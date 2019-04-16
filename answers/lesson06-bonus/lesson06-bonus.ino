/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#define MOISTURE_PIN A0
#define MOISTURE_POWER_PIN D7

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";

BlynkTimer timer;
int sensorValue = 0;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  digitalWrite(MOISTURE_POWER_PIN, HIGH);
  delay(300);
  
  sensorValue = analogRead(MOISTURE_PIN);
  
  delay(100);
  digitalWrite(MOISTURE_POWER_PIN, LOW);
  
  Blynk.virtualWrite(V5, sensorValue);
}


void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(MOISTURE_PIN, INPUT);
  pinMode(MOISTURE_POWER_PIN, OUTPUT);
  
  digitalWrite(MOISTURE_POWER_PIN, LOW);
  
  Blynk.begin(auth, ssid, pass);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer


}

