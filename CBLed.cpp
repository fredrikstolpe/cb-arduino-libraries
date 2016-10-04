#include "Arduino.h"
#include "CBLed.h"

CBLed::CBLed(int PIN)
{
  pin = PIN;
  pinMode(pin, OUTPUT);
  state = LOW;
}

void CBLed::on()
{
  digitalWrite(pin, HIGH);
  state = HIGH;
}

void CBLed::off()
{
  digitalWrite(pin, LOW);
  state = LOW;
}
