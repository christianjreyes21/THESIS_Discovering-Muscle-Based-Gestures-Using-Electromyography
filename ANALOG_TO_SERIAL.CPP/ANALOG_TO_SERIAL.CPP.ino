#include "Mouse.h"
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int sensorValue1 = 0;
int outputValue = 0;        // value output to the PWM (analog out)
boolean left_clicked=0;
boolean right_clicked=0;
//int clickState = 0;
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(8,LOW);
  digitalWrite(10,LOW);
  
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  sensorValue1 = analogRead(A1);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the serial monitor:
  //Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.println(sensorValue1);
  
  //Serial.print("\t output = ");
  //Serial.println(outputValue);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(20);

  if (sensorValue >= 200 && sensorValue1 >= 200) {
    // if the mouse is not pressed, press it:
    if (!left_clicked) {
      digitalWrite(8,HIGH);
      left_clicked=1;
    }
  }
  else {
    // if the mouse is pressed, release it:
    if (left_clicked) {
      digitalWrite(8,LOW);
      left_clicked=0;
    }
  }
  if (sensorValue < 200 && sensorValue1 >= 300) {
    // if the mouse is not pressed, press it:
    Serial.print("right");
    if (!right_clicked) {
      digitalWrite(10,HIGH);
      right_clicked=1;
    }
  }
  else {
    // if the mouse is pressed, release it:
    if (right_clicked){
      digitalWrite(10,LOW);
      right_clicked=0;
    }
  // else the mouse button is not pressed:
  
  }
}
