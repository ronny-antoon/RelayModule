#pragma once

#include <Arduino.h>

/**
 * @file RelayModuleInterface.hpp
 * @brief Defines the RelayModuleInterface class.
 * @details Header file declaring the abstract interface for relay modules.
 * @author Ronny Antoon
 * @copyright MetaHouse
 */

/**
 * @brief Interface for relay modules.
 *
 * @details This abstract class serves as an interface for relay modules,
 * providing methods for controlling the relay state (turning on/off, toggling),
 * and checking the current state of the relay.
 */
class RelayModuleInterface
{
public:
    /**
     * @brief Virtual destructor for RelayModuleInterface.
     */
    virtual ~RelayModuleInterface() = default;

    /**
     * @brief Sets the relay module state.
     *
     * @param newState The new state of the relay module (true for on, false for off).
     */
    virtual esp_err_t setPower(const bool newState) = 0;

    /**
     * @brief Checks if the relay module is currently on.
     *
     * @return true if the relay module is on, false otherwise.
     */
    virtual bool isOn() const = 0;
};
