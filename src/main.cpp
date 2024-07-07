#include <Arduino.h>
#include <RelayModule.hpp>
#include <esp_system.h>

void setup()
{
    Serial.begin(115200);

    Serial.printf("Minimum heap that has ever been available: %u\n", esp_get_minimum_free_heap_size());
    Serial.printf("Before Initialize, free heap: %u\n", esp_get_free_heap_size());

    RelayModule relayModule(2, true);
    relayModule.setState(true);
    relayModule.setState(false);
    relayModule.toggle();
    relayModule.isOn();

    Serial.printf("Minimum heap that has ever been available: %u\n", esp_get_minimum_free_heap_size());
    Serial.printf("After Initialize, free heap: %u\n", esp_get_free_heap_size());
}

void loop()
{
    // Do nothing
}
