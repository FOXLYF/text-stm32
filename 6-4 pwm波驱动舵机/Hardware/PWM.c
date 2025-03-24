#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 ,ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	
	GPIO_InitTypeDef GPIO_Initstructure; 
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Initstructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Initstructure);
	
	TIM_InternalClockConfig(TIM2);

	TIM_TimeBaseInitTypeDef TIM_TineBasaInitStructure;
	TIM_TineBasaInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TineBasaInitStructure.TIM_CounterMode  = TIM_CounterMode_Up;
	TIM_TineBasaInitStructure.TIM_Period  = 20000 - 1 ;		//ARR
	TIM_TineBasaInitStructure.TIM_Prescaler  = 72 - 1;	//PSC
	TIM_TineBasaInitStructure.TIM_RepetitionCounter  = 0;
	TIM_TimeBaseInit(TIM2 , &TIM_TineBasaInitStructure);

		
	TIM_Cmd(TIM2,ENABLE);//Æô¶¯¶¨Ê±Æ÷tim2
		
	TIM_OCInitTypeDef TIM_OCInitSturucture;
	TIM_OCStructInit(&TIM_OCInitSturucture);
	TIM_OCInitSturucture.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitSturucture.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitSturucture.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitSturucture.TIM_Pulse = 0;		//CCR
	TIM_OC2Init(TIM2,&TIM_OCInitSturucture);
}

void PWM_SetCompare2(uint16_t Compare)
{
	TIM_SetCompare2(TIM2 ,Compare);
}

