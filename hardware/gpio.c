#include "stm32f4xx.h"

void GPIO_Init() {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;  // Enable GPIOD clock
    GPIOD->MODER |= (1 << 24);            // Set PD12 as output
}

void toggleLED() {
    GPIOD->ODR ^= (1 << 12);  // Toggle PD12 (LED)
}