#include "Encoder.h"


void Encoder_Int(){

	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	TIM4 -> ARR = 0xFFFF;
	TIM4 -> CCMR1 |= (TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0);
	TIM4 -> CCER &= ~(TIM_CCER_CC1P | TIM_CCER_CC2P);
	TIM4 -> SMCR |= TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1;
	TIM4 -> CR1 |= TIM_CR1_CEN;
	
}

int read_encoder(){
	
	return TIM4->CNT;
}