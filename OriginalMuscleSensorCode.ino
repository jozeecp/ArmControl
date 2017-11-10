/* Controlling a servo motor using a muscle sensor
  By Jose Catarino
    Adapted from Michal Rinott's Example

Previous Version
  v0.0                                 // imported from months ago
  v1.0                                 // created filter function


Current Version
  v1.0.1                               // 4/20/17, modified filter fn as int fn
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int sensorPin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

// values for the average function
int g1 = 0;
int g2 = 0;
int g3 = 0;
int g4 = 0;
int g5 = 0;
int g = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(sensorPin);         // reads the value of the sensor (value between 60 and 200)
  val = map(val, 60, 200, 0, 180);     // scale it to use it with the servo (value between 0 and 180)

  myservo.write(avgFilter(val));             // sets the servo position according to the scaled value

  Serial.print(val);
  Serial.print("   ");
  Serial.println(g);
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
}
