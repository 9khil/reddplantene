/* Redd Plantene
 * @author: Nikhil André Luthra - Bouvet Norge
 * @web: reddplantene.labben.org / bouvet.no/reddplantene
 * @web: bouvet.no / nikhil.luthra.no
 */
#include <ESP8266WiFi.h>

// Fyll ut med SSID og passord
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

void setup() {
  Serial.begin(115200);

  Serial.println("");
  Serial.print("Connecting to: ");
  Serial.println(WIFI_SSID);

  // Oppgave: Start tilkobling til trådløst nettverk med ssid og password

  // Oppgave: Skriv ut "." hvert 0.5 sekund fram til vi er tilkoblet

  Serial.println("Connected!");
  Serial.println("IP address: ");

  // Oppgave: Skriv ut IP-adresse
}

void loop() {
}
