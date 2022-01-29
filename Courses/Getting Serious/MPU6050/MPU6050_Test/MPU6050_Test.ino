#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

#define MPU_ADDRESS 0x68
#define MPU_INTERRUPT 2
#define LED_PIN 13
bool blinkState = false;

MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() {
  Wire.begin();
  Serial.begin(38400);
  
  //initialize device
  Serial.println("Initializing I2C devices...");
  accelgyro.initialize();
  
  //verify connection
  Serial.println("Testing device connections...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

  //configure Arduino LED pin for output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  //read raw accel/gyro measurements from device
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  //display tab-separated accel/gyro x/y/z values
  Serial.print("a/g:\t");
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print("\t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.println(gz);

  blinkState = !blinkState;
  digitalWrite(LED_PIN, blinkState);
  delay(100);

}
