#include <ESP8266WiFi.h>

const char* ssid = "BoomWiFi";
const char* pass = "zzzzzzzz";

void setup () {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.print("IP address.....");
  Serial.println(WiFi.localIP());
}
void loop () {}
