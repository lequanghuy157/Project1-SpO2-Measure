#include "max30100.h"

void MAX30100_Init(I2C_HandleTypeDef *hi2c) {
    uint8_t mode = 0x03;
    uint8_t spo2 = 0x27;
    uint8_t led = 0x24;

    HAL_I2C_Mem_Write(hi2c, MAX30100_ADDRESS, REG_MODE_CONFIG, 1, &mode, 1, 100);
    HAL_I2C_Mem_Write(hi2c, MAX30100_ADDRESS, REG_SPO2_CONFIG, 1, &spo2, 1, 100);
    HAL_I2C_Mem_Write(hi2c, MAX30100_ADDRESS, REG_LED_CONFIG, 1, &led, 1, 100);
}

void MAX30100_ReadRaw(I2C_HandleTypeDef *hi2c, uint16_t* ir, uint16_t* red) {
    uint8_t data[4];
    HAL_I2C_Mem_Read(hi2c, MAX30100_ADDRESS, REG_FIFO_DATA, 1, data, 4, 100);
    *ir  = (data[0] << 8) | data[1];
    *red = (data[2] << 8) | data[3];
}
