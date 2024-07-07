#include "RelayModule.hpp"

RelayModule::RelayModule(uint8_t const pin, bool const isActiveHigh, MultiPrinterLoggerInterface *const logger)
    : m_pin(pin), m_isActiveHigh(isActiveHigh), m_logger(logger)
{
    Log_Debug(m_logger, "RelayModule initialized with pin %d, turn on %s", m_pin, m_isActiveHigh ? "HIGH" : "LOW");
    pinMode(m_pin, OUTPUT);
    setPower(false);
}

RelayModule::~RelayModule()
{
    Log_Debug(m_logger, "RelayModule destructor called");
}

esp_err_t RelayModule::setPower(bool const newState)
{
    Log_Verbose(m_logger, "RelayModule state set to: %s", newState ? "On" : "Off");
    digitalWrite(m_pin, newState ? m_isActiveHigh : !m_isActiveHigh);
    return ESP_OK;
}

bool RelayModule::isOn() const
{
    return digitalRead(m_pin) == m_isActiveHigh;
}
