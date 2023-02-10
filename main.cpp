#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    stdio_usb_init();
    stdio_usb_connected();

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        // This will show up on ttyACMX
        printf("Hello\n");
        gpio_put(LED_PIN, 1);
        sleep_ms(1000);
        gpio_put(LED_PIN, 0);
        sleep_ms(1000);
    }

    return 0;
}