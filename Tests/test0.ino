/* This file contains a test code meant to test the gain value specific to
   Yovany's arm.The test results will be evaluated based on the control quality
   of the motion.
   These will be the 3 tests conducted:
    a: the servo input will be the averaged sensor value times the gain
    b: the servo input will be the average of the product of the sensor value and
      the gain
    c: let the averaging function return the product of the averaged sensor value
      and the gain
  By Jose Catarino
    Adapted from Michal Rinott's Example

Current Version
  v0.0
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int sensorPin = 0;  // analog pin used to connect the sensor
int val;    // variable to read the value from the analog pin
int potPin = 1; // pin for potentiometer
int potVal; // raw value from potentiometer
int potVal1;

// values for the average function
int g1 = 0;
int g2 = 0;
int g3 = 0;
int g4 = 0;
int g5 = 0;
int g = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
}

// avgFilter(variable to average)
int avgFilter (int a) {
  g5 = g4;
  g4 = g3;
  g3 = g2;
  g2 = g1;
  g1 = a;
  g = (g1 + g2 + g3 + g4 + g5) / 5;
  return g;

  // test c
  //return g * gain;
}




void loop() {
  potVal = analogRead(potPin);
  val = analogRead(sensorPin);         // reads the value of the sensor (value between 60 and 200)
  val = map(val, 0 + potGain(), 200 + potGain(), 0, 180);     // scale it to use it with the servo (value between 0 and 180)

  // test a
  myservo.write(avgFilter(val));  // sets the servo position according to the scaled value
  // test b
  //myservo.write(avgFilter(val*gain));

  Serial.print("Raw Sensor Input: ");
  Serial.print(val);
  Serial.print("   ");
  Serial.print("Servo Input: ");
  Serial.print(avgFilter(val));
  Serial.print("   ");
  Serial.print("Pot Value: ");
  Serial.println(potGain());

  delay(15);
}

int potGain () {
  potVal1 = map(potVal, 0, 1023, 0, 800);
  return potVal1;
}
