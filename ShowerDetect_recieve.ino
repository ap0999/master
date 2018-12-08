#include <SoftwareSerial.h>
SoftwareSerial  BTSerial(2, 3); //TX RX
int ledPin = 8;

void setup() {
  BTSerial.begin(9600); //begin bluetooth communication
  Serial.begin(9600); //begin serial communication
  pinMode(ledPin, OUTPUT);
}
void loop() {
  if (BTSerial.available()) {
    char inChar = (char) BTSerial.read(); //reads single character at a time
    if(inChar == '1') {
      digitalWrite(ledPin, HIGH);
      
    }
    else if(inChar == '0') {
      digitalWrite(ledPin, LOW);
      
    }
    Serial.println(inChar);
  }
}
