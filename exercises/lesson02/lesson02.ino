/* Redd Plantene
 * @author: Nikhil André Luthra - Bouvet Norge
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
  
  // Oppgave: Sett MOISTURE_POWER_PIN til HIGH for å sende strøm til sensoren.
  

  delay(300);

  
}

void loop() {
  // Oppgave: Les av fuktighet
  

  Serial.print("Moisture: ");

  // Oppgave: Skriv ut fuktighet til serieport

  // Oppgave: Vent 2 sekunder
}
