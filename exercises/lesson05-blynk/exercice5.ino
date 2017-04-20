
// HUSK Å LESE README.TXT - Dette er en bonusoppgave hvis du har tid!

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Autentiseringstoken mottatt pr epost etter opprettelse av Blynk prosjekt
char auth[] = "SETT-INN-DIN-AUTH-KODE";

// Fyll ut med SSID og passord
#define WIFI_SSID "FYLL-INN"
#define WIFI_PASSWORD "FYLL-INN"

void setup()
{
  Serial.begin(9600);

  // Start tilkobling til trådløst nettverk med ssid og password
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  // Skriv ut "." hvert 0.5 sekund fram til vi er tilkoblet
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Blynk.config(auth);
  Blynk.connect();
}

void loop()
{
  Blynk.run();
}

