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

  // Start connection to WiFi with SSID and password
  // Start tilkobling til trådløst nettverk med ssid og password
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  // Print "." every 0.5 seconds until we are connected
  // Skriv ut "." hvert 0.5 sekund fram til vi er tilkoblet
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected!");
  Serial.println("IP address: ");

  // Print IP adress
  // Skriv ut IP-adresse
  Serial.println(WiFi.localIP());
}

void loop() {
}
