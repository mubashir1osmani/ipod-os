#include "stm32f4xx.h"
#include "scheduler.h"
#include "gpio.h"
#include "ui.h"

void task1() { toggleLED(); }  // Blink LED
void task2() { /* Update UI */ }

int main() {
    SystemInit();
    GPIO_Init();
    I2S_Init();
    UI_Init();

    addTask(task1);
    addTask(task2);
    scheduleTasks();

    return 0;
}