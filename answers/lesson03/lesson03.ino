#define MOISTURE_PIN A0
#define MOISTURE_POWER_PIN D7
#define LED_PIN D2

int sensorValue = 0;

void setup() {
  Serial.begin(115200);

  // Sett MOISTURE_PIN i inputmodus
  pinMode(MOISTURE_PIN, INPUT);

  pinMode(MOISTURE_POWER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  
  // Sett MOISTURE_POWER_PIN til LOW ved oppstart.
  digitalWrite(MOISTURE_POWER_PIN, LOW);
   digitalWrite(LED_PIN, LOW);

  delay(300);
}

void loop() {
 
  // Slå på sensoren
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(MOISTURE_POWER_PIN, HIGH);
  
  
  //Etter du har slått på sensoren venter du 300 ms før du leser av verdien.
  delay(300);
  sensorValue = analogRead(MOISTURE_PIN);

  //slå av sensoren igjen
  delay(100);
  digitalWrite(MOISTURE_POWER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  Serial.print("Moisture: ");

  // Skriv ut fuktighet til serieport
  Serial.println(sensorValue);

  // Vent 2 sekunder
  delay(2000);
}
