#include "SSD1306_SPI.h"



void SSD1306_Oled_CMD_Start(void)
{
    GPIOA ->ODR |= GPIO_ODR_ODR9;
    GPIOA ->ODR &=  ~GPIO_ODR_ODR9;
}
//

void SSD1306_Oled_CMD_Stop(void)
{
    GPIOA ->ODR |= GPIO_ODR_ODR9;
}
//

void SSD1306_Oled_Write_Command(int data[])
{
   
   SPI1_NSS_High();
   SPI1_NSS_Low();
   SSD1306_Oled_CMD_Start();
   SPI_Send_Data(SPI1, data);
   SSD1306_Oled_CMD_Stop();
   SPI1_NSS_High();
}
//

void SSD1306_Oled_Init(void)
{
    SPI_Master_Init(SPI1, 0,0, 36,0,8);
    SPI_Enable(SPI1);
     command[] = {0xA8, 0x3f, 0xd3, 0x00, 0x40, 
                     0xA0, 0xC0, 0xDa, 0x02, 0x81, 
                     0x7f, 0xA4, 0xA6, 0xd5, 0x80, 
                     0x14, 0xAF};
    
    SSD1306_Oled_Write_Command(command);
}
//

void SSD1306_Oled_Continuous_Horizontal_Scroll(int R_or_L_shift, int start_page, int end_page)
{
     command[6];
    
    if(R_or_L_shift == 1) command[0] = 0x26;
    else command[0] == 0x27;
    command[1] = 0x00;
    command[2] = (0x10 | start_page);
    command[3] = 0x03;
    command[4] = (0x80 | end_page );
    command[5] = 0x00;
    command[6] = 0xff;
    
    SSD1306_Oled_Write_Command(command);
    
}
//

void SSD1306_Oled_Deactivate_Scroll(void)
{
     command[0] = 0x2E;
     SSD1306_Oled_Write_Command(command);
     
}
//

void SSD1306_Oled_Activate_Scroll(void)
{
     command[0] = 0x2F;
     SSD1306_Oled_Write_Command(command);
     
}
//

void SSD1306_Oled_Continuous_Vertical_and_Horizontal_Scroll(int R_L_Scroll, int start_page, int end_page, uint8_t Vertical_Offset)
{
    if(R_L_Scroll == 1) command[0] = 0x29;
    else command[0] = 0x2A;
    command[1] = 0x00;
    command[2] = 0x20 | start_page;
    command[3] = 0x03;
    command[4] = 0x30 | end_page;
    command[5] = Vertical_Offset;
    SSD1306_Oled_Write_Command(command);
}
//

