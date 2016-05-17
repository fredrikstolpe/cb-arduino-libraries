# CB Arduino libraries

A set of simple but nice class libraries to use for controlling leds, buttons och servos with an Arduino.

## Features

* Encapsulates each electronic components to get rid of state keeping variables in the scetch
* Takes care of things like debouncing for buttons and speed for servos
* Does not block the flow of the code like delay() statements does, so everything can run like multitasking
* Uses callbacks which allows for event driven code

## Installation

* Download this repository or clone into the Arduino libraries folder, on mac I think it usually is /Users/xxx/Documents/Arduino/libraries

## Usage

### CBButton

```
#include "CBButton.h"

CBButton myButton = CBButton(6, &myButtonCallback);

void myButtonCallback(CBButton* button)
{
  if (button->pressed){
    //Do stuff
  }
}

void loop()
{
  myButton.doWork(); //Needs to be called for each instance
}

```

If you want a large amount of instances of a class, you can have an array of pointers:

```
CBButton myButton = CBButton(9, &myCallback);
CBButton myOtherButton = CBButton(10, &myOtherCallback);

const int buttonAmount = 2;
Button* buttons[buttonAmount] = {
  &myButton,
  &myOtherButton
}

void loop() {
  for (int i = 0; i < buttonAmount; i++){
    buttons[i]->doWork();
  }
}

```

### CBLed

```
#include "CBLed.h"

CBLed myLed = CBLed(8);

myLed.on();
```

### CBServo

```
#include <Servo.h> //Needs to be included
#include "CBServo.h"

CBServo myServo = CBServo(5);
CBServo myOtherServo = CBServo(3);

void setup()
{
  myServo.init(170); //Angle 0 - 180
  myOtherServo.init(170);
}

void loop()
{
  myServo.doWork(); //Needs to be called for each instance
  myOtherServo.doWork();
}
```

then somewhere in the code:

```
  myServo.animateTo(140, 1, &myCallback); //1 = slowest speed
  myOtherServo.animateTo(100, 20); //20 = faster

void myCallback(){
  //This happens when myServo movement is done
}

```
