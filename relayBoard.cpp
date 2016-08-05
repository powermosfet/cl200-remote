#include "relayBoard.h"

namespace remote {
  RelayBoard::RelayBoard(Config& config) :
                          ch1LedPin(config.CH1_LED_PIN),
                          relay1Pin(config.RELAY1_PIN),
                          relay2Pin(config.RELAY2_PIN),
                          relay3Pin(config.RELAY3_PIN),
                          tapePin(config.TAPE_PIN) {
      this->tapePin.Set(LOGIC_LOW);
      this->ActivateChannel1();
    }

  void RelayBoard::ClearOutputs() {
    this->relay1Pin.Set(LOGIC_LOW);
    this->relay2Pin.Set(LOGIC_LOW);
    this->relay3Pin.Set(LOGIC_LOW);
    this->ch1LedPin.Set(HIGH_Z);
  }

  void RelayBoard::ActivateChannel1() {
    this->ClearOutputs();
    this->ch1LedPin.Set(LOGIC_LOW);
  }

  void RelayBoard::ActivateChannel2() {
    this->ClearOutputs();
    this->relay1Pin.Set(HIGH_Z);
  }

  void RelayBoard::ActivateChannel3() {
    this->ClearOutputs();
    this->relay2Pin.Set(HIGH_Z);
  }

  void RelayBoard::ActivateChannel4() {
    this->ClearOutputs();
    this->relay3Pin.Set(HIGH_Z);
  }

  void RelayBoard::ToggleTapeMonitor() {
    LogicLevel oldLevel = this->tapePin.Get();
    LogicLevel newLevel = oldLevel == LOGIC_LOW? HIGH_Z : LOGIC_LOW;
    this->tapePin.Set(newLevel);
  }
}
