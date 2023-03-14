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

  // Sett MOISTURE_PIN i inputmodus
  pinMode(MOISTURE_PIN, INPUT);
  pinMode(MOISTURE_POWER_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  //Oppgave: Sett MOISTURE_POWER_PIN til LOW ved oppstart.
  

  delay(300);

  
}

void loop() {

  //Oppgave: Slå på sensoren

  //Oppgave: Etter du har slått på sensoren venter du 300 ms før du leser av verdien.
  
  sensorValue = analogRead(MOISTURE_PIN);
  
  //Oppgave: slå av sensoren igjen
  
  

  Serial.print("Moisture: ");
  Serial.println(sensorValue);
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  delay(2000);
}

