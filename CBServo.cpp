#include "Arduino.h"
#include <Servo.h>
#include "CBServo.h"

CBServo::CBServo(int PIN)
{
  pin = PIN;
}

void CBServo::init(int position)
{
  servo.attach(pin);
  CBServo::moveTo(position);
}

void CBServo::moveTo(int position)
{
  servo.write(position);
  currentPosition = position;
}

void CBServo::animateTo(int position, int speed, void (*pCallbackFunction)())
{
  pCallback = pCallbackFunction;
  targetPosition = position;
  isAnimating = true;
  directionCW = (currentPosition < targetPosition);
  lastAnimationTime = millis();
  movingSpeed = speed;
}

void CBServo::animateTo(int position, int speed)
{
  pCallback = NULL;
  targetPosition = position;
  isAnimating = true;
  directionCW = (currentPosition < targetPosition);
  lastAnimationTime = millis();
  movingSpeed = speed;
}

void CBServo::doWork()
{
  if (isAnimating){
    if ((millis() - lastAnimationTime) > 40){
      if (directionCW){
        if (currentPosition < targetPosition){
          int nextPosition = currentPosition + movingSpeed;
          if (nextPosition > targetPosition){
            nextPosition = targetPosition;
          }
          CBServo::moveTo(nextPosition);
        }
        else{
          isAnimating = false;
          if (pCallback != NULL){
            pCallback();
          }
        }
      }
      else if (!directionCW){
        if (currentPosition > targetPosition){
          int nextPosition = currentPosition - movingSpeed;
          if (nextPosition < targetPosition){
            nextPosition = targetPosition;
          }
          CBServo::moveTo(nextPosition);
        }
        else{
          isAnimating = false;
          if (pCallback != NULL){
            pCallback();
          }
        }
      }
      lastAnimationTime = millis();
    }
  }
}
