#include "relayBoard.h"

namespace remote {
  RelayBoard::RelayBoard(Config& config) :
                         ch1Pin(config.CH1_PIN),
                         ch2Pin(config.CH2_PIN),
                         ch3Pin(config.CH3_PIN),
                         ch4Pin(config.CH4_PIN),
                         tapePin(config.TAPE_PIN) {
    this->config = &config;
  }
  
  void RelayBoard::Activate(Channel channel) {
    ch1Pin.Set(HIGH_Z);
    ch2Pin.Set(HIGH_Z);
    ch3Pin.Set(HIGH_Z);
    ch4Pin.Set(HIGH_Z);
    switch(channel) {
      case CHANNEL1:
        this->ch1Pin.Set(LOGIC_LOW);
        break;
      case CHANNEL2:
        this->ch2Pin.Set(LOGIC_LOW);
        break;
      case CHANNEL3:
        this->ch3Pin.Set(LOGIC_LOW);
        break;
      case CHANNEL4:
        this->ch4Pin.Set(LOGIC_LOW);
        break;
    }
  }
  
  void RelayBoard::ToggleTapeMonitor() {
    LogicLevel oldLevel = this->tapePin.Get();
    LogicLevel newLevel = oldLevel == LOGIC_LOW? HIGH_Z : LOGIC_LOW;
    this->tapePin.Set(newLevel);
  }
}
