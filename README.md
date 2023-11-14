# RelayModule Library

[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/donate/?hosted_button_id=BACPRJTAU4G4E)
[![Latest](https://img.shields.io/github/v/tag/ronny-antoon/RelayModule?color=red&label=last+release)](https://github.com/ronny-antoon/RelayModule/releases)
[![Latest](https://badges.registry.platformio.org/packages/ronny-antoon/library/RelayModule.svg)](https://registry.platformio.org/libraries/ronny-antoon/RelayModule)
[![UnitTests](https://github.com/ronny-antoon/RelayModule/actions/workflows/build-and-test-embeded.yaml/badge.svg)](https://github.com/ronny-antoon/RelayModule/actions/workflows/build-and-test-embeded.yaml)

The RelayModule Library is a C++ library providing an abstract interface and implementation for controlling relay modules. It allows users to easily integrate relay functionality into ESP32/Arduino projects, offering methods for turning on/off, toggling, and checking the current state of the relay.



## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Dependency](#dependency)
- [Usage](#usage)
- [API](#API)
- [Example](#example)
- [License](#license)
- [Contributions](#contributions)
- [Platformio Registry](#platformio-registry)

## Introduction

The RelayModule Library simplifies the management of relay modules in ESP32/Arduino projects. It provides an abstract interface for controlling relay states, offering methods for turning on/off, toggling, and checking the current state.

## Features

- `Relay State Control`: Abstracts relay control with methods for turning on/off, toggling, and checking the current state.
- `Configurability`: Allows users to specify the pin connected to the relay module and whether the relay is turned on by a high or low signal.

## Installation

**Method 1**:
To use the **RelayModule** library in your PlatformIO project, follow these steps:

1. Open "platformio.ini", a project configuration file located in the root of PlatformIO project.

2. Add the following line to the `lib_deps` option of `[env:]` section:
`ronny-antoon/RelayModule@^2.0.0`

3. Build a project, PlatformIO will automatically install dependencies.

**Method 2**:
To use the **RelayModule** library in your Arduino project, follow these steps:

1. Download the latest release from the [GitHub repository](https://github.com/ronny-antoon/RelayModule).

2. In the Arduino IDE, click "Sketch" -> "Include Library" -> "Add .ZIP Library" and select the downloaded `.zip` file.

3. Make sure to link your project with the necessary ESP-IDF libraries for NVS support.

## Dependency
- [MultiPrinterLogger](https://github.com/ronny-antoon/MultiPrinterLogger#readme)

## Usage

1. Create an instance of the RelayModule class, specifying the pin connected to the relay module and whether it is turned on by a high or low signal.
```cpp
#include <RelayModule.hpp>

// Create a RelayModule instance with pin 6 and turned on by a high signal
RelayModule relayModule(6, true);
```

2. Control the relay state using the provided methods.
```cpp
// Turn on the relay module
relayModule.turnOn();

// Turn off the relay module
relayModule.turnOff();

// Toggle the relay module state
relayModule.toggle();

// Check if the relay module is currently on
bool isRelayOn = relayModule.isOn();
```

## API

The RelayModule Library provides the following classes and interfaces:
- `RelayModuleInterface`: Abstract interface for relay modules.
- `RelayModule`: Implementation of the RelayModuleInterface for relay modules.

Detailed documentation and usage examples can be found in the library source code.

## Example

Here's a simple example of how to use the RelayModule library to control a relay module:

```cpp
#include <RelayModule.hpp>

// Create a RelayModule instance with pin 6 and turned on by a high signal
RelayModule relayModule(6, true);

void setup()
{
    // Your setup code goes here
}

void loop()
{
    // Turn on the relay module
    relayModule.turnOn();
    delay(1000);

    // Turn off the relay module
    relayModule.turnOff();
    delay(1000);

    // Toggle the relay module state
    relayModule.toggle();
    delay(1000);

    // Check if the relay module is currently on
    bool isRelayOn = relayModule.isOn();

    // Your main loop code goes here
}
```

For a complete list of methods and parameters, refer to the class documentation in the source code.

## License

This library is provided under the MIT License. You are free to use, modify, and distribute it as needed.

## Contributions

If you'd like to contribute to the Database Library, please follow these guidelines:
1. Fork the repository.
2. Make your changes and document them.
3. Submit a pull request.

## Author

This library was created by Ronny Antoon. You can contact me at [ronny.antoon@gmail.com] for any questions or feedback.

## Platformio Registry

https://registry.platformio.org/libraries/ronny-antoon/RelayModule