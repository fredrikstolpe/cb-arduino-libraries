#include "Arduino.h"
#ifndef CBButton_h
#define CBButton_h

class CBButton
{
  private:
    int lastValue;
    unsigned long lastDebounceTime;
    void (*pCallback)(CBButton*);
  public:
    String label;
    int pin;
    int state;
    bool pressed;
    void doWork();
    CBButton(int PIN, void (*pCallbackFunction)(CBButton*));
};

#endif
