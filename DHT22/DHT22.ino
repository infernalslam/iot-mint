#include "DHT.h"
#define DHTPIN 10
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup (){
  Serial.begin(9600);
  dht.begin();
  pinMode(9, OUTPUT);
}

void loop (){
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();

  if(dht.readHumidity() && dht.readTemperature()){

    digitalWrite(9, HIGH);
    
    Serial.print("Hum >> ");
    Serial.println(hum);
  
    Serial.print("Temp >> ");
    Serial.println(temp);
    delay(500);  
    digitalWrite(9, LOW);
  }
  else{
    digitalWrite(9, LOW);
  }
  delay(2000);

}
