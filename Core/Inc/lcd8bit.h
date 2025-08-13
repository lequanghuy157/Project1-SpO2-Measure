#ifndef LCD8BIT_H
#define LCD8BIT_H

#include "stm32f1xx_hal.h"

#define LCD_RS_GPIO_Port GPIOA
#define LCD_RS_Pin       GPIO_PIN_0
#define LCD_E_GPIO_Port  GPIOA
#define LCD_E_Pin        GPIO_PIN_1

#define LCD_D0_GPIO_Port GPIOA
#define LCD_D0_Pin       GPIO_PIN_4
#define LCD_D1_GPIO_Port GPIOA
#define LCD_D1_Pin       GPIO_PIN_5
#define LCD_D2_GPIO_Port GPIOA
#define LCD_D2_Pin       GPIO_PIN_6
#define LCD_D3_GPIO_Port GPIOA
#define LCD_D3_Pin       GPIO_PIN_7
#define LCD_D4_GPIO_Port GPIOB
#define LCD_D4_Pin       GPIO_PIN_0
#define LCD_D5_GPIO_Port GPIOB
#define LCD_D5_Pin       GPIO_PIN_1
#define LCD_D6_GPIO_Port GPIOB
#define LCD_D6_Pin       GPIO_PIN_2
#define LCD_D7_GPIO_Port GPIOB
#define LCD_D7_Pin       GPIO_PIN_10

void LCD_Init(void);
void LCD_Send_Cmd(uint8_t cmd);
void LCD_Send_Data(uint8_t data);
void LCD_Send_String(char *str);
void LCD_Set_Cursor(uint8_t row, uint8_t col);
void LCD_Clear(void);

#endif
