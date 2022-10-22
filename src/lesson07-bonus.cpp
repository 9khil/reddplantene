#include <Arduino.h>
/* Redd Plantene
 * @author: Nikhil André Luthra/Jesper Andersson - Bouvet Norge
 * @web: reddplantene.labben.org / bouvet.no/reddplantene
 * @web: bouvet.no / nikhil.luthra.no
 */
#include <WiFiManager.h>
#include <ESP8266WiFi.h>


// Oppgave: Finn disse parametrerne i mailen fra blynk eller på https://blynk.cloud/dashboard
#define BLYNK_TEMPLATE_ID           ""
#define BLYNK_DEVICE_NAME           ""
#define BLYNK_AUTH_TOKEN            ""

#define BLYNK_PRINT Serial

// This one needs to be included after we have defined BLYNK_AUTH_TOKEN
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Oppgave: Gi dingsen din et navn.
const char deviceName[] = "";

BlynkTimer timer;

BLYNK_CONNECTED()
{
  // When you sucessfully connect to your app we change the banner.
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function is called every time the Virtual Pin 0 in the app changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  digitalWrite(LED_BUILTIN, !value);
  // Update state
  Blynk.virtualWrite(V1, value);
}

void myTimerEvent()
{
  // Please don't send more that 10 values per second.
  int uptime = millis() / 1000;
  Blynk.virtualWrite(V2, uptime);
}

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
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
