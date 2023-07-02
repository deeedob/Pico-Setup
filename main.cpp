#include <hardware/gpio.h>
#include <pico/stdlib.h>

#include <iostream>
#include <ctime>

void blink_for(uint8_t pin, uint32_t time1, uint32_t  time2 )
{
    gpio_put(pin, true);
    sleep_ms(time1);
    gpio_put(pin, false);
    sleep_ms(time2);
}

int main() {
    stdio_usb_init();
    stdio_usb_connected();

    // Setup pins
    const uint led_pin_int = PICO_DEFAULT_LED_PIN;
    gpio_init(led_pin_int);
    gpio_set_dir(led_pin_int, GPIO_OUT);

    // Setup rand
    std::srand(static_cast<uint>(std::time(nullptr)));
    auto get_rand = [] { return static_cast<uint32_t>(std::rand() % 1000); };

   while (true) {
        // This will show up on ttyACMX
        std::cout << "Hello Pico" << std::endl;
        blink_for(led_pin_int, get_rand(), get_rand());
    }

    return 0;
}
