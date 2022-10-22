#include <Arduino.h>
/* Redd Plantene
 * @author: Nikhil André Luthra/Jesper Andersson - Bouvet Norge
 * @web: reddplantene.labben.org / bouvet.no/reddplantene
 * @web: bouvet.no / nikhil.luthra.no
 */
#include <WiFiManager.h>
#include <ESP8266WiFi.h>

// Finn disse parametrerne i mailen fra blynk eller på https://blynk.cloud/dashboard
#define BLYNK_TEMPLATE_ID           ""
#define BLYNK_DEVICE_NAME           ""
#define BLYNK_AUTH_TOKEN            ""

#define MOISTURE_PIN A0
#define MOISTURE_POWER_PIN D7
#define BLYNK_PRINT Serial

// This one needs to be included after we have defined BLYNK_AUTH_TOKEN
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Gi dingsen din et navn.
const char deviceName[] = "Dingsebumsen";
int sensorValue = 0;

BlynkTimer timer;

void myTimerEvent()
{
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

  // Slå på sensoren, les til sensorvalue og slå den av igjen.
  digitalWrite(MOISTURE_POWER_PIN, HIGH);
  delay(300);
  sensorValue = analogRead(MOISTURE_PIN);
  delay(100);
  digitalWrite(MOISTURE_POWER_PIN, LOW);

  // Skriv sensorValue til virtuell pin V4
  Blynk.virtualWrite(V4, sensorValue);
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
  
  if (!wifiManager.autoConnect(deviceName)) { // <--- NB! Husk å gi dingsen din et navn!
    Serial.println("Connection failed.");
    delay(5000);
    setup();
  }
  else {
    Serial.println("Connected!");
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
