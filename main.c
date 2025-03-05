#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "Encoder.h"

uint8_t Speed;
int16_t Num;

int main(void)
{	
	OLED_Init();
	Motor_Init();
	Encoder_Init();
	
	OLED_ShowString(1, 1, "Speed:");
	//OLED_ShowString(2, 1, "Num:");
			
	while(1)
	{	
		Num += 2*Encoder_Get();
		if(Num > 120)
		{
			Num = 120;
		}
		else if (Num<0)
		{
			Num = 0;
		}
		
		Speed = Num;	
		
		if(Num > 120)
		{
			Speed = 120;
		}
		else if (Num<0)
		{
			Speed = 0;
		}
		
		Motor_SetSpeed(Speed);
		OLED_ShowSignedNum(1, 7, Speed, 3);
		//OLED_ShowSignedNum(2, 5, Num, 5);		
	}
}
