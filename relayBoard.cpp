#include "relayBoard.h"

namespace remote {
  RelayBoard::RelayBoard(Config& config) :
                         ch1LedPin(config.CH1_LED_PIN),
                         relay1Pin(config.RELAY1_PIN),
                         relay2Pin(config.RELAY2_PIN),
                         relay3Pin(config.RELAY3_PIN),
                         tapePin(config.TAPE_PIN) {
    this->tapePin.Set(LOGIC_LOW);
    this->Activate(CHANNEL1);
  }
  
  void RelayBoard::Activate(Channel channel) {
    this->relay1Pin.Set(LOGIC_LOW);
    this->relay2Pin.Set(LOGIC_LOW);
    this->relay3Pin.Set(LOGIC_LOW);
    this->ch1LedPin.Set(LOGIC_LOW);

    switch(channel) { //fall-through is intentional
      case CHANNEL4:
        this->ch1LedPin.Set(HIGH_Z);
        this->relay3Pin.Set(HIGH_Z);
      case CHANNEL3:
        this->relay2Pin.Set(HIGH_Z);
      case CHANNEL2:
        this->relay1Pin.Set(HIGH_Z);
    }
  }
  
  void RelayBoard::ToggleTapeMonitor() {
    LogicLevel oldLevel = this->tapePin.Get();
    LogicLevel newLevel = oldLevel == LOGIC_LOW? HIGH_Z : LOGIC_LOW;
    this->tapePin.Set(newLevel);
  }
}
