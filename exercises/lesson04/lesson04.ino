/* Redd Plantene
 * @author: Nikhil André Luthra - Bouvet Norge
 * @web: reddplantene.labben.org / bouvet.no/reddplantene
 * @web: bouvet.no / nikhil.luthra.no
 */
#include <ESP8266WiFi.h>
#include <Phant.h>

// Enter SSID and password
// Fyll ut med SSID og passord
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

// Enter public key and private key
// Fyll ut publickey og privatekey
const char PhantHost[] = "phant.labben.org"; //Get your public and private key by visiting http://phant.labben.org:8090
const char publicKey[] = "";
const char privateKey[] = "";

WiFiClient client;
const int httpPort = 8090;

#define MOISTURE_PIN A0
#define MOISTURE_POWER_PIN D7

int sensorValue = 0;

void setup() {
  Serial.begin(115200);
  pinMode(MOISTURE_PIN, INPUT);
  
  pinMode(MOISTURE_POWER_PIN, OUTPUT);
  digitalWrite(MOISTURE_POWER_PIN, LOW);

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
  digitalWrite(MOISTURE_POWER_PIN, HIGH);
  delay(300);
  
  sensorValue = analogRead(MOISTURE_PIN);
  
  delay(100);
  digitalWrite(MOISTURE_POWER_PIN, LOW);
  
  // Exercise: Declare a Phant object
  // Oppgave: Deklarer et Phantobjekt
  

  // Exercise: Add the sensor value to the Phant Object. Remember to use the same key as when you created the Phant stream
  // Oppgave: Legg til sensorverdien i Phantobjektet. Husk å bruke samme nøkkel som når du opprettet phant-stream

  
  // Exercise: Connect to the Phant server. Print a error message if the connection fails
  // Oppgave: koble til Phantserveren. Skriv ut feilmelding om tilkobling mislyktes
  
  
  // Exercise: Post data to the Phant server
  // Oppgave: Post data til Phant serveren




  delay(15000);
}
