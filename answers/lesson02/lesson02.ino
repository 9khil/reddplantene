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

  // Set MOISTURE_PIN in input mode
  // Sett MOISTURE_PIN i inputmodus
  pinMode(MOISTURE_PIN, INPUT);

  pinMode(MOISTURE_POWER_PIN, OUTPUT);

  // Set the MOISTURE_POWER_PIN to LOW
  // Sett MOISTURE_POWER_PIN til LOW
  digitalWrite(MOISTURE_POWER_PIN, LOW);
  
  delay(300);
}

void loop() {
  // set MOISTURE_POWER_PIN to HIGH to supply the sensor with power
  // Sett MOISTURE_POWER_PIN til HIGH for å sende strøm til sensoren
  digitalWrite(MOISTURE_POWER_PIN, HIGH);

  // After the moisture sensor has been turned on, wait for 300 ms
  // Etter du har slått på sensoren venter du 300 ms før du leser av verdien  
  delay(300);
  
  // Read moisture level
  // Les av fuktighet
  sensorValue = analogRead(MOISTURE_PIN);
  
  // Exercise: Turn the sensor off
  // Oppgave: Slå av sensoren
  digitalWrite(MOISTURE_POWER_PIN, LOW);
  
  Serial.print("Moisture: ");
  // Print moisture level to serial port
  // Skriv ut fuktighet til serieport
  Serial.println(sensorValue);

  // Wait for 2 seconds
  // Vent 2 sekunder
  delay(2000);
}
