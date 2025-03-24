#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	//¿âº¯Êý
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	//	¼Ä´æÆ÷
	//RCC->APB2ENR = 0X00000010;
	//GPIOC ->CRH = 0X00300000;
	//GPIOC ->ODR = 0X00000000;//ÁÁµÆ//
//GPIOC ->ODR = 0X00002000;//ÃðµÆ
	GPIO_InitTypeDef GPIO_Initstruct;//¾Ö²¿±äÁ¿
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initstruct.GPIO_Pin = GPIO_Pin_All;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Initstruct);
	
	
	
 while(1)
	{
	GPIO_Write(GPIOA, ~0X0001);//0000 0000 0000 0001
	Delay_ms(1000);
	GPIO_Write(GPIOA, ~0X0002);//0000 0000 0000 0010
	Delay_ms(500);
	GPIO_Write(GPIOA, ~0X0004);//0000 0000 0000 0100
	Delay_ms(1000);
	GPIO_Write(GPIOA, ~0X0008);//0000 0000 0000 1000
	Delay_ms(500);
	GPIO_Write(GPIOA, ~0X0010);//0000 0000 0001 0000
	Delay_ms(1000);
	GPIO_Write(GPIOA, ~0X0020);//0000 0000 0010 0000
	Delay_ms(500);
	GPIO_Write(GPIOA, ~0X0040);//0000 0000 0100 0000
	Delay_ms(1000);
	GPIO_Write(GPIOA, ~0X0080);//0000 0000 1000 0000
	Delay_ms(500);
	}
}
