// This example uses an Arduino/Genuino Zero together with
// a WiFi101 Shield or a MKR1000 to connect to shiftr.io.
//
// IMPORTANT: This example uses the new WiFi101 library.
//
// You can check on your device after a successful
// connection here: https://shiftr.io/try.
//
// by Gilberto Conti
// https://github.com/256dpi/arduino-mqtt

#include <SPI.h>
#include <WiFi101.h>
#include <MQTTClient.h>

char *ssid = "R2-D2";
char *pass = "yeah-Whatever";

WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;

void sendSetup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  client.begin("broker.shiftr.io", net);

  connect();
}

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("ADAPTIO", "771c4190", "c5c88ca4879b5f22")) { // String: clientId, String: tokenKey, String: tokenSecret
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe("/example");
  // client.unsubscribe("/example");
}

void sendLoop(int inputValue) {
  client.loop();

  if(!client.connected()) {
    connect();
  }

  // publish a message roughly every second.
  if(millis() - lastMillis > 200) {
    lastMillis = millis();
    client.publish("/ADAPTIO/set", String(inputValue));
  }
}

void messageReceived(String topic, String payload, char * bytes, unsigned int length) {
  Serial.print("incoming: ");
  Serial.print(topic);
  Serial.print(" - ");
  Serial.print(payload);
  Serial.println();
}