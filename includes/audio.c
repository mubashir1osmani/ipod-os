#include "stm32f4xx.h"

void I2S_Init() {
    // Enable I2S and GPIO clocks
    RCC->APB1ENR |= RCC_APB1ENR_SPI3EN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    // Configure I2S pins (PC7: I2S3_SD, PC10: I2S3_CK)
    GPIOC->MODER |= (2 << 14) | (2 << 20);  // Alternate function mode
    GPIOC->AFR[0] |= (6 << 28);             // PC7: AF6 (I2S3_SD)
    GPIOC->AFR[1] |= (6 << 8);              // PC10: AF6 (I2S3_CK)

    // Configure I2S for 16-bit, 44.1 kHz audio
    SPI3->I2SCFGR = SPI_I2SCFGR_I2SMOD | SPI_I2SCFGR_I2SCFG_1;
    SPI3->I2SPR = (2 << 0) | (6 << 8);      // Prescaler for 44.1 kHz
    SPI3->I2SCFGR |= SPI_I2SCFGR_I2SE;      // Enable I2S
}

void playAudio(uint16_t *buffer, uint32_t size) {
    for (uint32_t i = 0; i < size; i++) {
        while (!(SPI3->SR & SPI_SR_TXE));  // Wait for TX buffer empty
        SPI3->DR = buffer[i];              // Send audio data
    }
}