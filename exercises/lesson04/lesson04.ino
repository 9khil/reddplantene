#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Fyll ut med SSID og passord
#define WIFI_SSID "LabbenKurs"
#define WIFI_PASSWORD "labbenkurs123"

#define mqtt_server "192.168.2.30"
//#define mqtt_server "broker.hivemq.com"
#define topic "labbenkurs/fuktighet"


WiFiClient espClient;
PubSubClient client(espClient);

const int httpPort = 80;

#define MOISTURE_PIN A0

int sensorValue = 0;

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  client.setServer(mqtt_server, 1883);

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    // If you do not want to use a username and password, change next line to
     if (client.connect("ESP8266Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

long lastMsg = 0;

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 1000) {
    lastMsg = now;
    sensorValue = analogRead(MOISTURE_PIN);
    Serial.println(sensorValue);
    client.publish(topic, String(sensorValue).c_str(), true);
  }
  

  
  delay(5000);
}
