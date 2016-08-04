#include "config.h"
#include "actions.h"
#include "remote.h"
#include "codeHandler.h"
#include "relayBoard.h"

remote::Config      config;
remote::Remote      remoteSensor(config);
remote::CodeHandler codeHandler(config);
remote::RelayBoard  relayBoard(config);

void setup() {
  config.Load();
  remoteSensor.Initialize();

  remoteSensor.OnData([](unsigned int code){ codeHandler.HandleCode(code); });

  codeHandler.OnAction(remote::CHANNEL1,  [](){ relayBoard.Activate(remote::RelayBoard::CHANNEL1);    })
             .OnAction(remote::CHANNEL2,  [](){ relayBoard.Activate(remote::RelayBoard::CHANNEL2);    })
             .OnAction(remote::CHANNEL3,  [](){ relayBoard.Activate(remote::RelayBoard::CHANNEL3);    })
             .OnAction(remote::CHANNEL4,  [](){ relayBoard.Activate(remote::RelayBoard::CHANNEL4);    })
             .OnAction(remote::TAPEMON,   [](){ relayBoard.ToggleTapeMonitor(); });
}

void loop() {
  remoteSensor.Update();
  delay(100);
}
