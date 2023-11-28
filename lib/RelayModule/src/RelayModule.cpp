#include "RelayModule.hpp"

RelayModule::RelayModule(uint8_t pin, bool turnOnHigh, MultiPrinterLoggerInterface *logger) : _pin(pin), _onHigh(turnOnHigh), _logger(logger)
{
    Log_Debug(_logger, "RelayModule initialized with pin %d, turn on %s", _pin, _onHigh ? "HIGH" : "LOW");

    pinMode(_pin, OUTPUT);
    setState(false);
}

RelayModule::~RelayModule()
{
    Log_Debug(_logger, "RelayModule destructor called");
}

void RelayModule::setState(bool state)
{
    Log_Verbose(_logger, "RelayModule state set to: %s", state ? "On" : "Off");

    digitalWrite(_pin, state ? _onHigh : !_onHigh);
}

void RelayModule::toggle()
{
    setState(!isOn());
}

bool RelayModule::isOn() const
{
    return digitalRead(_pin) == _onHigh;
}
