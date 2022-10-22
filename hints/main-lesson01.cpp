#include <Arduino.h>
/* Redd Plantene
 * @author: Nikhil André Luthra/Jesper Andersson - Bouvet Norge
 * @web: reddplantene.labben.org / bouvet.no/reddplantene
 * @web: bouvet.no / nikhil.luthra.no
 */

void setup() {
  // Initialiser serieport på 115200 bps
  Serial.begin(115200);

  // Sett LED_BUILTIN til OUTPUT
  pinMode(LED_BUILTIN, OUTPUT);

  // Skriv ut melding til serieport
  Serial.println("Hello serial port");
}

void loop() {
  // Skriv ut melding til serieport
  Serial.println("Hello loop");

  // Sett LED_BUILTIN til HIGH
  digitalWrite(LED_BUILTIN, HIGH);

  // Vent 2 sekunder
  delay(2000);

  // Sett LED_BUILTIN til HIGH
  digitalWrite(LED_BUILTIN, LOW);

  // Vent 2 sekunder
  delay(2000);
}
