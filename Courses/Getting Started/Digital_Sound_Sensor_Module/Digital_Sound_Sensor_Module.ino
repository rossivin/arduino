#define LED_PIN 4
#define MIC_PIN 10

int soundDetectedVal = HIGH;        //where sound measurement is recorded
boolean bAlarm = false;             //whether sound (clap) was recognized
unsigned long lastSoundDetectTime;  //record the time we measured the sound
int soundAlarmTime = 500;           //number of milliseconds to keep the sound alarm on

void setup() {
  Serial.begin(9600);  
  pinMode(LED_PIN, OUTPUT);
  pinMode(MIC_PIN, INPUT);
}

void loop() {
  soundDetectedVal = digitalRead(MIC_PIN);
  Serial.print("Detected Val: ");
  Serial.println(soundDetectedVal);

  if (soundDetectedVal == HIGH)     //if we hear a sound
  {
    digitalWrite(LED_PIN, HIGH);    //turn LED on
    lastSoundDetectTime = millis(); //record the time of the sound alarm

    //this will output the LOUD message only once, even if the signal remains at HIGH.
    if(!bAlarm)
    {
      Serial.println("LOUD");
      bAlarm = true;
    }
  }

  //this will reset the alarm and LED if sound alarm has been on for longer than soundAlarmTime
  if ((millis() - lastSoundDetectTime) > soundAlarmTime && bAlarm)
  {
    Serial.println("quiet");
    digitalWrite(LED_PIN, LOW);
    bAlarm = false;
  }

}
