#ifndef CODEHANDLER_H
#define CODEHANDLER_H

#include "config.h"
#include "actions.h"

namespace remote {
  typedef void (*ActionCallback)();
  
  class CodeHandler {
      Config* config;
      ActionCallback callbacks[ACTION_COUNT];

      void LogFunction(char*);
      void PerformAction(Action);
    
    public:
      CodeHandler(Config&);
      void HandleCode(unsigned int);
      CodeHandler &OnAction(Action, ActionCallback);
  };
}

#endif
