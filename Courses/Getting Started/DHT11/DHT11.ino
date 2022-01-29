#include <DHT.h>
#define DHT11_PIN 2
#define DHTTYPE DHT11

DHT dht(DHT11_PIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  float t = dht.readTemperature(false);
  Serial.print("Temperature: ");
  Serial.println(t);
  float h = dht.readHumidity();
  Serial.print("Humidity: ");
  Serial.println(h);
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print("HIC: ");
  Serial.println(hic);
  delay(3000);
}
