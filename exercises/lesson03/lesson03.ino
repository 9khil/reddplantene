/* Redd Plantene
 * @author: Nikhil André Luthra - Bouvet Norge
 * @web: reddplantene.labben.org / bouvet.no/reddplantene
 * @web: bouvet.no / nikhil.luthra.no
 */
#include <ESP8266WiFi.h>

// Enter SSID and password
// Fyll ut med SSID og passord
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

void setup() {
  Serial.begin(115200);

  Serial.println("");
  Serial.print("Connecting to: ");
  Serial.println(WIFI_SSID);

  // Exercise: start connection to WiFi with SSID and password
  // Oppgave: Start tilkobling til trådløst nettverk med ssid og password

  // Exercise: Print "." every 0.5 seconds until we are connected
  // Oppgave: Skriv ut "." hvert 0.5 sekund fram til vi er tilkoblet

  Serial.println("Connected!");
  Serial.println("IP address: ");

  // Exercise: Print IP adress
  // Oppgave: Skriv ut IP-adresse
}

void loop() {
}
