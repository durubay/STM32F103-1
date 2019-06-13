
STM32F103 Encoder Example

#include "stm32f10x.h"

#include "Encoder.h"

int main()

{

Encoder_Init();

int encoder_data = read_encoder();

return 0;

}
