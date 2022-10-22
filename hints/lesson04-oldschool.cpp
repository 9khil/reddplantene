#include <Arduino.h>
/* Redd Plantene
 * @author: Nikhil André Luthra/Jesper Andersson - Bouvet Norge
 * @web: reddplantene.labben.org / bouvet.no/reddplantene
 * @web: bouvet.no / nikhil.luthra.no
 */
#include <ESP8266WiFi.h>

// Fyll ut med SSID og passord
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

  Serial.println("");
  Serial.print("Connecting to: ");
  Serial.println(WIFI_SSID);

  // Start tilkobling til trådløst nettverk med ssid og password
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  // Skriv ut "." hvert 0.5 sekund fram til vi er tilkoblet
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected!");
    Serial.print("IP address: ");

    // Skriv ut IP-adresse
    Serial.println(WiFi.localIP());

  }
  else {
    Serial.println("Connection failed.");
    delay(5000);
    setup();
  }
}

void loop() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  delay(300);
}
