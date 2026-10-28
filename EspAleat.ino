#include <ArduinoJson.h>

int id=0;

void setup() {
  Serial.begin(115200);
  delay(1000);
}

int aleatOUT()
{
  int rand = esp_random();
  delay(500);
  id++;
  return (rand);

}

void loop() {
  JsonDocument doc;
  
  JsonArray numeros = doc["numero"].to<JsonArray>();
  numeros.add(aleatOUT());
  
  doc["ID"] = id;

  serializeJson(doc, Serial);
  Serial.println();

  delay(1000);
  
}
