#include <AFMotor.h>

AF_DCMotor motorLeft(2);
AF_DCMotor motorRight(3);

#define irLeft A0
#define irRight A2

void setup() 
{
  Serial.begin(9600);
  //Set initial speed of the motor & stop
	motorLeft.setSpeed(50);
	motorLeft.run(RELEASE);
  motorRight.setSpeed(65); //77
	motorRight.run(RELEASE);

  pinMode(irLeft, INPUT);
  pinMode(irRight, INPUT);
}

void loop() 
{
  int sensorStatusLeft = digitalRead(irLeft);
  int sensorStatusRight = digitalRead(irRight);

      if (sensorStatusLeft == 1 && sensorStatusRight == 0) {
        motorLeft.setSpeed(190); // 190
        motorLeft.run(BACKWARD);
        motorRight.setSpeed(200); //200
        motorRight.run(FORWARD);
        Serial.println("Left on Black");
        //delay(500);
      }
      else if (sensorStatusLeft == 0 && sensorStatusRight == 1) {
        motorLeft.setSpeed(200); //200
        motorLeft.run(FORWARD);
        motorRight.setSpeed(190); //190
        motorRight.run(BACKWARD);
        Serial.println("Right on Black");
        //delay(500);
      }
      else if (sensorStatusLeft == 1 && sensorStatusRight == 1) {
        motorLeft.setSpeed(0);
        motorLeft.run(RELEASE);
        motorRight.setSpeed(0);
        motorRight.run(RELEASE);
      }
      else {
        motorLeft.setSpeed(50);
        motorLeft.run(FORWARD);
        motorRight.setSpeed(65); //75
        motorRight.run(FORWARD);
      }
  }
