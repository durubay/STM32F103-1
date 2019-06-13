#include "SPI.h"



void SPI_Full_Duplex_Init(void){

RCC->APB2ENR |= RCC_APB2ENR_SPI1EN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
GPIOA->CRH |= GPIO_CRH_CNF15_1 | GPIO_CRH_MODE15_1 | GPIO_CRH_MODE15_0; //NSS
GPIOB->CRL |= GPIO_CRL_CNF3_1 | GPIO_CRL_MODE3_1 | GPIO_CRL_MODE3_0; //CLK
GPIOB->CRL |= GPIO_CRL_CNF5_1 | GPIO_CRL_MODE5_1 | GPIO_CRL_MODE5_0; //MOSI

SPI1->CR1 &= ~SPI_CR1_BR;
SPI1->CR1 |= SPI_CR1_CPHA | SPI_CR1_CPOL;
SPI1->CR1 |= SPI_CR1_DFF; //16BIT
SPI1->CR1 &= ~SPI_CR1_LSBFIRST;
SPI1->CR1 |= SPI_CR1_SSM;
SPI1->CR1 |= SPI_CR1_MSTR;

}

void SPI_Half_Duplex_TX_Init(void){

RCC->APB2ENR |= RCC_APB2ENR_SPI1EN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
GPIOA->CRH |= GPIO_CRH_CNF15_1 | GPIO_CRH_MODE15_1 | GPIO_CRH_MODE15_0; //NSS
GPIOB->CRL |= GPIO_CRL_CNF3_1 | GPIO_CRL_MODE3_1 | GPIO_CRL_MODE3_0; //CLK
GPIOB->CRL |= GPIO_CRL_CNF5_1 | GPIO_CRL_MODE5_1 | GPIO_CRL_MODE5_0; //MOSI

SPI1->CR1 &= ~SPI_CR1_BR;
SPI1->CR1 |= SPI_CR1_CPHA | SPI_CR1_CPOL;
	
SPI1->CR1 |= SPI_CR1_DFF; //16BIT
SPI1->CR1 &= ~SPI_CR1_LSBFIRST;
SPI1->CR1 |= SPI_CR1_SSM;
SPI1->CR1 |= SPI_CR1_MSTR;

}


void SPI_TX(int data){

SPI1->CR1 |= SPI_CR1_SSI; //NSS HIGH
SPI1->CR1 &= ~SPI_CR1_SSI; //NSS LOW
while((SPI1->SR & SPI_SR_TXE) == RESET){}
SPI1->DR = data;
while((SPI1->SR & SPI_SR_BSY) == SET){}
SPI1->CR1 |= SPI_CR1_SSI; //NSS HIGH
}


int SPI_RX(void){
SPI1->CR1 |= SPI_CR1_SSI; //NSS HIGH
SPI1->CR1 &= ~SPI_CR1_SSI; //NSS LOW
while((SPI1->SR & SPI_SR_RXNE) == SET){}
	SPI1->CR1 |= SPI_CR1_SSI; //NSS HIGH
return SPI1->DR;
	
}



int SPI_TX_BLOCK(int data[],int bytes){
	
	int counter = 0;

SPI1->CR1 &= ~SPI_CR1_SSI; //NSS LOW
while(counter < bytes){
while((SPI1->SR & SPI_SR_TXE) == RESET){}
SPI1->DR = data[counter];
	while((SPI1->SR & SPI_SR_BSY) == SET){}
	counter +=1;
}
SPI1->CR1 |= SPI_CR1_SSI; //NSS HIGH
return 0;
}


int SPI_Rx_Block(int **array,size_t length){

int *result = malloc(length);
*array = result;
	
int counter = 0;

SPI1->CR1 |= SPI_CR1_SSI; //NSS HIGH
SPI1->CR1 &= ~SPI_CR1_SSI; //NSS LOW
	while(counter <= length){
while((SPI1->SR & SPI_SR_RXNE) == SET){}
result[counter] = SPI1->DR;
	counter +=1;
}
	SPI1->CR1 |= SPI_CR1_SSI; //NSS HIGH
return 0;
}
