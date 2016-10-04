#include "Arduino.h"
#include <Servo.h>
#ifndef CBServo_h
#define CBServo_h

class CBServo
{
  private:
    Servo servo;
    int currentPosition;
    int targetPosition;
    int movingSpeed;
    unsigned long lastAnimationTime;
    bool isAnimating;
    bool directionCW;
    void (*pCallback)();
  public:
    int pin;
    void init(int position);
    void moveTo(int position);
    void animateTo(int position, int speed, void (*pCallbackFunction)());
    void animateTo(int position, int speed);
    void doWork();
    CBServo(int PIN);
};

#endif
