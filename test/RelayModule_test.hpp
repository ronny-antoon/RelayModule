#ifndef RELAY_MODULE_TEST_HPP
#define RELAY_MODULE_TEST_HPP

#include <gtest/gtest.h>

#include "RelayModule.hpp"

class RelayModuleTest : public ::testing::Test
{
protected:
    RelayModule *_relayModule;
    void SetUp() override
    {
        _relayModule = new RelayModule(2);
    }

    void TearDown() override
    {
        delete _relayModule;
    }
};

TEST_F(RelayModuleTest, turnOn)
{
    _relayModule->turnOn();
    EXPECT_TRUE(_relayModule->isOn());
}

TEST_F(RelayModuleTest, turnOff)
{
    _relayModule->turnOff();
    EXPECT_FALSE(_relayModule->isOn());
}

TEST_F(RelayModuleTest, toggle)
{
    _relayModule->turnOn();
    _relayModule->toggle();
    EXPECT_FALSE(_relayModule->isOn());
    _relayModule->toggle();
    EXPECT_TRUE(_relayModule->isOn());
}

#endif // RELAY_MODULE_TEST_HPP