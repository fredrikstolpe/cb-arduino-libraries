#include "Arduino.h"
#ifndef CBPir_h
#define CBPir_h

class CBPir
{
  private:
    int lastValue;
    unsigned long lastDebounceTime;
    void (*pCallback)(CBPir*);
  public:
    int pin;
    int state;
    bool movement;
    void doWork();
    CBPir(int PIN, void (*pCallbackFunction)(CBPir*));
};

#endif
