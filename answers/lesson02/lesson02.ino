#define MOISTURE_PIN A0
#define MOISTURE_POWER_PIN D7

int sensorValue = 0;

void setup() {
  Serial.begin(115200);

  // Sett MOISTURE_PIN i inputmodus
  pinMode(MOISTURE_PIN, INPUT);

  pinMode(MOISTURE_POWER_PIN, OUTPUT);

  // Sett MOISTURE_POWER_PIN til HIGH for å sende strøm til sensoren.
  digitalWrite(MOISTURE_POWER_PIN, HIGH);

  delay(300);
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
