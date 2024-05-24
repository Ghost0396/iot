#include <WiFi.h>
#include <PubSubClient.h>
#include <ESPAsyncWebServer.h>
#include <DHT.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <string>

#define DHTPIN 14
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int lamp1Pin = 2;
const int lamp2Pin = 15;
const int lamp3Pin = 4;

const int buttonPin = 0;
bool buttonState = LOW;
bool lastButtonState = LOW;

const char* ssid = "";
const char* password = "";

const char* mqtt_server = "broker.hivemq.com"; 
const int mqtt_port = 1883;
const char* mqtt_topic = "esp32/iot-5232024-temperature";
WiFiClient espClient;
PubSubClient client(espClient);

const char* apiKey = "";
const char* city = "Juarez";
String cityTemperature = "N/A";
String cityWeatherDescription = "N/A";
String cityHumidity = "N/A";

const char* validUsername = "admin";
const char* validPassword = "password";

const char* secretToken = "secret12345";

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");


const char* temp_page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <title>ESP32 Control</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" href="https://github.com/Ghost0396/iot/raw/main/web_development/examples/weather/assets/img/iot.png">
    <link href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script>
    <style>
      body {
        background-image: url('https://github.com/Ghost0396/iot/raw/main/web_development/examples/weather/assets/img/2.jpg');
        background-size: cover;
        background-repeat: no-repeat;
        background-attachment: fixed;
        margin: 0;
        display: flex;
        flex-direction: column;
        height: 100vh;
      }
      .navbar-brand img {
        border-radius: 50%;
        background-color: #282A36;
        padding: 5px;
        margin-right: 10px;
        display: inline-block;
        vertical-align: top;
      }
      .navbar {
        background-color: #282A36;
        text-align: center;
      }
      .navbar-brand {
        display: inline-flex;
        align-items: center;
        text-decoration: none; 
        color: inherit; 
      }
      .nav-item {
        margin: 0 10px;
      }
      .nav-link {
        text-decoration: none;
        color: inherit;
        display: flex;
        align-items: center;
      }
      .material-icons {
        margin-right: 5px;
      }
      .main-content {
        flex: 1;
        display: flex;
        justify-content: center;
        align-items: center;
        padding: 20px;
      }
      .container {
        max-width: 600px;
        width: 100%;
      }
      .card {
        background-color: #282A36;
        border: none;
      }
      .card-body {
        color: #fff;
      }
      .btn-custom {
        background-color: #fff;
        color: #282A36;
        border: 2px solid #282A36;
        display: flex;
        align-items: center;
        justify-content: center;
      }
      .btn-custom:hover {
        background-color: #282A36;
        color: #fff;
      }
      .btn-custom .material-icons {
        margin-right: 5px;
      }
      .button-container {
        display: flex;
        justify-content: space-between;
      }
      @media (max-width: 576px) {
        .card {
          margin: 20px 0;
        }
        .card-body {
          padding: 10px;
        }
        .btn {
          font-size: 14px;
        }
        .button-container {
          flex-direction: column;
        }
        .button-container a {
          margin-bottom: 10px;
        }
      }
    </style>
    <script>
        var ws = new WebSocket('ws://' + window.location.hostname + '/ws');
        ws.onopen = function() {
          console.log("WebSocket connection established");
        };
        ws.onmessage = function(event) {
          console.log("WebSocket message received:", event.data);
          try {
            var data = JSON.parse(event.data);
            document.getElementById('room-temperature').innerText = data.roomTemperature + ' °C';
            document.getElementById('city-temperature').innerText = data.cityTemperature + ' °C';
            document.getElementById('city-weather').innerText = data.cityWeather;
            document.getElementById('city-humidity').innerText = data.cityHumidity + ' %';
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
    <nav class="navbar navbar-expand-lg navbar-dark">
      <a class="navbar-brand" href="#">
        <img src="https://github.com/Ghost0396/iot/raw/main/web_development/examples/weather/assets/img/iot.png" width="50" height="50" class="d-inline-block align-top" alt="">
        Project
      </a>
      <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>
      <div class="collapse navbar-collapse" id="navbarNav">
        <ul class="navbar-nav">
          <li class="nav-item">
            <a class="nav-link" href="/"><i class="material-icons">home</i> Home</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="/logout"><i class="material-icons">exit_to_app</i> Log Out</a>
          </li>
        </ul>
      </div>
    </nav>
    
    <div class="main-content">
        <div class="container">
            <div class="row justify-content-center">
                <div class="col-md-6">
                    <div class="card mt-5">
                        <div class="card-body text-center">
                            <h3 class="card-title"><i class="material-icons">thermostat</i> Temperature</h3>
                            <div class="card mt-3">
                                <div class="card-body">
                                    <h5 class="card-title">Room Temperature</h5>
                                    <p id="room-temperature" class="card-text">Loading...</p>
                                </div>
                            </div>
                            <div class="card mt-3">
                                <div class="card-body">
                                    <h5 class="card-title">City Temperature (%CITY%)</h5>
                                    <p id="city-temperature" class="card-text">Loading...</p>
                                    <p id="city-weather" class="card-text">Loading...</p>
                                    <p id="city-humidity" class="card-text">Loading...</p>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
)rawliteral";

const char* controller_page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <title>ESP32 Control</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" href="https://github.com/Ghost0396/iot/raw/main/web_development/examples/weather/assets/img/iot.png">
    <link href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script>
    <style>
      body {
        background-image: url('https://github.com/Ghost0396/iot/raw/main/web_development/examples/weather/assets/img/2.jpg');
        background-size: cover;
        background-repeat: no-repeat;
        background-attachment: fixed;
        margin: 0;
        display: flex;
        flex-direction: column;
        height: 100vh;
      }
      .navbar-brand img {
        border-radius: 50%;
        background-color: #282A36;
        padding: 5px;
        margin-right: 10px;
        display: inline-block;
        vertical-align: top;
      }
      .navbar {
        background-color: #282A36;
        text-align: center;
      }
      .navbar-brand {
        display: inline-flex;
        align-items: center;
        text-decoration: none;
        color: inherit;
      }
      .nav-item {
        margin: 0 10px;
      }
      .nav-link {
        text-decoration: none;
        color: inherit;
        display: flex;
        align-items: center;
      }
      .material-icons {
        margin-right: 5px;
      }
      .main-content {
        flex: 1;
        display: flex;
        justify-content: center;
        align-items: center;
        padding: 20px;
      }
      .container {
        max-width: 600px;
        width: 100%;
      }
      .card {
        background-color: #282A36;
        border: none;
      }
      .card-body {
        color: #fff;
      }
      .btn-custom {
        background-color: #fff;
        color: #282A36;
        border: 2px solid #282A36;
        display: flex;
        align-items: center;
        justify-content: center;
      }
      .btn-custom:hover {
        background-color: #282A36;
        color: #fff;
      }
      .btn-custom .material-icons {
        margin-right: 5px;
      }
      .button-container {
        display: flex;
        justify-content: space-between;
      }
      @media (max-width: 576px) {
        .card {
          margin: 20px 0; 
        }
        .card-body {
          padding: 10px; 
        }
        .btn {
          font-size: 14px; 
        }
        .button-container {
          flex-direction: column;
        }
        .button-container a {
          margin-bottom: 10px; 
        }
      }
    </style>
    <script>
        var ws = new WebSocket('ws://' + window.location.hostname + '/ws');
        ws.onopen = function() {
          console.log("WebSocket connection established");
        };
        ws.onmessage = function(event) {
          console.log("WebSocket message received:", event.data); 
          try {
            var data = JSON.parse(event.data);
            document.getElementById('lamp1').innerText = data.lamp1Status ? 'Turn Off' : 'Turn On';
            document.getElementById('lamp2').innerText = data.lamp2Status ? 'Turn Off' : 'Turn On';
            document.getElementById('lamp3').innerText = data.lamp3Status ? 'Turn Off' : 'Turn On';
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
    <nav class="navbar navbar-expand-lg navbar-dark">
      <a class="navbar-brand" href="#">
        <img src="https://github.com/Ghost0396/iot/raw/main/web_development/examples/weather/assets/img/iot.png" width="50" height="50" class="d-inline-block align-top" alt="">
        Project
      </a>
      <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>
      <div class="collapse navbar-collapse" id="navbarNav">
        <ul class="navbar-nav">
          <li class="nav-item">
            <a class="nav-link" href="/"><i class="material-icons">home</i> Home</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="/logout"><i class="material-icons">exit_to_app</i> Log Out</a>
          </li>
        </ul>
      </div>
    </nav>
    
    <div class="main-content">
        <div class="container">
            <div class="row justify-content-center">
                <div class="col-md-6">
                    <div class="card mt-5">
                        <div class="card-body text-center">
                            <h3 class="card-title"><i class="material-icons">power</i> Controllers</h3>
                            <p>Lamp 1: <a href="/toggle?lamp=1" id="lamp1" class="btn btn-secondary"></a></p>
                            <p>Lamp 2: <a href="/toggle?lamp=2" id="lamp2" class="btn btn-secondary"></a></p>
                            <p>Lamp 3: <a href="/toggle?lamp=3" id="lamp3" class="btn btn-secondary"></a></p>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
)rawliteral";

const char* login_page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <title>ESP32 Control</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" href="https://github.com/Ghost0396/iot/raw/main/web_development/examples/weather/assets/img/iot.png">
    <link href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script>
    <style>
      body {
        background-image: url('https://github.com/Ghost0396/iot/raw/main/web_development/examples/weather/assets/img/2.jpg');
        background-size: cover;
        background-repeat: no-repeat;
        background-attachment: fixed;
        margin: 0;
        display: flex;
        flex-direction: column;
        height: 100vh;
      }
      .navbar-brand img {
        border-radius: 50%;
        background-color: #282A36;
        padding: 5px;
        margin-right: 10px;
        display: inline-block;
        vertical-align: top;
      }
      .navbar {
        background-color: #282A36;
        text-align: center;
      }
      .navbar-brand {
        display: inline-flex;
        align-items: center;
        text-decoration: none;
        color: inherit;
      }
      .nav-item {
        margin: 0 10px;
      }
      .nav-link {
        text-decoration: none;
        color: inherit;
        display: flex;
        align-items: center;
      }
      .material-icons {
        margin-right: 5px;
      }
      .login {
        display: flex;
        justify-content: center;
        align-items: center;
        height: 100%;
      }
      .login form {
        background: #1e2833;
        max-width: 320px;
        width: 100%;
        padding: 50px;
        border-radius: 4px;
        box-shadow: 3px 3px 4px rgba(0,0,0,0.2);
        color: aliceblue;
      }
      .login form .login-ico, #ico-log {
        font-size: 100px;
        color: #2980ef;
        padding: 15px 0 20px;
        text-align: center;
      }
      .login form .form-control {
        background: none;
        color: inherit;
        border: none;
        border-bottom: 1px solid #434a52;
        box-shadow: none;
        border-radius: 0;
      }
      .login form .btn {
        background: #214a80;
        padding: 11px;
        margin-top: 26px;
        color: inherit;
      }
      .login form .forgot {
        display: block;
        font-size: 12px;
        text-align: center;
        color: #6f7a85;
        text-decoration: none;
      }
    </style>
</head>
<body>
    <nav class="navbar navbar-expand-lg navbar-dark">
      <a class="navbar-brand" href="#">
        <img src="https://github.com/Ghost0396/iot/raw/main/web_development/examples/weather/assets/img/iot.png" width="50" height="50" class="d-inline-block align-top" alt="">
        Project
      </a>
      <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>
      <div class="collapse navbar-collapse" id="navbarNav">
        <ul class="navbar-nav">
          <li class="nav-item">
            <a class="nav-link" href="/"><i class="material-icons">home</i> Home</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="/logout"><i class="material-icons">exit_to_app</i> Log Out</a>
          </li>
        </ul>
      </div>
    </nav>
    
    <div class="login">
      <form action="/login" method="post">
          <div class="login-ico">                
            <a><i class="material-icons" id="ico-log">login</i></a>
          </div>
          <div class="form-group">
              <input class="form-control" type="text" placeholder="Username" name="username" required>
          </div>
          <div class="form-group">
              <input class="form-control" type="password" placeholder="Password" name="password" required>
          </div>
          <div class="form-group">
              <button type="submit" class="btn btn-block">Log in</button>
          </div>
          <a href="#" class="forgot">Forgot your username or password?</a>
      </form>
  </div>
</body>
</html>

)rawliteral";

const char* index_page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <title>ESP32 Control</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" href="https://github.com/Ghost0396/iot/raw/main/web_development/examples/weather/assets/img/iot.png">
    <link href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script>
    <style>
      body {
        background-image: url('https://github.com/Ghost0396/iot/raw/main/web_development/examples/weather/assets/img/2.jpg');
        background-size: cover;
        background-repeat: no-repeat;
        background-attachment: fixed;
        margin: 0;
        display: flex;
        flex-direction: column;
        height: 100vh;
      }
      .navbar-brand img {
        border-radius: 50%;
        background-color: #282A36;
        padding: 5px;
        margin-right: 10px;
        display: inline-block;
        vertical-align: top; 
      }
      .navbar {
        background-color: #282A36;
        text-align: center;
      }
      .navbar-brand {
        display: inline-flex;
        align-items: center;
        text-decoration: none; 
        color: inherit; 
      }
      .nav-item {
        margin: 0 10px;
      }
      .nav-link {
        text-decoration: none;
        color: inherit;
        display: flex;
        align-items: center;
      }
      .material-icons {
        margin-right: 5px; 
      }
      .main-content {
        flex: 1;
        display: flex;
        justify-content: center;
        align-items: center;
        padding: 20px;
      }
      .container {
        max-width: 600px;
        width: 100%;
      }
      .card {
        background-color: #282A36;
        border: none; 
      }
      .card-body {
        color: #fff; 
      }
      .btn-custom {
        background-color: #fff;
        color: #282A36;
        border: 2px solid #282A36;
        display: flex;
        align-items: center;
        justify-content: center;
      }
      .btn-custom:hover {
        background-color: #282A36;
        color: #fff;
      }
      .btn-custom .material-icons {
        margin-right: 5px;
      }
      .button-container {
        display: flex;
        justify-content: space-between;
      }
      @media (max-width: 576px) {
        .card {
          margin: 20px 0; 
        }
        .card-body {
          padding: 10px; 
        }
        .btn {
          font-size: 14px; 
        }
        .button-container {
          flex-direction: column;
        }
        .button-container a {
          margin-bottom: 10px;
        }
      }
    </style>
</head>
<body>
    <nav class="navbar navbar-expand-lg navbar-dark">
      <a class="navbar-brand" href="#">
        <img src="https://github.com/Ghost0396/iot/raw/main/web_development/examples/weather/assets/img/iot.png" width="50" height="50" class="d-inline-block align-top" alt="">
        Project
      </a>
      <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>
      <div class="collapse navbar-collapse" id="navbarNav">
        <ul class="navbar-nav">
          <li class="nav-item">
            <a class="nav-link" href="/"><i class="material-icons">home</i> Home</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="/logout"><i class="material-icons">exit_to_app</i> Log Out</a>
          </li>
        </ul>
      </div>
    </nav>
    
    <div class="main-content">
        <div class="container">
            <div class="row justify-content-center">
                <div class="col-md-12">
                    <div class="card mt-5">
                        <div class="card-body text-center">
                            <h3 class="card-title"><i class="material-icons">dashboard</i> ESP32 Control</h3>
                            <div class="button-container">
                                <a href="/controllers" class="btn btn-custom"><i class="material-icons">power</i> Controllers</a>
                                <a href="/temperature" class="btn btn-custom"><i class="material-icons">thermostat</i> Temperature</a>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</body>
</html>
)rawliteral";

void callback(char* topic, byte* payload, unsigned int length);
void updateDHTData();
void updateCityTemperature();
void notifyClients();
void notifyLampStatus();
bool isAuthenticatedRequest(AsyncWebServerRequest *request);
void onWebSocketEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
      client.publish("esp32/status", "connected");
      client.subscribe(mqtt_topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(lamp1Pin, OUTPUT);
  pinMode(lamp2Pin, OUTPUT);
  pinMode(lamp3Pin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(lamp1Pin, LOW);
  digitalWrite(lamp2Pin, LOW);
  digitalWrite(lamp3Pin, LOW);
    
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (!isAuthenticatedRequest(request)) {
      String page = String(login_page);
      request->send(200, "text/html", page);
    } else {
      String page = String(index_page);
      request->send(200, "text/html", page);
    }
  });

  server.on("/login", HTTP_POST, [](AsyncWebServerRequest *request) {
    if (request->hasParam("username", true) && request->hasParam("password", true)) {
      String username = request->getParam("username", true)->value();
      String password = request->getParam("password", true)->value();
      if (username == validUsername && password == validPassword) {
        AsyncWebServerResponse *response = request->beginResponse(301);
        response->addHeader("Location", "/");
        response->addHeader("Set-Cookie", "session=" + String(secretToken));
        request->send(response);
        return;
      }
    }
    request->send(200, "text/html", "<html><body>Login Failed. <a href='/'>Try again</a></body></html>");
  });

  server.on("/logout", HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncWebServerResponse *response = request->beginResponse(200, "text/html", "<html><body>Logged out. <a href='/'>Login again</a></body></html>");
    response->addHeader("Set-Cookie", "session=; Max-Age=0; path=/;");
    request->send(response);
  });

  server.on("/controllers", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (!isAuthenticatedRequest(request)) {
      request->redirect("/");
      return;
    }
    String page = String(controller_page);
    page.replace("%LAMP1%", digitalRead(lamp1Pin) == HIGH ? "Turn Off" : "Turn On");
    page.replace("%LAMP2%", digitalRead(lamp2Pin) == HIGH ? "Turn Off" : "Turn On");
    page.replace("%LAMP3%", digitalRead(lamp3Pin) == HIGH ? "Turn Off" : "Turn On");
    request->send(200, "text/html", page);
  });

  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (!isAuthenticatedRequest(request)) {
      request->redirect("/");
      return;
    }
    String page = String(temp_page);
    page.replace("%CITY%", city);
    request->send(200, "text/html", page);
  });

  server.on("/toggle", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (!isAuthenticatedRequest(request)) {
      request->redirect("/");
      return;
    }
    if (request->hasParam("lamp")) {
      int lamp = request->getParam("lamp")->value().toInt();
      if (lamp == 1) {
        digitalWrite(lamp1Pin, !digitalRead(lamp1Pin));
      } else if (lamp == 2) {
        digitalWrite(lamp2Pin, !digitalRead(lamp2Pin));
      } else if (lamp == 3) {
        digitalWrite(lamp3Pin, !digitalRead(lamp3Pin));
      }
      notifyLampStatus();
    }
    request->redirect("/controllers");
  });

  ws.onEvent(onWebSocketEvent);
  server.addHandler(&ws);
  server.begin();
  updateDHTData();
  updateCityTemperature();
  notifyClients();
}

unsigned long previousMillis = 0;
const long interval = 5000;

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    updateDHTData();
    updateCityTemperature();
    notifyClients();
  }
  
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastButtonState == HIGH) {
    delay(50);
    digitalWrite(lamp1Pin, !digitalRead(lamp1Pin));
    notifyLampStatus();
  }
  lastButtonState = buttonState;
}

bool isAuthenticatedRequest(AsyncWebServerRequest *request) {
  if (request->hasHeader("Cookie")) {
    AsyncWebHeader* cookie = request->getHeader("Cookie");
    String cookieValue = cookie->value();
    if (cookieValue.indexOf("session=") != -1) {
      String token = cookieValue.substring(cookieValue.indexOf("session=") + 8);
      if (token.equals(secretToken)) {
        return true;
      }
    }
  }
  return false;
}

void updateDHTData() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (!isnan(temperature) && !isnan(humidity)) {
    // Publish the data to the MQTT topic
    String payload = "{\"temperature\": " + String(temperature) + ", \"humidity\": " + String(humidity) + "}";
    client.publish(mqtt_topic, payload.c_str());

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
    Serial.println("Data published to MQTT");
  }
}

void updateCityTemperature() {
  HTTPClient http;
  String url = "http://api.openweathermap.org/data/2.5/weather?q=" + String(city) + "&appid=" + String(apiKey) + "&units=metric";
  http.begin(url);
  int httpResponseCode = http.GET();
  if (httpResponseCode == 200) {
    String payload = http.getString();
    DynamicJsonDocument doc(1024);
    deserializeJson(doc, payload);
    cityTemperature = String(doc["main"]["temp"].as<float>());
    cityWeatherDescription = String(doc["weather"][0]["description"].as<const char*>());
    cityHumidity = String(doc["main"]["humidity"].as<int>());

    Serial.print("City Temperature: ");
    Serial.print(cityTemperature);
    Serial.print(" °C, Weather: ");
    Serial.print(cityWeatherDescription);
    Serial.print(", Humidity: ");
    Serial.print(cityHumidity);
    Serial.println(" %");
  } else {
    Serial.print("Error on HTTP request: ");
    Serial.println(httpResponseCode);
  }
  http.end();
}

void notifyClients() {
  DynamicJsonDocument doc(1024);
  doc["roomTemperature"] = dht.readTemperature();
  doc["cityTemperature"] = cityTemperature;
  doc["cityWeather"] = cityWeatherDescription;
  doc["cityHumidity"] = cityHumidity;
  doc["lamp1Status"] = digitalRead(lamp1Pin) == HIGH;
  doc["lamp2Status"] = digitalRead(lamp2Pin) == HIGH;
  doc["lamp3Status"] = digitalRead(lamp3Pin) == HIGH;

  String json;
  serializeJson(doc, json);
  Serial.println("Sending to clients: " + json);
  ws.textAll(json);
}

void notifyLampStatus() {
  DynamicJsonDocument doc(1024);
  doc["lamp1Status"] = digitalRead(lamp1Pin) == HIGH;
  doc["lamp2Status"] = digitalRead(lamp2Pin) == HIGH;
  doc["lamp3Status"] = digitalRead(lamp3Pin) == HIGH;

  String json;
  serializeJson(doc, json);
  Serial.println("Sending lamp status to clients: " + json);
  ws.textAll(json);
}

void callback(char* topic, byte* payload, unsigned int length) {
  // Handle incoming messages if needed
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
