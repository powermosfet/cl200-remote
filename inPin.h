#ifndef PIN_H
#define PIN_H

namespace remote {
  typedef void (*PinCb)();

  class InPin {
      int pinN;
      PinCb callback;
      int edge;
      bool oldValue;
    public:
      InPin(int);
      void OnEdge(int, PinCb);
      void Update();
  };
}

#endif
