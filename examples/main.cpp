#include <Arduino.h>

#include "RelayModule.hpp"

RelayModule *relayModule;

void setup()
{
    Serial.begin(115200);

    relayModule = new RelayModule(2, true);
}

void loop()
{
    relayModule->turnOn();
    delay(1000);
    relayModule->turnOff();
    delay(1000);
}