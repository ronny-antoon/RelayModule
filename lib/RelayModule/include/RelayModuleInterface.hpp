#ifndef RELAY_MODULE_INTERFACE_HPP
#define RELAY_MODULE_INTERFACE_HPP

/**
 * @file RelayModuleInterface.hpp
 * @brief Defines the RelayModuleInterface class
 * @details Header file declaring the abstract interface for relay modules
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
     * @brief Sets the relay module state.
     */
    virtual void setState(const bool state) = 0;

    /**
     * @brief Toggles the relay module state.
     */
    virtual void toggle() = 0;

    /**
     * @brief Checks if the relay module is currently on.
     *
     * @return true if the relay module is on, false otherwise.
     */
    virtual bool const isOn() const = 0;
};

#endif // RELAY_MODULE_INTERFACE_HPP
