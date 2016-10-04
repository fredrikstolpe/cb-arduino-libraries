#include "Arduino.h"
#include "CBButton.h"

CBButton::CBButton(int PIN, void (*pCallbackFunction)(CBButton*))
{
  pin = PIN;
  pCallback = pCallbackFunction;
  pinMode(pin, INPUT_PULLUP);
  state = digitalRead(pin);
  pressed = state == LOW;
  lastValue = state;
  lastDebounceTime = 0;
}

void CBButton::doWork()
{
  int value = digitalRead(pin);
  if (value != lastValue){
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > 10){
    if (value != state){
      state = value;
      pressed = state == LOW;
      pCallback(this);
    }
  }
  lastValue = value;
}
