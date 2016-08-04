#ifndef CONFIG_H
#define CONFIG_H

#include <IRremote.h>

namespace remote {
  class Config {
    public:
      static const unsigned int IR_PIN   = 2;
      static const unsigned int CH1_PIN  = 3;
      static const unsigned int CH2_PIN  = 4;
      static const unsigned int CH3_PIN  = 5;
      static const unsigned int CH4_PIN  = 6;
      static const unsigned int TAPE_PIN = 7;
    
      unsigned int ch1Code;
      unsigned int ch2Code;
      unsigned int ch3Code;
      unsigned int ch4Code;
      unsigned int tapeCode;
      unsigned int upCode;
      unsigned int downCode;

      Config();
      Config& Load();
      Config& Save();
      Config& SetCh1Code(unsigned int);
      Config& SetCh2Code(unsigned int);
      Config& SetCh3Code(unsigned int);
      Config& SetCh4Code(unsigned int);
      Config& SetTapeCode(unsigned int);
      Config& SetUpCode(unsigned int);
      Config& SetDownCode(unsigned int);
  };
}

#endif
