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

char *ssid = "BRIDGE";
char *pass = "internet";

WiFiClient net;
MQTTClient client;

const int INTERVAL = 200;

unsigned long lastMillis = 0;
int shiftrInput;

void receiveSetup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  client.begin("broker.shiftr.io", net);

  shiftrInput = 0;

  connect();
}

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("arduino", "try", "try")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");


  client.subscribe("/example");
}

void receiveLoop() {
  client.loop();

  if(!client.connected()) {
    connect();
  }

  // I don't think I'll need this...
  // publish a message roughly every second.
  // if(millis() - lastMillis > INTERVAL) {
  //   lastMillis = millis();
  //   // client.publish("/hello", "world");
    
  // }
}

void messageReceived(String topic, String payload, char * bytes, unsigned int length) {
  // Serial.print("incoming: ");
  // Serial.print(topic);
  // Serial.print(" - ");
  // Serial.print(payload);
  // Serial.println();
  
  shiftrInput = payload.toInt();

}

int getInput() {
  return shiftrInput;
}