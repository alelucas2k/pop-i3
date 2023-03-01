/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "Utility.h"


int main(void)
{

	Utility_Init(); //habilita as funções especiais

	RCC -> AHB1ENR |= 0b10001;

	GPIOA -> MODER |= 0b01<<12;
	GPIOA -> MODER |= 0b01<<14;
	GPIOE -> MODER |= 0B01;

	while(1)
	{
		GPIOA -> ODR &= ~(1<<6);
		GPIOA -> ODR |= 1 << 7;
		GPIOE -> ODR &= ~(1);
		Delay_ms(1000);
		GPIOA -> ODR |= 1 << 6;
		GPIOA -> ODR &= ~(1<<7);
		GPIOE -> ODR &= ~(1);
		Delay_ms(1000);
		GPIOA -> ODR |= 1<<6;
		GPIOA -> ODR |= 1 << 7;
		GPIOE -> ODR &= ~(1);
		Delay_ms(50);
		GPIOE -> ODR |= 1;
		Delay_ms(50);
		GPIOE -> ODR &= ~(1);
		Delay_ms(50);
		GPIOE -> ODR |= 1;
		Delay_ms(50);
		//Delay_ms(1000);

	}


}
