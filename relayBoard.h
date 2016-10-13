#ifndef RELAYBOARD_H
#define RELAYBOARD_H

#include "outPin.h"
#include "config.h"

namespace remote {
  class RelayBoard {
    Config* config;
    OutPin ch1LedPin;
    OutPin relay1Pin;
    OutPin relay2Pin;
    OutPin relay3Pin;
    OutPin tapePin;
    
    void ClearOutputs();
    void SetTape(bool);

    public:
      RelayBoard(Config&);
      void ActivateChannel1();
      void ActivateChannel2();
      void ActivateChannel3();
      void ActivateChannel4();
      void ToggleTapeMonitor();
      void NextChannel();
      void PrevChannel();
  };
}

#endif
