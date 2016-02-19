#include "LEDPin.hpp"
#include "GameLogic.hpp"

uint8_t rows = 2;
uint8_t cols = 2;

int hKnob = A0;
int hVal = 0;

int vKnob = A1;
int vVal = 0;

LEDPin* p1 = new LEDPin(2);
LEDPin* p2 = new LEDPin(3);
LEDPin* p3 = new LEDPin(4);
LEDPin* p4 = new LEDPin(5);

GameLogic g(rows, cols);


/**
 * Given a range of values, return the int value of
 * the knob between those points
 */
 float getKnobValue(int knob, int first, int last) {
  float MAX_VAL = 1023.0;
  float knobVal = analogRead(knob);
  Serial.println(knobVal);

  float ratio = knobVal / MAX_VAL;

  float calc = ((last - first) * ratio) + first;
  int x = round(calc);
  return calc;
 }
 
 
void setup() {
  //LEDPin p1(2);
  Serial.begin(9600);
  g.assign(p4, 0, 0);
  g.assign(p3, 1, 0);
  g.assign(p2, 0, 1);
  g.assign(p1, 1, 1);
  g.getTileAtPoint(0, 0)->on();
  g.getTileAtPoint(0, 1)->on();
  g.getTileAtPoint(1, 0)->on();
  g.getTileAtPoint(1, 1)->on();

//  p1.on();
//  p2.on();
//  p3.on();
//  p4.on();
}


void loop() {
  hVal = getKnobValue(hKnob, 0, cols);
  if (hVal > 1) {
    hVal = 1;
  }
  vVal = getKnobValue(vKnob, 0, rows);
  if (vVal > 1) {
    vVal = 1;
  }
  
  //Serial.println(hVal);
  g.getTileAtPoint(0, 0)->off();
  g.getTileAtPoint(0, 1)->off();
  g.getTileAtPoint(1, 0)->off();
  g.getTileAtPoint(1, 1)->off();

  g.getTileAtPoint(hVal, vVal)->on();

  g.getTileAtPoint(0, 0)->emit();
  g.getTileAtPoint(0, 1)->emit();
  g.getTileAtPoint(1, 0)->emit();
  g.getTileAtPoint(1, 1)->emit();

////  p1.emit();
//  p2.emit();
//  p3.emit();
//  p4.emit();
  delay(1);
}



