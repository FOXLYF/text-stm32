#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	//¿âº¯Êý
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	//	¼Ä´æÆ÷
	//RCC->APB2ENR = 0X00000010;
	//GPIOC ->CRH = 0X00300000;
	//GPIOC ->ODR = 0X00000000;//ÁÁµÆ//
//GPIOC ->ODR = 0X00002000;//ÃðµÆ
	GPIO_InitTypeDef GPIO_Initstruct;//¾Ö²¿±äÁ¿
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initstruct.GPIO_Pin = GPIO_Pin_12;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Initstruct);
	
	
	
 while(1)
	{
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);
	Delay_ms(10);
	GPIO_SetBits(GPIOB, GPIO_Pin_12);
	Delay_ms(10);
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);
	Delay_ms(10);
	GPIO_SetBits(GPIOB, GPIO_Pin_12);
	Delay_ms(10);
	}
}
