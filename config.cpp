#include "config.h"
#include <EEPROM.h>

namespace remote {
  Config::Config() {
  }

  Config& Config::Load() {
    Config loadedConf;
    EEPROM.get(0x0000, loadedConf);

    this->currentChannel = loadedConf.currentChannel;
    this->tapeState = loadedConf.tapeState;
    
    this->ch1Code  = 0xFF30CF; //Hardcode IR codes for now
    this->ch2Code  = 0xFF18E7;
    this->ch3Code  = 0xFF7A85;
    this->ch4Code  = 0xFF10EF;
    this->tapeCode = 0xFF52AD;
    this->upCode   = 0xFFE21D;
    this->downCode = 0xFFA25D;
    return *this;
  }

  Config& Config::Save() {
    EEPROM.put(0x0000, *this);
    return *this;
  }

  Config& Config::SetCh1Code(unsigned int code){
    this->ch1Code = code;
    this->Save();
    return *this;
  }
  
  Config& Config::SetCh2Code(unsigned int code){
    this->ch2Code = code;
    this->Save();
    return *this;
  }
  
  Config& Config::SetCh3Code(unsigned int code){
    this->ch3Code = code;
    this->Save();
    return *this;
  }
  
  Config& Config::SetCh4Code(unsigned int code){
    this->ch4Code = code;
    this->Save();
    return *this;
  }

  Config& Config::SetTapeCode(unsigned int code){
    this->tapeCode = code;
    this->Save();
    return *this;
  }

  Config& Config::SetUpCode(unsigned int code){
    this->upCode = code;
    this->Save();
    return *this;
  }
  
  Config& Config::SetDownCode(unsigned int code){
    this->downCode = code;
    this->Save();
    return *this;
  }

  Config& Config::SetCurrentChannel(unsigned int channel){
    this->currentChannel = channel;
    this->Save();
    return *this;
  }

  Config& Config::SetTapeState(bool tapeState){
    this->tapeState = tapeState;
    this->Save();
    return *this;
  }
}
