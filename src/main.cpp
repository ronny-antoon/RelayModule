#include <Arduino.h>
// #include <RelayModule.hpp>
// #include <esp_system.h>
// #include <esp_log.h>

// #include <esp32-hal.h>

void setup()
{
    //     Serial.begin(115200);

    //     Serial.printf("Minimum heap that has ever been available: %u\n", esp_get_minimum_free_heap_size());
    //     Serial.printf("Before Initialize, free heap: %u\n", esp_get_free_heap_size());

    //     RelayModule relayModule(2, true);
    //     bool shouldBe = true;
    //     relayModule.setPower(shouldBe);
    //     if (relayModule.isOn() != shouldBe)
    //     {
    //         ESP_LOGE("main", "Relay is not in the expected state.");
    //     }
    //     shouldBe = false;
    //     relayModule.setPower(shouldBe);
    //     if (relayModule.isOn() != shouldBe)
    //     {
    //         ESP_LOGE("main", "Relay is not in the expected state.");
    //     }

    //     Serial.printf("Minimum heap that has ever been available: %u\n", esp_get_minimum_free_heap_size());
    //     Serial.printf("After Initialize, free heap: %u\n", esp_get_free_heap_size());
}

void loop()
{
    //     delay(1000);
    //     Serial.printf("Chip Temperature: %f\n", temperatureRead());
    //     // Do nothing

    pinMode(2, OUTPUT);

    uint8_t

        ESP_LOGI("main", "Setting relay power state to: %s", "ON");
    esp_log_level_set("main", ESP_LOG_DEBUG);
}
