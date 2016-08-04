#include "config.h"
#include "actions.h"
#include "remote.h"
#include "codeHandler.h"
#include "relayBoard.h"
#include "inPin.h"

remote::Config      config;
remote::Remote      remoteSensor(config);
remote::CodeHandler codeHandler(config);
remote::RelayBoard  relayBoard(config);
remote::InPin       ch1Button(config.CH1_BUTTON_PIN);
remote::InPin       ch2Button(config.CH2_BUTTON_PIN);
remote::InPin       ch3Button(config.CH3_BUTTON_PIN);
remote::InPin       ch4Button(config.CH4_BUTTON_PIN);
remote::InPin       tapeButton(config.TAPE_BUTTON_PIN);

void setup() {
  config.Load();
  remoteSensor.Initialize();

  remoteSensor.OnData([](unsigned int code){ codeHandler.HandleCode(code); });

  codeHandler.OnAction(remote::CHANNEL1,  [](){ relayBoard.Activate(remote::RelayBoard::CHANNEL1);    })
             .OnAction(remote::CHANNEL2,  [](){ relayBoard.Activate(remote::RelayBoard::CHANNEL2);    })
             .OnAction(remote::CHANNEL3,  [](){ relayBoard.Activate(remote::RelayBoard::CHANNEL3);    })
             .OnAction(remote::CHANNEL4,  [](){ relayBoard.Activate(remote::RelayBoard::CHANNEL4);    })
             .OnAction(remote::TAPEMON,   [](){ relayBoard.ToggleTapeMonitor();                       });

  ch1Button.OnEdge(RISING,  [](){ relayBoard.Activate(remote::RelayBoard::CHANNEL1);    });
  ch2Button.OnEdge(RISING,  [](){ relayBoard.Activate(remote::RelayBoard::CHANNEL2);    });
  ch3Button.OnEdge(RISING,  [](){ relayBoard.Activate(remote::RelayBoard::CHANNEL3);    });
  ch4Button.OnEdge(RISING,  [](){ relayBoard.Activate(remote::RelayBoard::CHANNEL4);    });
  tapeButton.OnEdge(RISING, [](){ relayBoard.ToggleTapeMonitor();                       });
}

void loop() {
  remoteSensor.Update();
  ch1Button.Update();
  ch2Button.Update();
  ch3Button.Update();
  ch4Button.Update();
  tapeButton.Update();

  delay(100);
}
