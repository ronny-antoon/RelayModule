#ifndef RELAY_MODULE_INTERFACE_HPP
#define RELAY_MODULE_INTERFACE_HPP

/**
 * @file RelayModuleInterface.hpp
 * @brief Defines the RelayModuleInterface class
 * @details Header file declaring the abstract interface for relay modules
 * @version 1.0.0
 * @date 2023/11/08
 * @author Ronny Antoon
 * @copyright MetaHouse LTD.
 */

/**
 * @brief Interface for relay modules.
 *
 * @details This abstract class serves as an interface for relay modules,
 * providing methods for controlling the relay state (turning on/off, toggling)
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
     * @brief Turns on the relay module.
     */
    virtual void turnOn() = 0;

    /**
     * @brief Turns off the relay module.
     */
    virtual void turnOff() = 0;

    /**
     * @brief Toggles the relay module state.
     */
    virtual void toggle() = 0;

    /**
     * @brief Checks if the relay module is currently on.
     *
     * @return true if the relay module is on, false otherwise.
     */
    virtual bool isOn() = 0;
};

#endif // RELAY_MODULE_INTERFACE_HPP
