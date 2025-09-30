#include <Wire.h>
#include "Adafruit_SHT31.h"
#include <WiFi.h>
#include <WebServer.h>

// WiFi credentials
const char* ssid = "iPhone";
const char* password = "987654321";

// I2C pins
const int I2C_SDA = 33;
const int I2C_SCL = 35;

Adafruit_SHT31 sht31 = Adafruit_SHT31();

// Create a web server on port 80
WebServer server(80);

void handleRoot() {
  float t = sht31.readTemperature();
  float h = sht31.readHumidity();

  String html = "<!DOCTYPE html><html><head><title>ESP32 SHT3x</title></head><body>";
  html += "<h1>ESP32 SHT3x Sensor</h1>";

  if (!isnan(t) && !isnan(h)) {
    html += "<p>Temperature: " + String(t, 2) + " &deg;C</p>";
    html += "<p>Humidity: " + String(h, 2) + " %</p>";
  } else {
    html += "<p>Sensor read failed!</p>";
  }

  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  delay(200);

  Wire.begin(I2C_SDA, I2C_SCL);

  if (!sht31.begin(0x44)) { 
    Serial.println("Couldn't find SHT31 sensor! Check wiring or use 0x45 address.");
  }

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  // Set up web server
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Web server started!");
}

void loop() {
  server.handleClient();  // Handle incoming HTTP requests

  // Optional: print readings to Serial
  float t = sht31.readTemperature();
  float h = sht31.readHumidity();
  if (!isnan(t)) Serial.print("Temp: " + String(t,2) + " °C  ");
  if (!isnan(h)) Serial.println("Humidity: " + String(h,2) + " %");
  delay(2000);
}
