#include <ESP8266WiFi.h>
#include <Phant.h>

// Fyll ut med SSID og passord
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

// Fyll ut phanthost, publickey og privatekey
const char PhantHost[] = "phant.labben.org";
const char PublicKey[] = "";
const char PrivateKey[] = "";

WiFiClient client;
const int httpPort = 80;

#define MOISTURE_PIN A0

int sensorValue = 0;

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  sensorValue = analogRead(MOISTURE_PIN);

  // Oppgave: Deklarer et Phantobjekt
  Phant phant(PhantHost, PublicKey, PrivateKey);

  // Oppgave: legg til sensorverdien i Phantobjektet. Husk å bruke samme nøkkel som når du opprettet phant-stream
  phant.add("moisture", sensorValue);

  // Oppgave: koble til Phantserveren. Skriv ut feilmelding om tilkobling mislyktes
  if (!client.connect(PhantHost, httpPort)) 
  {
    // If we fail to connect, return 0.
    Serial.println("Error connecting to Phant.");
  }

  // Oppgave: Post data til Phant serveren
  client.print(phant.post());

  delay(15000);
}
