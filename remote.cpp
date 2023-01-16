#include "remote.h"
#include "config.h"

namespace remote {
  Remote::Remote(Config& config) : irrecv(config.IR_PIN) { }

  Remote& Remote::Initialize() {
      this->irrecv.enableIRIn();

      return *this;
  }
  
  Remote& Remote::OnData(DataCallback callback){
    this->callback = callback;
    return *this;
  }

  Remote& Remote::Update(){
    if (this->irrecv.decode(&this->results)) {
      this->callback(this->results.value);
      this->irrecv.resume(); // Receive the next value
    }
    return *this;
  }
}
