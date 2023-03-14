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

  // Oppgave: Start tilkobling til trådløst nettverk med ssid og password

  // Oppgave: Skriv ut "." hvert 0.5 sekund fram til vi er tilkoblet
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected!");
    Serial.print("IP address: ");

    // Oppgave: Skriv ut IP-adresse
    
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
