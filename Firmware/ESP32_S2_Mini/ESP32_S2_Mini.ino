#include <WiFi.h>  // Use <ESP8266WiFi.h> if it's ESP8266

const char* ssid = "IoT";
const char* password = "InternetOfThings";

void setup() {
  Serial.begin(115200);  // Start serial communication
  delay(1000);

  Serial.println();
  Serial.println("Connecting to WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Your main code here
}
