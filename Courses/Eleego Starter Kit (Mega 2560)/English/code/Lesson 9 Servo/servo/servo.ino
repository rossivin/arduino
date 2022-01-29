//www.elegoo.com
//2018.12.19
#include <Servo.h>
Servo myservo;

void setup(){
  myservo.attach(9);
  myservo.write(120);// move servos to center position -> 90°
} 
void loop(){
  myservo.write(10);
  delay(500);
  myservo.write(20);
  delay(500);
  myservo.write(30);
  delay(500);
  myservo.write(40);
  delay(500);
  myservo.write(50);
  delay(500);
  myservo.write(60);
  delay(500);
  myservo.write(70);
  delay(500);
  myservo.write(80);
  delay(500);

  myservo.write(90);
  delay(500);

  myservo.write(80);
  delay(500);

  myservo.write(70);
  delay(500);

  myservo.write(60);
  delay(500);

  myservo.write(50);
  delay(500);

  myservo.write(40);
  delay(500);

  myservo.write(30);
  delay(500);

  myservo.write(20);
  delay(500);
  
  
}
