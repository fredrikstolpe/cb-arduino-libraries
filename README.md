# CB Arduino libraries

A set of simple but nice class libraries to use for controlling leds, buttons och servos with an Arduino.

## Features

* Encapsulates each electrocal component to get rid of state keeping variables in the scetch
* Takes care of things like deboucing for buttons and speed for servos
* Does not block the flow of the code like delay() statements does, so everything can run like multitasking
* Uses callbacks which allows for event driven code

## Installation

* Download this repository or clone into the Arduino libraries folder, on mac I think it usually is /Users/xxx/Documents/Arduino/libraries
