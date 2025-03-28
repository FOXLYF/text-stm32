#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 ,ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	//GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);
	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	
	GPIO_InitTypeDef GPIO_Initstructure; 
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Initstructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Initstructure);
	
	TIM_InternalClockConfig(TIM2);

	TIM_TimeBaseInitTypeDef TIM_TineBasaInitStructure;
	TIM_TineBasaInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TineBasaInitStructure.TIM_CounterMode  = TIM_CounterMode_Up;
	TIM_TineBasaInitStructure.TIM_Period  = 100 - 1 ;		//ARR
	TIM_TineBasaInitStructure.TIM_Prescaler  = 720 - 1;	//PSC
	TIM_TineBasaInitStructure.TIM_RepetitionCounter  = 0;
	TIM_TimeBaseInit(TIM2 , &TIM_TineBasaInitStructure);

		
	TIM_Cmd(TIM2,ENABLE);//������ʱ��tim2
		
	TIM_OCInitTypeDef TIM_OCInitSturucture;
	TIM_OCStructInit(&TIM_OCInitSturucture);
	TIM_OCInitSturucture.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitSturucture.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitSturucture.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitSturucture.TIM_Pulse = 0;		//CCR
	TIM_OC3Init(TIM2,&TIM_OCInitSturucture);
}

void PWM_SetCompare3(uint16_t Compare)
{
	TIM_SetCompare3(TIM2 ,Compare);
}

