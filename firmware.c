#include <stdint.h>
#define UART0 ((volatile uint32_t*)0x10000000) // QEMU UART base address

void uart_putc(char c) {
    *UART0 = c; // Send character to UART
}

void uart_puts(const char* str) {
    while (*str) {
        uart_putc(*str++);
    }
}

int main() {
    uart_puts("Hello from QEMU!\n");
    while (1);
    return 0;
}
