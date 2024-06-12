#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

// Wi-Fi credentials REPLACE HERE
const char* ssid = "iPhone von Jonathan (605)";
const char* password = "12345678";

// Web server URL
const char* serverName = "https://i-teaching-next.vercel.app/api/data";

// DHT sensor configuration
#define DHTPIN 4       // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22  // DHT 22 (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(115200); // Initialize serial communication at 115200 baud

  // Initialize the DHT sensor
  dht.begin();

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {

  // TODO: id deklarieren (String) 

  delay(2000); // Wait 5min (=300000ms) between measurements.

  //TODO: Werte des dht lesen und in 2 float-Variablen speichern 

  // Check if any reads failed and exit early (to try again).

  if (true) { // TODO: "true" entfernen und Bedingung eintragen
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print temperature and humidity
  Serial.print("Humidity: ");
  // TODO: variablennamen eintragen um die Werte in die Konsole zu drucken
  Serial.print("%  Temperature: ");
  // TODO: variablennamen eintragen um die Werte in die Konsole zu drucken
  Serial.println("°C ");

  // If WiFi is connected, send data
  if(WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Specify request destination
    http.begin(serverName);

    // Specify content-type header
    http.addHeader("Content-Type", "application/json");

    // Prepare JSON payload
    // TODO: Variablen mit den Daten eintragen wo die Platzhalter sind
    String httpRequestData = "{\"data\": {\"id\": \"" + String(0) + "\", \"temperature\": \"" + String(0) + "\", \"humidity\": \"" + String(0) + "\"}}";
    Serial.print("HTTP Request data: ");
    Serial.println(httpRequestData);

    // Send HTTP POST request
    // TODO: POST-Request senden und den Reponse Code als integer speichern.


    if (true) { // TODO richtige Bedingung eintragen (true entfernen)
      // TODO: Response der Request in Variable speichern
      // TODO: code ausdrucken
      // TODO: Request Response ausdrucken
    } else {
      // Error-Message ausdrucken
      // Code ausdrucken
    }

    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
}