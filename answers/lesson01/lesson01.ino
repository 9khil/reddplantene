/* Redd Plantene
 * @author: Nikhil André Luthra - Bouvet Norge
 * @web: reddplantene.labben.org / bouvet.no/reddplantene
 * @web: bouvet.no / nikhil.luthra.no
 */
void setup() {
  // Initialize serial port with 11520 bps
  // Initialiser serieport på 115200 bps
  Serial.begin(115200);

  // Print a message to serial port
  // Skriv ut melding til serieport
  Serial.println("Hello serial port");
}

void loop() {
  // Write a mesage to serial port
  // Skriv ut melding til serieport
  Serial.println("Hello loop");

  // Wait for 2 seconds
  // Vent 2 sekunder
  delay(2000);
}
