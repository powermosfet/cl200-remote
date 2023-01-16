#include "codeHandler.h"
#include "actions.h"

namespace remote {
  CodeHandler::CodeHandler(Config& config) {
    this->config = &config;
  }
   
  void CodeHandler::HandleCode(unsigned int code) {
    if(code == this->config->ch1Code) {
      this->PerformAction(CHANNEL1);
    } else if(code == this->config->ch2Code) {
      this->PerformAction(CHANNEL2);
    } else if(code == this->config->ch3Code) {
      this->PerformAction(CHANNEL3);
    } else if(code == this->config->ch4Code) {
      this->PerformAction(CHANNEL4);
    } else if(code == this->config->tapeCode) {
      this->PerformAction(TAPEMON);
    } else if(code == this->config->upCode) {
      this->PerformAction(UP);
    } else if(code == this->config->downCode) {
      this->PerformAction(DOWN);
    }
  }

  void CodeHandler::PerformAction(Action action) {
    ActionCallback maybeCallback = this->callbacks[action];
    if(maybeCallback) {
      maybeCallback();
    }
  }
  
  CodeHandler& CodeHandler::OnAction(Action action, ActionCallback callback) {
    this->callbacks[action] = callback;
    return *this;
  }
}

