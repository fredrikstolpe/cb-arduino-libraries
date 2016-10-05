#include "Arduino.h"
#ifndef CBLed_h
#define CBLed_h

class CBLed
{
  private:
    int currentValue;
    int targetValue;
    int fadeSpeed;
    int blinkDelay;
    unsigned long lastFadeTime;
    unsigned long lastBlinkTime;
    bool isFading;
    bool fadingUp;
    bool isBlinking;
    void (*pCallback)();
    void set(int value);
    void setFade(int value);
  public:
    int pin;
    int state;
    void on();
    void off();
    void blink(int delay);
    void fade(int value);
    void doWork();
    void fadeTo(int value, int speed, void (*pCallbackFunction)());
    void fadeTo(int value, int speed);    
    CBLed(int PIN);
};

#endif
