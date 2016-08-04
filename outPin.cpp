#include <Arduino.h>

#include "outPin.h"

namespace remote {
  OutPin::OutPin(int pin) {
    this->pin = pin;
    this->Set(HIGH_Z);
  }

  LogicLevel OutPin::Get() {
    return this->level;
  }

  void OutPin::Set(LogicLevel level) {
    this->level = level;
    switch(level) {
      case HIGH_Z:
        pinMode(this->pin, INPUT);
        break;
      case LOGIC_LOW:
        pinMode(this->pin, OUTPUT);
        digitalWrite(this->pin, LOW);
        break;
      case LOGIC_HIGH:
        pinMode(this->pin, OUTPUT);
        digitalWrite(this->pin, HIGH);
        break;
    }
  }
}

