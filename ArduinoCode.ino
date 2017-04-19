/* Controlling a servo motor using a muscle sensor
  By Jose Catarino
    Adapted from Michal Rinott's Example

Previous Version
  v0.0                                 // imported from months ago

Current Version
  v1.0                                 // created filter function
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int sensorPin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

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
  val = analogRead(sensorPin);            // reads the value of the sensor (value between 60 and 200)
  val = map(val, 60, 200, 0, 180);     // scale it to use it with the servo (value between 0 and 180)

  avgFilter();                         //filter function

  myservo.write(g);                    // sets the servo position according to the scaled value
  delay(50);                           // waits for the servo to get there

  Serial.print(val);
  Serial.print("   ");
  Serial.println(g);
}

void avgFilter () {
  g5 = g4;
  g4 = g3;
  g3 = g2;
  g2 = g1;
  g1 = val;
  g = (g1 + g2 + g3 + g4 + g5) / 5;
}
