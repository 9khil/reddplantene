#include <ESP8266WiFi.h>
#include <Phant.h>

// Fyll ut med SSID og passord
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

//1.  Fyll ut phanthost, publickey og privatekey. Du finner disse verdiene ved å registrere deg her: http://phant.labben.org:8090
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
  
  //2. Lim inn kode for å slå på sensoren:
  
  delay(300);

  //3. Lim inn kode for å lese data fra sensoren:
  

  delay(100);

  //4. Lim inn kode for å slå av sensoren:


  Phant phant(PhantHost, publicKey, privateKey);

  //5. Lim inn kode for å sende data til internett:

  if (!client.connect(PhantHost, httpPort))
  {
    // If we fail to connect, return 0.
    Serial.println("Error connecting to Phant.");
  }

  client.print(phant.post());



  delay(15000);
}
