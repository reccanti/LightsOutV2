#include "LEDPin.hpp"

/*
 * Initializes a pin at the given pin number
 * and set its state to "off" (false)
 */
LEDPin::LEDPin(int pinNum) {
  pin = pinNum;
  state = false;
  
  pinMode(pin, OUTPUT);
}

LEDPin::~LEDPin() {};

/*
 * Sets the pin's value to "on" (true)
 */
void LEDPin::on() {
  state = true;
}


/*
 * Sets the pin's state to "off" (false)
 */
void LEDPin::off() {
  state = false;
}

/*
 * This function causes the LED to emit a  
 * different value depending on its state or
 * whether or not it is selected.
 */
void LEDPin::emit() {
  if (state) {
    digitalWrite(pin, HIGH);
  }
  else {
    digitalWrite(pin, LOW);
  }
}

/*
 * This function returns a string value
 * that displays the state of the LED Pin
 */
String LEDPin::toString() {
  if (state == true) {
    return "true";
  } else {
    return "false";
  }
}


