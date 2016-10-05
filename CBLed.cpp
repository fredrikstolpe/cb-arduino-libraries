#include "Arduino.h"
#include "CBLed.h"

//PWM pins: 3, 5, 6, 9, 10, 11

CBLed::CBLed(int PIN)
{
  pin = PIN;
  pinMode(pin, OUTPUT);
  state = LOW;
  currentValue = 0;
}

void CBLed::on()
{
  isBlinking = false;
  isFading = false;
  CBLed::set(HIGH);
}

void CBLed::off()
{
  isBlinking = false;
  isFading = false;  
  CBLed::set(LOW);
}

void CBLed::blink(int delay)
{
  isFading = false;
  isBlinking = true;
  lastBlinkTime = millis();
  blinkDelay = delay;
}

void CBLed::fade(int value){
  isFading = false;
  isBlinking = false;  
  CBLed::setFade(value);
}

// Private

void CBLed::set(int value)
{
  digitalWrite(pin, value);
  state = value;
  if (value == LOW){
    currentValue = 0;
  }
  else{
    currentValue = 255;
  }
}

void CBLed::setFade(int value){
  analogWrite(pin, value);
  currentValue = value;
}

void CBLed::fadeTo(int value, int speed, void (*pCallbackFunction)()){
  isBlinking = false;
  isFading = true;
  pCallback = pCallbackFunction;
  targetValue = value;
  fadingUp = (currentValue < targetValue);
  lastFadeTime = millis();
  fadeSpeed = speed;
}

void CBLed::fadeTo(int value, int speed){
  isBlinking = false;
  isFading = true;
  pCallback = NULL;
  targetValue = value;
  fadingUp = (currentValue < targetValue);
  lastFadeTime = millis();
  fadeSpeed = speed;  
}

void CBLed::doWork()
{
  if (isFading){
    if (fadingUp){
      if ((millis() - lastFadeTime) > 40){
        if (currentValue < targetValue){
          int nextValue = currentValue + fadeSpeed;
          if (nextValue > targetValue){
            nextValue = targetValue;
          }
          CBLed::setFade(nextValue);
        }
        else{
          isFading = false;
          if (pCallback != NULL){
            pCallback();
          }
        }
        lastFadeTime = millis();
      }
    }
    else{
      if ((millis() - lastFadeTime) > 40){
        if (currentValue > targetValue){
          int nextValue = currentValue - fadeSpeed;
          if (nextValue < targetValue){
            nextValue = targetValue;
          }
          CBLed::setFade(nextValue);
        }
        else{
          isFading = false;
          if (pCallback != NULL){
            pCallback();
          }
        }
        lastFadeTime = millis();
      }
    }
  }
  else if (isBlinking){
    if ((millis() - lastBlinkTime) > blinkDelay){
      if (state == LOW){
        CBLed::set(HIGH);
      }
      else{
        CBLed::set(LOW);
      }
      lastBlinkTime = millis();
    }
  }
}