#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
const char* ssid = "BoomWiFi";
const char* pass = "zzzzzzzz";

char auth[] = "652f677016264b219c4f5b26d5a872b7";

void setup()
{
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  Blynk.begin(auth, "BoomWiFi", "zzzzzzzz");
  
    while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(1000);
  }
  Serial.println(WiFi.localIP());

}

void loop()
{
  Blynk.run();
}
