void setup() {
  Serial.being(9600);
}

void loop() {
  // capture data in Arduino
  int variable1 = int(random(100));

    //put the data onto the serial port
  Serial.println(variable);

  delay(200);

}
