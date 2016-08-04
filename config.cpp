#include "config.h"
#include <EEPROM.h>

namespace remote {
  Config::Config() {
  }

  Config& Config::Load() {
    EEPROM.get(0x0000, *this);
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
}
