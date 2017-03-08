void setup() {
  // Initialiser serieport på 115200 bps
  Serial.begin(115200);

  // Skriv ut melding til serieport
  Serial.println("Hello serial port");
}

void loop() {
  // Skriv ut melding til serieport
  Serial.println("Hello loop");

  // Vent 2 sekunder
  delay(2000);
}
