#define SERIESRESISTOR 10000

#define THERMISTORPIN A0



void setup() {
  Serial.begin(9600);
}

void loop() {
  
  float reading;
  reading = analogRead(THERMISTORPIN);

  Serial.print("Analog reading: ");
  Serial.println(reading);

  //Convert the value to resistance
  reading = (1023 / reading) - 1;
  reading = SERIESRESISTOR / reading;
  Serial.print("Thermistor resistance: ");
  Serial.println(reading);

  delay(1000);

  
}
