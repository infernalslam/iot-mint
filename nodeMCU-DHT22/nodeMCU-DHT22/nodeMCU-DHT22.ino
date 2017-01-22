#include "DHT.h"
#define DHTPIN D5
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

float oldTemp = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  oldTemp = dht.readTemperature();
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
}

void loop() {

  float newTemp = dht.readTemperature();

  if(newTemp > oldTemp){
    digitalWrite(D2, HIGH);
    digitalWrite(D1, LOW);
    Serial.print(newTemp);
    Serial.print(" > ");
    Serial.println(oldTemp);
    delay(2000);
  }
  else if(newTemp < oldTemp){
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    Serial.print(newTemp);
    Serial.print(" < ");
    Serial.println(oldTemp);
    delay(2000);
  }
  else{
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    Serial.print(newTemp);
    Serial.print(" = ");
    Serial.println(oldTemp);
    delay(2000);
  }
  oldTemp = newTemp;
  delay(5000);
}
