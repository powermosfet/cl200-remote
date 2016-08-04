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
    
    public:
      enum Channel { CHANNEL1, CHANNEL2, CHANNEL3, CHANNEL4 };
  
      RelayBoard(Config&);
      void Activate(Channel);
      void ToggleTapeMonitor();
  };
}

#endif
