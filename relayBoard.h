#ifndef RELAYBOARD_H
#define RELAYBOARD_H

#include "outPin.h"
#include "config.h"

namespace remote {
  class RelayBoard {
    Config* config;
    OutPin ch1Pin;
    OutPin ch2Pin;
    OutPin ch3Pin;
    OutPin ch4Pin;
    OutPin tapePin;
    
    public:
      enum Channel { CHANNEL1, CHANNEL2, CHANNEL3, CHANNEL4 };
  
      RelayBoard(Config&);
      void Activate(Channel);
      void ToggleTapeMonitor();
  };
}

#endif
