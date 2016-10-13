#ifndef RELAYBOARD_H
#define RELAYBOARD_H

#include "outPin.h"
#include "config.h"

namespace remote {
  class RelayBoard {
    OutPin ch1LedPin;
    OutPin relay1Pin;
    OutPin relay2Pin;
    OutPin relay3Pin;
    OutPin tapePin;
    
    void ClearOutputs();

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
