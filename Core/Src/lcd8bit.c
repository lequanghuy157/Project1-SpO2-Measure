#include "lcd8bit.h"
#include "main.h"
#include <string.h>

void LCD_Enable(void) {
    HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);
    HAL_Delay(1);
}

void LCD_Send_8Bits(uint8_t data) {
    HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, (data >> 0) & 0x01);
    HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, (data >> 1) & 0x01);
    HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, (data >> 2) & 0x01);
    HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, (data >> 3) & 0x01);
    HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, (data >> 4) & 0x01);
    HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, (data >> 5) & 0x01);
    HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, (data >> 6) & 0x01);
    HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (data >> 7) & 0x01);
}

void LCD_Send_Cmd(uint8_t cmd) {
    HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_RESET);
    LCD_Send_8Bits(cmd);
    LCD_Enable();
}

void LCD_Send_Data(uint8_t data) {
    HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_SET);
    LCD_Send_8Bits(data);
    LCD_Enable();
}

void LCD_Send_String(char *str) {
    while (*str) {
        LCD_Send_Data(*str++);
    }
}

void LCD_Set_Cursor(uint8_t row, uint8_t col) {
    uint8_t addr = (row == 0) ? 0x80 + col : 0xC0 + col;
    LCD_Send_Cmd(addr);
}

void LCD_Clear(void) {
    LCD_Send_Cmd(0x01);
    HAL_Delay(2);
}

void LCD_Init(void) {
    HAL_Delay(50);
    LCD_Send_Cmd(0x38); // 8-bit, 2 lines, 5x8 font
    LCD_Send_Cmd(0x0C); // Display on, cursor off
    LCD_Send_Cmd(0x06); // Entry mode
    LCD_Clear();
}
