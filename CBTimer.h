#include "Arduino.h"
#ifndef CBTimer_h
#define CBTimer_h

class CBTimer
{
  private:
    int timerDelay;
    unsigned long startTime;
    bool isRunning;
    void (*pCallback)();
  public:
    void setTimeout(int delay, void (*pCallbackFunction)());
    void doWork();
    CBTimer();
};

#endif
