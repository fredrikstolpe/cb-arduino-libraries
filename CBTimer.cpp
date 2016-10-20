#include "Arduino.h"
#include "CBTimer.h"

CBTimer::CBTimer()
{
}

void CBTimer::setTimeout(int delay, void (*pCallbackFunction)())
{
  pCallback = pCallbackFunction;
  timerDelay = delay;
  isRunning = true;
  startTime = millis();
}

void CBTimer::clear()
{
  isRunning = false;
}

void CBTimer::doWork()
{
  if (isRunning){
    if ((millis() - startTime) > timerDelay){
      isRunning = false;
      pCallback();
    }
  }
}