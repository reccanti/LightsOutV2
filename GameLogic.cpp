#include "GameLogic.hpp"
#include <Arduino.h>


/*
 * Initializes a new Game with a board of the 
 * specified dimensions
 */
GameLogic::GameLogic (uint8_t x, uint8_t y) {
  int arrSize = x * y;
  curX = 0;
  curY = 0;
  rows = y;
  cols = x;
}


/*
 * Assigns an LEDPin to the given coordinates
 */
void GameLogic::assign(LEDPin* t, int x, int y) {
  int i = convertToIndex(x, y);
  Serial.println(i);
  tiles[i] = t;
}


/*
 * Gets and returns a pointer to the tile at the given
 * coordinates
 */
LEDPin* GameLogic::getTileAtPoint(int x, int y) {
  int i = convertToIndex(x, y);
  
  LEDPin* p = tiles[i];

  //Serial.println(i);
  //Serial.println(rows);
  //Serial.println(cols);
  return p;  
}


/*
 * An internal utility function that converts a
 * set of 2d coordinates to a 1d index value
 */
uint8_t GameLogic::convertToIndex(uint8_t x, uint8_t y) {
  uint8_t index = y * cols + x;
  Serial.println("*****get index*****");
  Serial.println(y);
  Serial.println(x);
  Serial.println(cols, DEC);
  Serial.println("");
  Serial.println(index);
  return index;
}



