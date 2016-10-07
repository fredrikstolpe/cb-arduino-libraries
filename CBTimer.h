#include "Arduino.h"
#ifndef CBTimer_h
#define CBTimer_h

class CBTimer
{
  private:
    int timerDelay;
    unsigned long startTime;
    void (*pCallback)();
  public:
    bool isRunning;
    void setTimeout(int delay, void (*pCallbackFunction)());
    void doWork();
    CBTimer();
};

#endif
