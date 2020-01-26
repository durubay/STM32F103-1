#ifndef _MCP2515_
#define _MCP2515_

#include "stm32f10x.h"
#include "SPI.h"

static SPI_TypeDef *spi;


// SPI Instruction Set
#define MCP_RESET 					0xC0 //Reset internal registers
#define MCP_READ						0x03 //Read data from the register at selected address
#define MCP_READ_RX_BUFFER_0	0x90 //When reading a receive buffer, reduces the overhead of a normal READ
#define MCP_READ_RX_BUFFER_1	0x90
#define MCP_READ_RX_BUFFER_2	0x90
#define MCP_READ_RX_BUFFER_3	0x90
#define MCP_WRITE						0x02 //Writes data to the register beginning at the selected address
#define MCP_LOAD_TX_BUFFER  0x40 //When loading a transmit buffer, reduces the overhead of a normal WRITE
#define MCP_RTS							0x80 //Instructs controller to begin message transmission sequence for any of the transmit buffers
#define MCP_READ_STATUS			0xA0 //Quick polling command that reads several status bits for transmit and receive functions.
#define MCP_RX_STATU				0xB0 //Quick polling command that indicates filter match and message type  of received message.
#define MCP_BIT_MODIFY			0x05 //Allows the user to set or clear individual bits in a particular register. 


uint8_t MCP_Read_Instruction(uint8_t address);




void MCP_Read_Register(uint8_t regid);





#endif
