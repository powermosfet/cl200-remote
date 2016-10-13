#include "codeHandler.h"
#include "actions.h"

namespace remote {
  CodeHandler::CodeHandler(Config& config) {
    this->config = &config;
  }
  
  void CodeHandler::LogFunction(char* fun) {
    Serial.print("Code mathces function ");
    Serial.println(fun);
  }
  
  void CodeHandler::HandleCode(unsigned int code) {
    Serial.print("Handle code '");
    Serial.print(code, HEX);
    Serial.println("':");
    if(code == this->config->ch1Code) {
      LogFunction("CHANNEL1");
      this->PerformAction(CHANNEL1);
    } else if(code == this->config->ch2Code) {
      LogFunction("CHANNEL2");
      this->PerformAction(CHANNEL2);
    } else if(code == this->config->ch3Code) {
      LogFunction("CHANNEL3");
      this->PerformAction(CHANNEL3);
    } else if(code == this->config->ch4Code) {
      LogFunction("CHANNEL4");
      this->PerformAction(CHANNEL4);
    } else if(code == this->config->tapeCode) {
      LogFunction("TAPE");
      this->PerformAction(TAPEMON);
    } else if(code == this->config->upCode) {
      LogFunction("UP");
      this->PerformAction(UP);
    } else if(code == this->config->downCode) {
      LogFunction("DOWN");
      this->PerformAction(DOWN);
    }
  }

  void CodeHandler::PerformAction(Action action) {
    ActionCallback maybeCallback = this->callbacks[action];
    Serial.println("Looking for ir code callback");
    if(maybeCallback) {
      Serial.println("Found it!");
      maybeCallback();
    }
  }
  
  CodeHandler& CodeHandler::OnAction(Action action, ActionCallback callback) {
    this->callbacks[action] = callback;
    return *this;
  }
}

