#include <Arduino.h>
/* Redd Plantene
 * @author: Nikhil André Luthra/Jesper Andersson - Bouvet Norge
 * @web: reddplantene.labben.org / bouvet.no/reddplantene
 * @web: bouvet.no / nikhil.luthra.no
 */

// Error her forsvinner når du laster opp eller bygger første gang. (Error here is expected until build&upload)
#include <WiFiManager.h>
#include <Phant.h> 

// Oppgave: Gi dingsen din et navn.
const char deviceName[] = "";

// Oppgave: Fyll ut phanthost, publickey og privatekey
// NB! i 'Fields' må du skrive 'moisture' for at den skal funke med webløsningen etterpå.
const char PhantHost[] = "phant.labben.org"; //Get your public and private key by visiting http://phant.labben.org:8090
const char publicKey[] = "";
const char privateKey[] = "";

#define MOISTURE_PIN A0
#define MOISTURE_POWER_PIN D7

int sensorValue = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(MOISTURE_PIN, INPUT);
  
  pinMode(MOISTURE_POWER_PIN, OUTPUT);
  digitalWrite(MOISTURE_POWER_PIN, LOW);

  WiFiManager wifiManager;
  
  if (wifiManager.autoConnect(deviceName)) {  // <--- NB! Husk å gi dingsen din et navn!
    Serial.println("Connected!");
  }
  else {
    Serial.println("Connection failed.");
    delay(5000);
    setup();
  }
}

void loop() {
  digitalWrite(MOISTURE_POWER_PIN, HIGH);
  digitalWrite(LED_BUILTIN, LOW);
  delay(300);
  
  sensorValue = analogRead(MOISTURE_PIN);
  
  delay(100);
  digitalWrite(MOISTURE_POWER_PIN, LOW);
  digitalWrite(LED_BUILTIN, HIGH);
  

  // Oppgave: Deklarer et Phantobjekt
  

  // Oppgave: legg til sensorverdien i Phantobjektet. Husk å bruke nøkkel 'moisture' som når du opprettet phant-stream
  

  // Oppgave: koble til Phantserveren. Skriv ut feilmelding om tilkobling mislyktes
  
  
  // Oppgave: Post data til Phant serveren


  delay(15000);
}
