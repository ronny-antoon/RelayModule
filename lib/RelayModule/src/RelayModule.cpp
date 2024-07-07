#include "RelayModule.hpp"

RelayModule::RelayModule(
    uint8_t const pin, bool const turnOnHigh,
    MultiPrinterLoggerInterface *const logger)
    : _pin(pin), _onHigh(turnOnHigh), _logger(logger)
{
    Log_Debug(_logger, "RelayModule initialized with pin %d, turn on %s", _pin, _onHigh ? "HIGH" : "LOW");

    pinMode(_pin, OUTPUT);
    setState(false);
}

RelayModule::~RelayModule()
{
    Log_Debug(_logger, "RelayModule destructor called");
}

void RelayModule::setState(bool const state)
{
    Log_Verbose(_logger, "RelayModule state set to: %s", state ? "On" : "Off");

    digitalWrite(_pin, state ? _onHigh : !_onHigh);
}

void RelayModule::toggle()
{
    setState(!isOn());
}

bool const RelayModule::isOn() const
{
    return digitalRead(_pin) == _onHigh;
}
