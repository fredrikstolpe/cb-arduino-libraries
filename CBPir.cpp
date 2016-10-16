#include "Arduino.h"
#include "CBPir.h"

CBPir::CBPir(int PIN, void (*pCallbackFunction)(CBPir*))
{
  pin = PIN;
  pCallback = pCallbackFunction;
  pinMode(pin, INPUT);
  state = digitalRead(pin);
  movement = state == HIGH;
  lastValue = state;
}

void CBPir::doWork()
{
  int value = digitalRead(pin);
  if (value != state){
    state = value;
    movement = state == HIGH;
    pCallback(this);
  }
  lastValue = value;
}
