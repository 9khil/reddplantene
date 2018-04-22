#define MOISTURE_PIN A0
#define MOISTURE_POWER_PIN D7

int sensorValue = 0;

void setup() {
  Serial.begin(115200);

  pinMode(MOISTURE_PIN, INPUT);
  pinMode(MOISTURE_POWER_PIN, OUTPUT);

  digitalWrite(MOISTURE_POWER_PIN, HIGH);

  delay(300);


}

void loop() {
  // Oppgave: Les av fuktighet


  Serial.print("Moisture: ");

  // Oppgave: Skriv ut fuktighet til serieport

  // Oppgave: Vent 2 sekunder
}
