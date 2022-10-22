#include <Arduino.h>
/* Redd Plantene
 * @author: Nikhil André Luthra/Jesper Andersson - Bouvet Norge
 * @web: reddplantene.labben.org / bouvet.no/reddplantene
 * @web: bouvet.no / nikhil.luthra.no
 */
// Error her forsvinner når du laster opp eller bygger første gang. (Error here is expected until build&upload)
#include <WiFiManager.h>

// Oppgave: Gi dingsen din et navn.
const char deviceName[] = "Dingsebumsen";

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

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
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  delay(300);
}
