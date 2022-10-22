#include <Arduino.h>
/* Redd Plantene
 * @author: Nikhil André Luthra/Jesper Andersson - Bouvet Norge
 * @web: reddplantene.labben.org / bouvet.no/reddplantene
 * @web: bouvet.no / nikhil.luthra.no
 */
#define MOISTURE_PIN A0
#define MOISTURE_POWER_PIN D7

int sensorValue = 0;

void setup() {
  Serial.begin(115200);

  // Oppgave: Sett MOISTURE_PIN i inputmodus

  
  pinMode(MOISTURE_POWER_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Oppgave: Sett MOISTURE_POWER_PIN til HIGH for å sende strøm til sensoren.
  

  delay(300);
}

void loop() {
  // Oppgave: Les av fuktighet til variabeln 'sensorValue'
  
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  Serial.print("Moisture: ");

  // Oppgave: Skriv ut fuktighet til serieport

  // Oppgave: Vent 2 sekunder
  
}

