#ifndef RELAY_MODULE_TEST_HPP
#define RELAY_MODULE_TEST_HPP

#include <gtest/gtest.h>

#include "RelayModule.hpp"

// Define relay configuration for testing
int relayPin1 = 2;
bool turnOnHigh1 = true;
int relayPin2 = 23;
bool turnOnHigh2 = false;

// Test fixture for RelayModule class
class RelayModuleTest : public ::testing::Test
{
protected:
    uint32_t _startFreeHeap = 0; // Initial free heap size
    RelayModule *_relayModule1;  // Pointer to the first RelayModule instance
    RelayModule *_relayModule2;  // Pointer to the second RelayModule instance

    // Set up function to run before each test case
    void SetUp() override
    {
        _startFreeHeap = ESP.getFreeHeap();                      // Record initial free heap size
        _relayModule1 = new RelayModule(relayPin1, turnOnHigh1); // Create RelayModule instance 1
        _relayModule2 = new RelayModule(relayPin2, turnOnHigh2); // Create RelayModule instance 2
    }

    // Tear down function to run after each test case
    void TearDown() override
    {
        delete _relayModule1; // Delete RelayModule instance 1
        delete _relayModule2; // Delete RelayModule instance 2
        if (ESP.getFreeHeap() != _startFreeHeap)
            FAIL() << "Memory leak of " << _startFreeHeap - ESP.getFreeHeap() << " bytes"; // Fail the test if there is a memory leak
    }
};

// Test case for turnOn method
TEST_F(RelayModuleTest, turnOn)
{
    _relayModule1->turnOn();                        // Turn on RelayModule 1
    EXPECT_EQ(digitalRead(relayPin1), turnOnHigh1); // Verify the state of the relay pin

    _relayModule2->turnOn();                        // Turn on RelayModule 2
    EXPECT_EQ(digitalRead(relayPin2), turnOnHigh2); // Verify the state of the relay pin
}

// Test case for turnOff method
TEST_F(RelayModuleTest, turnOff)
{
    _relayModule1->turnOff();                        // Turn off RelayModule 1
    EXPECT_EQ(digitalRead(relayPin1), !turnOnHigh1); // Verify the state of the relay pin

    _relayModule2->turnOff();                        // Turn off RelayModule 2
    EXPECT_EQ(digitalRead(relayPin2), !turnOnHigh2); // Verify the state of the relay pin
}

// Test case for toggle method
TEST_F(RelayModuleTest, toggle)
{
    _relayModule1->toggle();                        // Toggle RelayModule 1
    EXPECT_EQ(digitalRead(relayPin1), turnOnHigh1); // Verify the state of the relay pin

    _relayModule2->toggle();                        // Toggle RelayModule 2
    EXPECT_EQ(digitalRead(relayPin2), turnOnHigh2); // Verify the state of the relay pin

    _relayModule1->toggle();                         // Toggle RelayModule 1 again
    EXPECT_EQ(digitalRead(relayPin1), !turnOnHigh1); // Verify the state of the relay pin

    _relayModule2->toggle();                         // Toggle RelayModule 2 again
    EXPECT_EQ(digitalRead(relayPin2), !turnOnHigh2); // Verify the state of the relay pin
}

// Test case for isOn method
TEST_F(RelayModuleTest, isOn)
{
    EXPECT_FALSE(_relayModule1->isOn()); // Verify RelayModule 1 is initially off
    EXPECT_FALSE(_relayModule2->isOn()); // Verify RelayModule 2 is initially off

    digitalWrite(relayPin1, turnOnHigh1); // Simulate turning on RelayModule 1
    EXPECT_TRUE(_relayModule1->isOn());   // Verify isOn correctly reports the state

    digitalWrite(relayPin2, turnOnHigh2); // Simulate turning on RelayModule 2
    EXPECT_TRUE(_relayModule2->isOn());   // Verify isOn correctly reports the state

    digitalWrite(relayPin1, !turnOnHigh1); // Simulate turning off RelayModule 1
    EXPECT_FALSE(_relayModule1->isOn());   // Verify isOn correctly reports the state

    digitalWrite(relayPin2, !turnOnHigh2); // Simulate turning off RelayModule 2
    EXPECT_FALSE(_relayModule2->isOn());   // Verify isOn correctly reports the state
}

#endif // RELAY_MODULE_TEST_HPP
