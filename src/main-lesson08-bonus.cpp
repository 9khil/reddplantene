#include <Arduino.h>
/* Redd Plantene
 * @author: Nikhil André Luthra/Jesper Andersson - Bouvet Norge
 * @web: reddplantene.labben.org / bouvet.no/reddplantene
 * @web: bouvet.no / nikhil.luthra.no
 */
#include <WiFiManager.h>
#include <ESP8266WiFi.h>


// Oppgave: Finn disse parametrerne i mailen fra blynk eller på https://blynk.cloud/dashboard
#define BLYNK_TEMPLATE_ID           "TMPLhjDuaTdH"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "dXdKMpwELmHzGxj-w8rOEnH78lMnVTjy"

#define MOISTURE_PIN A0
#define MOISTURE_POWER_PIN D7
#define BLYNK_PRINT Serial

// This one needs to be included after we have defined BLYNK_AUTH_TOKEN
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Oppgave: Gi dingsen din et navn.
const char deviceName[] = "";
int sensorValue = 0;

BlynkTimer timer;

void myTimerEvent()
{
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

  // Oppgave: 
  // Lag en ny widget i appen, for eksempel en "gauge"
  // koble den mot en ny datastream som benytter seg av virtual pin V4
  // sett maksverdien på datastrømmen til 500

  // Oppgave: Kopier inn koden som slår på sensoren, leser til sensorvalue og slår den av igjen.


  // Oppgave: skriv sensorValue til virtuell pin V4


  // Please don't send more that 10 values per second.
  int uptime = millis() / 1000;
  Blynk.virtualWrite(V2, uptime);
}

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
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

  Blynk.begin(auth, WiFi.SSID().c_str(), WiFi.psk().c_str());

  // A function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
}
