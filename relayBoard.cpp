#include "relayBoard.h"

namespace remote {
  RelayBoard::RelayBoard(Config& config) :
                          ch1LedPin(config.CH1_LED_PIN, LOGIC_HIGH),
                          relay1Pin(config.RELAY1_PIN,  LOGIC_HIGH),
                          relay2Pin(config.RELAY2_PIN,  LOGIC_HIGH),
                          relay3Pin(config.RELAY3_PIN,  LOGIC_HIGH),
                          tapePin(config.TAPE_PIN,      LOGIC_HIGH) {
      this->config = &config;
      this->ActivateChannel1();
      this->SetTape(config.tapeState);
    }

  void RelayBoard::SetTape(bool state) {
    this->tapePin.Set(state? LOGIC_LOW : LOGIC_HIGH);
    this->config->SetTapeState(state);
  }

  void RelayBoard::ClearOutputs() {
    this->relay1Pin.Set(LOGIC_HIGH);
    this->relay2Pin.Set(LOGIC_HIGH);
    this->relay3Pin.Set(LOGIC_HIGH);
    this->ch1LedPin.Set(LOGIC_LOW);
    Serial.println("Set led pin low");
  }

  void RelayBoard::ActivateChannel1() {
    Serial.println("ActivateChannel1");
    this->ClearOutputs();
    this->ch1LedPin.Set(LOGIC_HIGH);
    Serial.println("Set led pin high");
    this->config->SetCurrentChannel(1);
  }

  void RelayBoard::ActivateChannel2() {
    Serial.println("ActivateChannel2");
    this->ClearOutputs();
    this->relay1Pin.Set(LOGIC_LOW);
    this->config->SetCurrentChannel(2);
  }

  void RelayBoard::ActivateChannel3() {
    Serial.println("ActivateChannel3");
    this->ClearOutputs();
    this->relay2Pin.Set(LOGIC_LOW);
    this->config->SetCurrentChannel(3);
  }

  void RelayBoard::ActivateChannel4() {
    Serial.println("ActivateChannel4");
    this->ClearOutputs();
    this->relay3Pin.Set(LOGIC_LOW);
    this->config->SetCurrentChannel(4);
  }

  void RelayBoard::ToggleTapeMonitor() {
    this->SetTape(!this->config->tapeState);
  }

  void RelayBoard::PrevChannel() {
    switch(this->config->currentChannel) {
      case 2:
        this->ActivateChannel1();
        break;
      case 3:
        this->ActivateChannel2();
        break;
      case 4:
        this->ActivateChannel3();
        break;
    }
  }

  void RelayBoard::NextChannel() {
    switch(this->config->currentChannel) {
      case 1:
        this->ActivateChannel2();
        break;
      case 2:
        this->ActivateChannel3();
        break;
      case 3:
        this->ActivateChannel4();
        break;
    }
  }
}
