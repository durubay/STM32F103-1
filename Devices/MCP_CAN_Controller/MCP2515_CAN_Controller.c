#include "MCP2515_CAN_Controller.h"



uint8_t MCP_Read_Instruction(uint8_t address)
{
	int data[] = { MCP_READ, address};
	 SPI1_NSS_HIGH();//NSS HIGH
	 SPI1_NSS_LOW();//NSS LOW
	 SPI_Send_Data(SPI1, data);//SEND MCP_READ & ADDRESS
	return (uint8_t)(spi -> DR);//RETURN DATA

}
//
uint8_t MCP_Read_RX_Buff_1()
{
//nss high
//nss low
	//send rx_buffer
	//rx data
}

//

void MCP_Write_Instruction(uint8_t address, uint8_t data)
{
int d[] = {MCP_WRITE,address, data};
 SPI1_NSS_HIGH();//NSS HIGH
	 SPI1_NSS_LOW();//NSS LOW
SPI_Send_Data(SPI1, d); //send data
 SPI1_NSS_HIGH();//NSS HIGH

}
	//
	
void MCP_Load_TX_Buff_1(){}
	//
	
	void MCP_Request_to_Send()
	{
		 SPI1_NSS_HIGH();//NSS HIGH
	 SPI1_NSS_LOW();//NSS LOW
		spi -> DR = MCP_RTS | (1 << 0);
		spi -> DR = MCP_RTS | (1 << 1);
		spi -> DR = MCP_RTS | (1 << 2);
		SPI1_NSS_HIGH();//NSS HIGH
	}
	//
	
	void MCP_Bit_Modify_Instruction(uint8_t address, uint8_t mask_byte, uint8_t data_byte)
	{
	int data[] = {MCP_BIT_MODIFY, address, mask_byte, data_byte};
			 SPI1_NSS_HIGH();//NSS HIGH
	 SPI1_NSS_LOW();//NSS LOW
	SPI_Send_Data(spi,data);
	SPI1_NSS_HIGH();//NSS HIGH
	
	}
