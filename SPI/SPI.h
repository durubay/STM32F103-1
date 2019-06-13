#ifndef _SPI_H_
#define _SPI_H_



#include "stm32f10x.h"
#include "stdio.h"
#include "stdlib.h"

void SPI_Full_Duplex_Init(void);
void SPI_Half_Duplex_TX_Init(void);
void SPI_TX(int data);
int SPI_RX(void);
int SPI_Rx_Block(int **array,size_t length);
int SPI_TX_BLOCK(int data[],int bytes);















#endif
