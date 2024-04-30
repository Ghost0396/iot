#include "WiFi.h"

const char* ssid = "ITCJ-WIFI";
const char* password = "";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {

}
