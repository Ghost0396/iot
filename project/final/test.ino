#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <string>
#include <ArduinoJson.h>

const char* ssid = "ITCJ-WIFI";
const char* password = "";

const int lamp1Pin = 2;
const int buttonPin = 0;

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void onWebSocketEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);

const char* index_page = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Hello world</title>
    <script>
        var ws = new WebSocket('ws://' + window.location.hostname + '/ws');
        ws.onopen = function() {
          console.log("WebSocket connection established");
        };
        ws.onmessage = function(event) {
          console.log("WebSocket message received:", event.data);
          try {
            var data = JSON.parse(event.data);
            document.getElementById('lamp1').innerText = data.lamp1Status ? 'ON' : 'OFF';
            console.log(data)
          } catch (e) {
            console.error("Error parsing JSON:", e);
          }
        };
        ws.onclose = function() {
          console.log("WebSocket connection closed");
        };
        ws.onerror = function(error) {
          console.log("WebSocket error:", error);
        };
      </script>
</head>
<body>
    <h1> Status</h1>
    <h3 id="lamp1"></h3>
    <h3 id="messages"></h3>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);
  pinMode(lamp1Pin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(lamp1Pin, LOW);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String page = String(index_page);
    request->send(200, "text/html", page);
  });
  
  ws.onEvent(onWebSocketEvent);
  server.addHandler(&ws);  // Add this line to register the WebSocket with the server
  server.begin();
}

void loop() {
  bool buttonPressed = digitalRead(buttonPin) == LOW;
  if (buttonPressed) {
    digitalWrite(lamp1Pin, !digitalRead(lamp1Pin));
    notifyLampStatus();
    delay(300);
  }
}

void notifyLampStatus() {
  DynamicJsonDocument doc(1024);
  doc["lamp1Status"] = digitalRead(lamp1Pin) == HIGH;
  
  String json;
  serializeJson(doc, json);
  Serial.println("Sending lamp status to clients: " + json);
  ws.textAll(json);
}


void onWebSocketEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  if (type == WS_EVT_CONNECT) {
    Serial.printf("WebSocket client connected: %u\n", client->id());
    notifyLampStatus();
  } else if (type == WS_EVT_DISCONNECT) {
    Serial.printf("WebSocket client disconnected: %u\n", client->id());
  } else if (type == WS_EVT_DATA) {
    Serial.printf("WebSocket data received: %s\n", data);
  }
}