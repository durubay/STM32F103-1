#ifndef SSD1306_H_
#define SSD1306_H_

#include "stm32f10x.h"
#include "SPI.h"
#include "Timer.h"

/*
    @pins : For SPI1
            PA4 -> NSS
            PA5 -> SCLK
            PA6 -> MISO
            PA7 -> MOSI

            For SPI2
            PA12 -> NSS
            PA13 -> SCLK
            PA14 -> MISO
            PA15 -> MOSI
            
            Common to both
            PA8 -> RESET
            PA9 -> C/D
*/

uint8_t data[];
uint8_t command[];



void SSD1306_Oled_CMD_Start(void);
void SSD1306_Oled_CMD_Stop(void);
void SSD1306_Oled_Write(int data[]);
void SSD1306_Oled_Init(void);


#endif
