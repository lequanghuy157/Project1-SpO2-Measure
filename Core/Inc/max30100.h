#ifndef MAX30100_H
#define MAX30100_H

#include "stm32f1xx_hal.h"

#define MAX30100_ADDRESS 0xAE

#define REG_FIFO_DATA    0x05
#define REG_MODE_CONFIG  0x06
#define REG_SPO2_CONFIG  0x07
#define REG_LED_CONFIG   0x09

void MAX30100_Init(I2C_HandleTypeDef *hi2c);
void MAX30100_ReadRaw(I2C_HandleTypeDef *hi2c, uint16_t* ir, uint16_t* red);

#endif
