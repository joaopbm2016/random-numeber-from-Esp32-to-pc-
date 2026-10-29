#include <ArduinoJson.h>
#include "BluetoothSerial.h"

BluetoothSerial serialBT;
int id=0;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  serialBT.begin("AleatBT");
  serialBT.discover(true);
  delay(1000);
}

int aleatOUT()
{
  int rand = esp_random();
  delay(500);
  id++;
  digitalWrite(LED_BUILTIN,HIGH);
  return (rand);

}

void loop() {
  JsonDocument doc;
  
  JsonArray numeros = doc["numero"].to<JsonArray>();
  numeros.add(aleatOUT());
  
  doc["ID"] = id;

  String AleatJson;

  serializeJson(doc, AleatJson);
  serialBT.println(AleatJson);

  digitalWrite(LED_BUILTIN,LOW);

  delay(500);
  
}
