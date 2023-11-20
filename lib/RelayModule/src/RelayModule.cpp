#include "RelayModule.hpp"

RelayModule::RelayModule(uint8_t pin, bool turnOnHigh, MultiPrinterLoggerInterface *logger) : _pin(pin), _onHigh(turnOnHigh), _logger(logger)
{
    if (_logger)
        Log_Debug(_logger, "RelayModule created on pin %d, turnOnHigh: %d", _pin, _onHigh);
    pinMode(_pin, OUTPUT);        // Set pin as output
    digitalWrite(_pin, !_onHigh); // Turn off the relay module initially
}

RelayModule::~RelayModule()
{
    if (_logger)
        Log_Debug(_logger, "RelayModule destroyed");
    // No cleanup needed for now
}

void RelayModule::turnOn()
{
    // Turn on the relay module
    if (!isOn())
        digitalWrite(_pin, _onHigh);
}

void RelayModule::turnOff()
{
    // Turn off the relay module
    if (isOn())
        digitalWrite(_pin, !_onHigh);
}

void RelayModule::toggle()
{
    // Toggle the relay module state
    if (isOn())
        turnOff();
    else
        turnOn();
}

bool RelayModule::isOn() const
{
    return digitalRead(_pin) == _onHigh; // Check if the relay module is currently on
}
