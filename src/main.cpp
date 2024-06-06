#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

// Wi-Fi credentials REPLACE HERE
const char* ssid = "";
const char* password = "";

// Web server URL
const char* serverName = "";


void setup() {
  Serial.begin(115200); // Initialize serial communication at 115200 baud
}

void loop() {
  Serial.println("Nothing to see yet :(");
}