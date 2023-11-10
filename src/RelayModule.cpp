#include "RelayModule.hpp"

#include <esp32-hal-gpio.h> // pinMode, digitalWrite, digitalRead

RelayModule::RelayModule(uint8_t pin, bool turnOnHigh)
{
    _pin = pin;           // Pin connected to the relay module
    _onHigh = turnOnHigh; // Flag indicating if the relay module is turned on by a high or low signal

    pinMode(_pin, OUTPUT);        // Set pin as output
    digitalWrite(_pin, !_onHigh); // Turn off the relay module initially
}

RelayModule::~RelayModule()
{
    // No cleanup needed for now
}

void RelayModule::turnOn()
{
    digitalWrite(_pin, _onHigh); // Turn on the relay module
}

void RelayModule::turnOff()
{
    digitalWrite(_pin, !_onHigh); // Turn off the relay module
}

void RelayModule::toggle()
{
    digitalWrite(_pin, !digitalRead(_pin)); // Toggle the relay module state
}

bool RelayModule::isOn()
{
    return digitalRead(_pin) == _onHigh; // Check if the relay module is currently on
}
