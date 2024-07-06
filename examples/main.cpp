#include <Arduino.h>
#include "RelayModule.hpp"

RelayModuleInterface *relayModule;

void setup()
{
    Serial.begin(115200);

    relayModule = new RelayModule(2, true);

    // Optional: Set the initial state if needed
    relayModule->setPower(false); // Turn off the relay initially
}

void loop()
{
    relayModule->setPower(true);
    delay(1000);
    relayModule->setPower(false);
    delay(1000);
}
