#ifndef REMOTE_H
#define REMOTE_H

#include <IRremote.h>
#include <IRremoteInt.h>

#include "config.h"

namespace remote {
  typedef void (*DataCallback)(unsigned int);
 
  class Remote {
    IRrecv irrecv;
    decode_results results;
    DataCallback callback;
    
    public:
      Remote(Config&);
      Remote& Initialize();
      Remote& OnData(DataCallback);
      Remote& Update();
  };
}

#endif
