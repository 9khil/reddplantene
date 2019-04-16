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
const char PhantHost[] = "phant.labben.org";
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

  // Declare a Phant object
  // Deklarer et Phantobjekt
  Phant phant(PhantHost, publicKey, privateKey);

  // Add the sensor value to the Phant Object. Remember to use the same key as when you created the Phant stream
  // Legg til sensorverdien i Phantobjektet. Husk å bruke samme nøkkel som når du opprettet phant-stream
  phant.add("moisture", sensorValue);

  // Connect to the Phant server. Print a error message if the connection fails
  // koble til Phantserveren. Skriv ut feilmelding om tilkobling mislyktes
  if (!client.connect(PhantHost, httpPort)) 
  {
    // If we fail to connect, return 0
    Serial.println("Error connecting to Phant.");
  }

  // Post data to the Phant server
  // Post data til Phant serveren
  client.print(phant.post());

  delay(15000);
}
