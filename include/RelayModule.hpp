#ifndef RELAY_MODULE_HPP
#define RELAY_MODULE_HPP

/**
 * @file RelayModule.hpp
 * @brief Defines the RelayModule class
 * @details Header file for RelayModule class implementing the RelayModuleInterface
 * @version 1.0.0
 * @date 2023/11/08
 * @author Ronny Antoon
 * @copyright MetaHouse LTD.
 */

#include <stdint.h> // uint8_t

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
    uint8_t _pin; // Pin connected to the relay module
    bool _onHigh; // Flag indicating if the relay module is turned on by high or low signal

public:
    /**
     * @brief RelayModule constructor
     *
     * @param pin The pin connected to the relay module
     * @param turnOnHigh Flag indicating if the relay module is turned on by high or low signal
     */
    RelayModule(uint8_t pin, bool turnOnHigh = true);

    /**
     * @brief RelayModule destructor
     */
    ~RelayModule() override;

    /**
     * @brief Turns on the relay module.
     */
    void turnOn() override;

    /**
     * @brief Turns off the relay module.
     */
    void turnOff() override;

    /**
     * @brief Toggles the relay module state.
     */
    void toggle() override;

    /**
     * @brief Checks if the relay module is currently on.
     *
     * @return true if the relay module is on, false otherwise.
     */
    bool isOn() override;
};

#endif // RELAY_MODULE_HPP
