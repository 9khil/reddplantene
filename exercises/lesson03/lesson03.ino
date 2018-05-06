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

   pinMode(MOISTURE_PIN, INPUT);

   pinMode(MOISTURE_POWER_PIN, OUTPUT);
  
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
  delay(2000);
}
