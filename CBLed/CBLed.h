#include "Arduino.h"
#ifndef CBLed_h
#define CBLed_h

class CBLed
{
  private:
  public:
    int pin;
    int state;
    void on();
    void off();
    CBLed(int PIN);
};

#endif
