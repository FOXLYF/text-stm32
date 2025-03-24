#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	//�⺯��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	//	�Ĵ���
	//RCC->APB2ENR = 0X00000010;
	//GPIOC ->CRH = 0X00300000;
	//GPIOC ->ODR = 0X00000000;//����//
//GPIOC ->ODR = 0X00002000;//���
	GPIO_InitTypeDef GPIO_Initstruct;//�ֲ�����
	
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initstruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_Initstruct);
	
	
	
 while(1)
	{
	GPIO_SetBits(GPIOA,GPIO_Pin_0);	
	Delay_ms(100);
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	Delay_ms(500);
	GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);
	Delay_ms(100);
	GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
	Delay_ms(500);
	}
}
