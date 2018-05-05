import processing.serial.*; // includes the serial object library

Serial mySerial; // creates local serial object from serial library

String myString = null; // a variable to collect serial data
int nl = 10; // ASCII code for carage return to in serial
float myVal; // float for storing converted ascii serial data

void setup(){
  size(200, 400);
  // link processing to serial port (correct one)
  String myPort = Serial.list() [4]; // find correct serial port
  mySerial = new Serial(this, myPort, 9600);
}

void draw() {
  while (mySerial.available() > 0) {
    myString = mySerial.readStringUntil(nl); //STRIPs data of serial port

    if (myString != null) {
      background (0);
      myVal = float(myString); // takes data from serial and turns it into number

      myVal = myVal/100 *height;

      rectMode(CENTER);
      rect(width/2, height-(myVal/2), 100, myVal);
    } // data was on the serial port
  } // do something if there is data on the port
}
