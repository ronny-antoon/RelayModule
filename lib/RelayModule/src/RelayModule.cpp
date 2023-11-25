#include "RelayModule.hpp"

RelayModule::RelayModule(uint8_t pin, bool turnOnHigh, MultiPrinterLoggerInterface *logger) : _pin(pin), _onHigh(turnOnHigh), _logger(logger)
{
    Log_Debug(_logger, "RelayModule initialized with pin %d, turnOnHigh: %s", _pin, _onHigh ? "true" : "false");
    pinMode(_pin, OUTPUT); // Set pin as output
    setState(false);       // Turn off the relay module initially
}

RelayModule::~RelayModule()
{
    Log_Debug(_logger, "RelayModule destructor called");
    // No cleanup needed for now
}

void RelayModule::setState(bool state)
{
    Log_Debug(_logger, "RelayModule state set to: %s", state ? "On" : "Off");
    // Set the relay module state
    digitalWrite(_pin, state ? _onHigh : !_onHigh);
}

void RelayModule::toggle()
{
    Log_Verbose(_logger, "RelayModule state toggled");
    // Toggle the relay module state
    setState(!isOn());
}

bool RelayModule::isOn() const
{
    Log_Verbose(_logger, "RelayModule state checked");
    return digitalRead(_pin) == _onHigh; // Check if the relay module is currently on
}
