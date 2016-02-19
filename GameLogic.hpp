#ifndef GameLogic_H
#define GameLogic_H

#include <Arduino.h>
#include "LEDPin.hpp"


class GameLogic {
  public:
    GameLogic(uint8_t x, uint8_t y);
    void assign(LEDPin* t, int x, int y);
    LEDPin* getTileAtPoint(int x, int y);
  private:
    LEDPin* tiles[];
    int curX;
    int curY;
    uint8_t rows;
    uint8_t cols;
    uint8_t convertToIndex(uint8_t x, uint8_t y);
};

#endif
