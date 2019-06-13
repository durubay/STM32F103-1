STM32F103 CAN Example:

#include "stm32f10x.h"

#include "Debug.h"

#include "CAN.h"


int main(){
	
	int data[] = {1,2,3,4,5};
  
	int length = 5;
  
	int identifier = 12345;
	
  CAN_Sleep_Mode_Stop();
  
	CAN_Init_Mode_Start();
  
	CAN_Init_Mode_Stop();
  
	CAN_Normal_Mode();
	
	CAN_TX_Mailbox_0(identifier, length, data); 


	
while(1)	

{

	
}

}
