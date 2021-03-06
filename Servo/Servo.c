#include "Servo.h"

//ALTERNATIVE FUNCTION PUSH PULL


//************************************************** Timer 1 **************************************************
//  PA8, PA9, PA10, PA11

void Servo_1_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_TIM1EN;
	GPIOA->CRH |= GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8_1 | GPIO_CRH_MODE8_0;
	TIM1->PSC = 71;
	TIM1->ARR = 20000;
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1PE;
	TIM1->BDTR |= TIM_BDTR_MOE;
	TIM1->CCER |= TIM_CCER_CC1E;
	TIM1->CR1 |= TIM_CR1_ARPE;
  TIM1->EGR |= TIM_EGR_UG;
	TIM1->CR1 |= TIM_CR1_CEN;
}
void Servo_1_Update(float angle){
	TIM1->CCR1 = 5.556*angle + 1000;
}

void Servo_2_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_TIM1EN;
	GPIOA->CRH |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9_1 | GPIO_CRH_MODE9_0;
	TIM1->PSC = 71;
	TIM1->ARR = 20000;
	TIM1->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2PE;
	TIM1->BDTR |= TIM_BDTR_MOE;
	TIM1->CCER |= TIM_CCER_CC2E;
	TIM1->CR1 |= TIM_CR1_ARPE;
  TIM1->EGR |= TIM_EGR_UG;
	TIM1->CR1 |= TIM_CR1_CEN;
}
void Servo_2_Update(float angle){
	TIM1->CCR2 = 5.556*angle + 1000;
}
	
void Servo_3_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_TIM1EN;
	GPIOA->CRH |= GPIO_CRH_CNF10_1 | GPIO_CRH_MODE10_1 | GPIO_CRH_MODE10_0;
	TIM1->PSC = 71;
	TIM1->ARR = 20000;
	TIM1->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3PE;
	TIM1->BDTR |= TIM_BDTR_MOE;
	TIM1->CCER |= TIM_CCER_CC3E;
	TIM1->CR1 |= TIM_CR1_ARPE;
  TIM1->EGR |= TIM_EGR_UG;
	TIM1->CR1 |= TIM_CR1_CEN;
}
void Servo_3_Update(float angle){
	TIM1->CCR3 = 5.556*angle + 1000;
}

void Servo_4_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_TIM1EN;
	GPIOA->CRH |= GPIO_CRH_CNF11_1 | GPIO_CRH_MODE11_1 | GPIO_CRH_MODE11_0;
	TIM1->PSC = 71;
	TIM1->ARR = 20000;
	TIM1->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4PE;
	TIM1->BDTR |= TIM_BDTR_MOE;
	TIM1->CCER |= TIM_CCER_CC4E;
	TIM1->CR1 |= TIM_CR1_ARPE;
  TIM1->EGR |= TIM_EGR_UG;
	TIM1->CR1 |= TIM_CR1_CEN;
}
void Servo_4_Update(float angle){
  TIM1->CCR4 = 5.556*angle + 1000;
}

//************************************************** Timer 2 **************************************************
//  PA0, PA1, PA2, PA3

void Servo_5_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN ;
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	GPIOA-> CRL |= GPIO_CRL_CNF0_1 | GPIO_CRL_MODE0_1 | GPIO_CRL_MODE0_0;
	TIM2->PSC = 35;
	TIM2->ARR = 20000;
	TIM2->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1PE;
	TIM2->BDTR |= TIM_BDTR_MOE;
	TIM2->CCER |= TIM_CCER_CC1E;
	TIM2->CR1 |= TIM_CR1_ARPE;
  TIM2->EGR |= TIM_EGR_UG;
	TIM2->CR1 |= TIM_CR1_CEN;
}
void Servo_5_Update(float angle){
 TIM2->CCR1 = 5.556*angle + 1000;
}
	
void Servo_6_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN ;
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	GPIOA-> CRL |= GPIO_CRL_CNF1_1 | GPIO_CRL_MODE1_1 | GPIO_CRL_MODE1_0;
	TIM2->PSC = 35;
	TIM2->ARR = 20000;
	TIM2->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2PE;
	TIM2->BDTR |= TIM_BDTR_MOE;
	TIM2->CCER |= TIM_CCER_CC2E;
	TIM2->CR1 |= TIM_CR1_ARPE;
  TIM2->EGR |= TIM_EGR_UG;
	TIM2->CR1 |= TIM_CR1_CEN;
}
void Servo_6_Update(float angle){
 TIM2->CCR2 = 5.556*angle + 1000;
}
	
void Servo_7_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN ;
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	GPIOA-> CRL |= GPIO_CRL_CNF2_1 | GPIO_CRL_MODE2_1 | GPIO_CRL_MODE2_0;
	TIM2->PSC = 35;
	TIM2->ARR = 20000;
	TIM2->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3PE;
	TIM2->BDTR |= TIM_BDTR_MOE;
	TIM2->CCER |= TIM_CCER_CC3E;
	TIM2->CR1 |= TIM_CR1_ARPE;
  TIM2->EGR |= TIM_EGR_UG;
	TIM2->CR1 |= TIM_CR1_CEN;
}
void Servo_7_Update(float angle){
 TIM2->CCR3 = 5.556*angle + 1000;
}

void Servo_8_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN ;
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	GPIOA-> CRL |= GPIO_CRL_CNF3_1 | GPIO_CRL_MODE3_1 | GPIO_CRL_MODE3_0;
	TIM2->PSC = 35;
	TIM2->ARR = 20000;
	TIM2->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4PE;
	TIM2->BDTR |= TIM_BDTR_MOE;
	TIM2->CCER |= TIM_CCER_CC4E;
	TIM2->CR1 |= TIM_CR1_ARPE;
  TIM2->EGR |= TIM_EGR_UG;
	TIM2->CR1 |= TIM_CR1_CEN;
}
void Servo_8_Update(float angle){
 TIM2->CCR4 = 5.556*angle + 1000;
}

//************************************************** Timer 3 **************************************************
//  PA6, PA7, PB0, PB1

void Servo_9_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN ;
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	GPIOA-> CRH |= GPIO_CRL_CNF6_1 | GPIO_CRL_MODE6_1 | GPIO_CRL_MODE6_0;
	TIM3->PSC = 35;
	TIM3->ARR = 20000;
	TIM3->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1PE;
	TIM3->BDTR |= TIM_BDTR_MOE;
	TIM3->CCER |= TIM_CCER_CC1E;
	TIM3->CR1 |= TIM_CR1_ARPE;
  TIM3->EGR |= TIM_EGR_UG;
	TIM3->CR1 |= TIM_CR1_CEN;
}
void Servo_9_Update(float angle){
 TIM3->CCR1 = 5.556*angle + 1000;
}

void Servo_10_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN ;
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	GPIOA-> CRH |= GPIO_CRL_CNF7_1 | GPIO_CRL_MODE7_1 | GPIO_CRL_MODE7_0;
	TIM3->PSC = 35;
	TIM3->ARR = 20000;
	TIM3->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2PE;
	TIM3->BDTR |= TIM_BDTR_MOE;
	TIM3->CCER |= TIM_CCER_CC2E;
	TIM3->CR1 |= TIM_CR1_ARPE;
  TIM3->EGR |= TIM_EGR_UG;
	TIM3->CR1 |= TIM_CR1_CEN;
}
void Servo_10_Update(float angle){
 TIM3->CCR2 = 5.556*angle + 1000;
}
	
void Servo_11_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN ;
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	GPIOB-> CRL |= GPIO_CRL_CNF0_1 | GPIO_CRL_MODE0_1 | GPIO_CRL_MODE0_0;
	TIM3->PSC = 35;
	TIM3->ARR = 20000;
	TIM3->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3PE;
	TIM3->BDTR |= TIM_BDTR_MOE;
	TIM3->CCER |= TIM_CCER_CC3E;
	TIM3->CR1 |= TIM_CR1_ARPE;
  TIM3->EGR |= TIM_EGR_UG;
	TIM3->CR1 |= TIM_CR1_CEN;
}
void Servo_11_Update(float angle){
 TIM3->CCR3 = 5.556*angle + 1000;
}
	
void Servo_12_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN ;
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	GPIOB-> CRL |= GPIO_CRL_CNF1_1 | GPIO_CRL_MODE1_1 | GPIO_CRL_MODE1_0;
	TIM3->PSC = 35;
	TIM3->ARR = 20000;
	TIM3->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4PE;
	TIM3->BDTR |= TIM_BDTR_MOE;
	TIM3->CCER |= TIM_CCER_CC4E;
	TIM3->CR1 |= TIM_CR1_ARPE;
  TIM3->EGR |= TIM_EGR_UG;
	TIM3->CR1 |= TIM_CR1_CEN;
}
void Servo_12_Update(float angle){
 TIM3->CCR4 = 5.556*angle + 1000;
}

//************************************************** Timer 4 **************************************************
//  PB6, PB7, PB8, PB9
	
void Servo_13_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN ;
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	GPIOB-> CRL |= GPIO_CRL_CNF6_1 | GPIO_CRL_MODE6_1 | GPIO_CRL_MODE6_0;
	TIM4->PSC = 35;
	TIM4->ARR = 20000;
	TIM4->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1PE;
	TIM4->BDTR |= TIM_BDTR_MOE;
	TIM4->CCER |= TIM_CCER_CC1E;
	TIM4->CR1 |= TIM_CR1_ARPE;
  TIM4->EGR |= TIM_EGR_UG;
	TIM4->CR1 |= TIM_CR1_CEN;
}
void Servo_13_Update(float angle){
 TIM4->CCR1 = 5.556*angle + 1000;
}

void Servo_14_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN ;
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	GPIOB-> CRL |= GPIO_CRL_CNF7_1 | GPIO_CRL_MODE7_1 | GPIO_CRL_MODE7_0;
	TIM4->PSC = 35;
	TIM4->ARR = 20000;
	TIM4->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2PE;
	TIM4->BDTR |= TIM_BDTR_MOE;
	TIM4->CCER |= TIM_CCER_CC2E;
	TIM4->CR1 |= TIM_CR1_ARPE;
  TIM4->EGR |= TIM_EGR_UG;
	TIM4->CR1 |= TIM_CR1_CEN;
}
void Servo_14_Update(float angle){
 TIM4->CCR2 = 5.556*angle + 1000;
}
	
void Servo_15_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN ;
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	GPIOB-> CRH |= GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8_1 | GPIO_CRH_MODE8_0;
	TIM4->PSC = 35;
	TIM4->ARR = 20000;
	TIM4->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3PE;
	TIM4->BDTR |= TIM_BDTR_MOE;
	TIM4->CCER |= TIM_CCER_CC3E;
	TIM4->CR1 |= TIM_CR1_ARPE;
  TIM4->EGR |= TIM_EGR_UG;
	TIM4->CR1 |= TIM_CR1_CEN;
}
void Servo_15_Update(float angle){
 TIM4->CCR3 = 5.556*angle + 1000;
}

void Servo_16_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN ;
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	GPIOB-> CRH |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9_1 | GPIO_CRH_MODE9_0;
	TIM4->PSC = 35;
	TIM4->ARR = 20000;
	TIM4->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4PE;
	TIM4->BDTR |= TIM_BDTR_MOE;
	TIM4->CCER |= TIM_CCER_CC4E;
	TIM4->CR1 |= TIM_CR1_ARPE;
  TIM4->EGR |= TIM_EGR_UG;
	TIM4->CR1 |= TIM_CR1_CEN;
}
void Servo_16_Update(float angle){
 TIM4->CCR4 = 5.556*angle + 1000;
}
	
