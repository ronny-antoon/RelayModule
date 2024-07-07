#pragma once

/**
 * @file RelayModule.hpp
 * @brief Defines the RelayModule class.
 * @details Header file for RelayModule class implementing the RelayModuleInterface.
 * @authored Ronny Antoon
 * @company MetaHouse
 */

#include <Arduino.h>

#include "RelayModuleInterface.hpp"
#include <MultiPrinterLoggerInterface.hpp>

#ifndef CONFIG_R_B_M_ACTIVE_HIGH
#define CONFIG_R_B_M_ACTIVE_HIGH true
#endif

/**
 * @brief RelayModule class.
 *
 * @details This class is responsible for controlling the relay module, providing methods
 * to turn the relay module on or off, and checking its state.
 */
class RelayModule : public RelayModuleInterface
{
public:
    /**
     * @brief RelayModule constructor.
     *
     * @param pin The pin connected to the relay module.
     * @param isActiveHigh Flag indicating if the relay module is turned on by high or low signal.
     * @param logger Pointer to the logger instance.
     */
    RelayModule(uint8_t const pin, bool const isActiveHigh = CONFIG_R_B_M_ACTIVE_HIGH, MultiPrinterLoggerInterface *const logger = nullptr);

    /**
     * @brief RelayModule destructor.
     */
    ~RelayModule() override;

    /**
     * @brief Sets the relay module state.
     *
     * @param newState The new state of the relay module (true for on, false for off).
     * @return esp_err_t Error code indicating success or failure.
     */
    esp_err_t setPower(bool const newState) override;

    /**
     * @brief Checks if the relay module is currently on.
     *
     * @return true if the relay module is on, false otherwise.
     */
    bool isOn() const override;

private:
    uint8_t const m_pin;                         ///< Pin connected to the relay module.
    bool const m_isActiveHigh;                   ///< Flag indicating if the relay module is turned on by high or low signal.
    MultiPrinterLoggerInterface *const m_logger; ///< Pointer to the logger instance.

    // Deleted copy constructor and assignment operator
    RelayModule(RelayModule const &) = delete;
    RelayModule &operator=(RelayModule const &) = delete;
};
