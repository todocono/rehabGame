/*
  KeyboardAndMouseClick

  Controls the mouse left click and the space bar from a button on pin 2

  Hardware:
  - one pushbutton attached to D2

  WARNING: When you use the Mouse.move() command, the Arduino takes over your
  mouse and keyboard! It waits 2s till it is initialized, so use that time to reprogram on boot

  created 9 Mar 2023
  by Rodolfo Cossovich

  This example code is in the public domain.
  Borrows heavily from the code by Tom Igoe (2012)
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/KeyboardAndMouseControl
*/

#include "Keyboard.h"
#include "Mouse.h"

const int mouseButton = 2;
bool toggle = false;
void setup() {  // initialize the buttons' inputs:

  pinMode(mouseButton, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  delay(2000);  //waits 2 seconds before interfering with the regular keyboard & mouse
  // initialize mouse control:
  Mouse.begin();
  Keyboard.begin();
}

void loop() {
                             
  if (digitalRead(mouseButton) == LOW) {
    if (!toggle) {
      toggle = true;
      digitalWrite(LED_BUILTIN, HIGH);
      Keyboard.write(' ');
      Mouse.click(MOUSE_LEFT);
      Serial.println("Action!");
      digitalWrite(LED_BUILTIN, LOW);
    }
  } else {
    toggle = false;
  }
}
