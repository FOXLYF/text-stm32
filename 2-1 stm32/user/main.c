#include "stm32f10x.h"                  // Device header
int main(void)
{
	//¿âº¯Êý
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	//	¼Ä´æÆ÷
	//RCC->APB2ENR = 0X00000010;
	//GPIOC ->CRH = 0X00300000;
	//GPIOC ->ODR = 0X00000000;//ÁÁµÆ//
//GPIOC ->ODR = 0X00002000;//ÃðµÆ
	GPIO_InitTypeDef GPIO_Initstruct;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initstruct.GPIO_Pin = GPIO_Pin_13;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_Initstruct);
	GPIO_SetBits(GPIOC,GPIO_Pin_13);
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);
 while(1)
	{
	
	}
}
