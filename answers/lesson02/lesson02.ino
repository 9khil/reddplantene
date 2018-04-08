#define MOISTURE_PIN A0
int sensorValue = 0;

void setup() {
  Serial.begin(115200);

  // Sett A0 i inputmodus
  pinMode(MOISTURE_PIN, INPUT);
}

void loop() {
  // Les av fuktighet
  sensorValue = analogRead(MOISTURE_PIN);

  Serial.print("Moisture: ");

  // Skriv ut fuktighet til serieport
  Serial.println(sensorValue);

  // Vent 2 sekunder
  delay(2000);
}
