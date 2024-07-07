#pragma once

/**
 * @file RelayModule.hpp
 * @brief Defines the RelayModule class
 * @details Header file for RelayModule class implementing the RelayModuleInterface
 * @author Ronny Antoon
 * @copyright MetaHouse LTD.
 */

#include <MultiPrinterLoggerInterface.hpp> // _logger
#include <esp32-hal-gpio.h>                // pinMode, digitalWrite, digitalRead
#include <stdint.h>                        // uint8_t

#include "RelayModuleInterface.hpp"

/**
 * @brief RelayModule class
 *
 * @details This class is responsible for the relay module, providing methods
 * to control the relay module by turning it on or off, and checking its state.
 */
class RelayModule : public RelayModuleInterface
{
private:
    uint8_t const _pin; // Pin connected to the relay module
    bool const _onHigh; // Flag indicating if the relay module is turned on by high or low signal

    MultiPrinterLoggerInterface *const _logger; // Pointer to the logger instance

public:
    /**
     * @brief RelayModule constructor
     *
     * @param pin The pin connected to the relay module
     * @param turnOnHigh Flag indicating if the relay module is turned on by high or low signal
     */
    RelayModule(uint8_t const pin, bool const turnOnHigh = true, MultiPrinterLoggerInterface *const logger = nullptr);

    /**
     * @brief RelayModule destructor
     */
    ~RelayModule() override;

    /**
     * @brief Sets the relay module state.
     */
    void setState(bool const state) override;

    /**
     * @brief Toggles the relay module state.
     */
    void toggle() override;

    /**
     * @brief Checks if the relay module is currently on.
     *
     * @return true if the relay module is on, false otherwise.
     */
    bool const isOn() const override;
};