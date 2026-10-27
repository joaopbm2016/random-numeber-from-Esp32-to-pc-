#include <Arduino_JSON.h>
#include <stdio.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
}

int aleatOUT()
{
  int rand = esp_random();
  delay(500);
  return (rand);

}
void loop() {
  // put your main code here, to run repeatedly:
  JsonDocument doc;
  
  JsonArray numeros = doc["numero"].to<JsonArray()>;
  numeros.add(aleatOUT());

  serializeJson(doc, Serial);
  Serial.println();

  delay(1000);
  
}
