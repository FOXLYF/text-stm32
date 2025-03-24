#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
 
int main(void)
{
	OLED_Init();
	
	OLED_ShowChar(1, 1, 'A');
	OLED_ShowString(1, 3, "Hello Word!");
	OLED_ShowNum(2, 1, 12345, 5);//��ʾ�޷���ʮ����
	OLED_ShowSignedNum(2, 7, -66, 2);//��ʾ�з���ʮ����
	OLED_ShowHexNum(3, 1, 0xAA55, 4);//��ʾʮ������
	OLED_ShowBinNum(4, 1, 0xAB55, 16);//��ʾ������
	
	
 while(1)
 {
 
	 
 }
}
