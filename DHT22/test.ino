#include "DHT.h"

#define DHTPIN 10 // กำหนดขา Data เพื่อรับข้อมูลจาก DHT22

#define DHTTYPE DHT22 // ใส่รุ่นให้ตรง

DHT dht(DHTPIN, DHTTYPE); // เรียกคลาส

float ft = 0;

void setup () {
  Serial.begin(9600);
  dht.begin();
  pinMode(9, OUTPUT);
  ft = dht.readTemperature();
}

void loop () {
  float h = dht.readHumidity();
  float t = dht.readTemperature();


//  Serial.print("HUM :: ");
//  Serial.println(h);

//  Serial.print("TEMP :: ");
//  Serial.println(t);

//  float td = 0;
//  td = (t - ((100-h)/5));
//  Serial.print("TD :: ");
//  Serial.println(td);

  if(t < ft){
    digitalWrite(9, HIGH);
    Serial.print(t);
    Serial.print(" < ");
    Serial.println(ft);
  }
  else {
    digitalWrite(9, LOW);
    Serial.print("ft ");
    Serial.println(ft);
    Serial.print(" t ");
    Serial.println(t);
  }

  delay(6000);
  ft = t;
  
  
}
