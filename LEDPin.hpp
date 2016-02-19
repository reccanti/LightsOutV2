#ifndef LEDPin_H
#define LEDPin_H

#include <Arduino.h>
class LEDPin {
  public:
    LEDPin(int pinNum);
    ~LEDPin();
    void on();
    void off();
    void emit();
    bool state;
    String toString();
  private:
    int pin;
};

#endif
