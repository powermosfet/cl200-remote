#ifndef OUTPIN_H
#define OUTPIN_H

namespace remote {
  enum LogicLevel { LOGIC_LOW, LOGIC_HIGH, HIGH_Z };
  
  class OutPin {
    int pin;
    LogicLevel level;
    
    public:
      OutPin(int);
      void Set(LogicLevel);
      LogicLevel Get();
  };
}

#endif
