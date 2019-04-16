/* Redd Plantene
 * @author: Nikhil André Luthra - Bouvet Norge
 * @web: reddplantene.labben.org / bouvet.no/reddplantene
 * @web: bouvet.no / nikhil.luthra.no
 */
#define MOISTURE_PIN A0
#define MOISTURE_POWER_PIN D7

// Varible to store the value read from the sensor
// Variabel for å lagre verdien lest fra sensor
int sensorValue = 0; 

void setup() {
  Serial.begin(115200);

  // Excercise: Set MOISTURE_PIN in input mode
  // Oppgave: Sett MOISTURE_PIN i inputmodus

  
  pinMode(MOISTURE_POWER_PIN, OUTPUT);

  // Exercise: Set MOISTURE_POWER_PIN to LOW
  // Oppgave: Sett MOISTURE_POWER_PIN til LOW  


  delay(300);
  
}

void loop() {
  // Exercise: Set MOISTURE_POWER_PIN to HIGH to supply the sensor with power
  // Oppgave: Sett MOISTURE_POWER_PIN til HIGH for å sende strøm til sensoren


  // Exercise: After the moisture sensor has been turned on, wait for 300 ms
  // Oppgave: Etter du har slått på sensoren venter du 300 ms før du leser av verdien

  
  // Exercise: Read moisture level
  // Oppgave: Les av fuktighet
  

  // Exercise: Turn the sensor off
  // Oppgave: Slå av sensoren

  Serial.print("Moisture: ");

  // Exercise: Print moisture level to serial port
  // Oppgave: Skriv ut fuktighet til serieport

  // Exercise: Wait for 2 seconds
  // Oppgave: Vent 2 sekunder
}
