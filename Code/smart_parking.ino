#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";
ESP8266WebServer server(80);

int sensors[3] = {D5, D6, D7};
int leds[3]    = {D1, D2, D0};
bool occupied[3];

void handleRoot() {
  String page = "<h2>Parking Status</h2>";
  for (int i = 0; i < 3; i++) {
    page += "Slot " + String(i + 1) + ": " + (occupied[i] ? "OCCUPIED" : "FREE") + "<br>";
  }
  server.send(200, "text/html", page);
}

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 3; i++) {
    pinMode(sensors[i], INPUT);
    pinMode(leds[i], OUTPUT);
  }
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  for (int i = 0; i < 3; i++) {
    occupied[i] = (digitalRead(sensors[i]) == LOW);
    digitalWrite(leds[i], occupied[i]);
  }
  server.handleClient();
}