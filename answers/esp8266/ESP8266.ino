#include <ESP8266WiFi.h>
#include <Phant.h>

// Set these to run example.
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

////////////////
// Phant Keys //
////////////////
const char PhantHost[] = "phant.labben.org";
const char PublicKey[] = "";
const char PrivateKey[] = "";

WiFiClient client;
const int httpPort = 80;

#define MOISTURE_PIN A0

int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(A0, INPUT);

  // connect to wifi.
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
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(MOISTURE_PIN);
  Serial.println(sensorValue);


  // Declare an object from the Phant library - phant
  Phant phant(PhantHost, PublicKey, PrivateKey);
  phant.add("moisture", sensorValue);

  // Now connect to data.sparkfun.com, and post our data:
  if (!client.connect(PhantHost, httpPort)) 
  {
    // If we fail to connect, return 0.
    Serial.println("Error connecting to Phant.");
  }
  // If we successfully connected, print our Phant post:
  client.print(phant.post());

  // DEBUG: Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.println(line); // Trying to avoid using serial
  }
  
  
  delay(15000);

  

}
