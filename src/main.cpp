#include <Arduino.h>
#include <RelayModule.hpp>

void setup()
{
    // Initialize the relay module
    RelayModule relayModule(13, true);
    // Turn on the relay module
    relayModule.setState(true);
    // Wait for 5 seconds
    delay(5000);
    // Turn off the relay module
    relayModule.setState(false);
}

void loop()
{
    // Do nothing
}
