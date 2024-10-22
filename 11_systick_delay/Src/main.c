#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"

#define GPIOAEN			(1U<<0)
#define PIN5			(1U<<5)
#define LED_PIN			PIN5


int main(void)
{
	/* 1. Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;
	/* 2. Set PA5 as output pin*/
	GPIOA->MODER |= (1U << 10); // Set bit 10 to 1
	GPIOA->MODER &=~ (1U << 11); // Set bit 11 to 0

	uart2_rxtx_init();
	while (1)
	{
		systickDelayMs(1000);
		GPIOA->ODR ^= LED_PIN;
		printf("A second passed !!\n\r");
	}

}





