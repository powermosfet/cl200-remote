#include <Arduino.h>
#include "inPin.h"

namespace remote {
  InPin::InPin(int pinN) {
    this->pinN = pinN;
  }

  void InPin::OnEdge(int edge, PinCb callback) {
    this->edge = edge;
    this->callback = callback;
  }

  void InPin::Update() {
    bool newValue = digitalRead(this->pinN);
    if(newValue != this->oldValue) {
      if((this->edge == RISING  &&  newValue) ||
          (this->edge == FALLING && !newValue)) {

        if(this->callback) {
          this->callback();
        }
      }
      this->oldValue = newValue;
    }
  }
}
