//Where is the led connected?
//Port:	A
//Pin:	5

#include <stdint.h>  // Include this header file for fixed-width integer types
#include <stddef.h>  // Include this header file for size_t and NULL (optional but common)

#define PERIPH_BASE				(0X40000000ul) //(ul = unsigned long)
#define AHB1PERIPH_OFFSET		(0X00020000UL)
#define AHB1PERIPH_BASE 		(PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET			(0x0000UL)

#define GPIOA_BASE				(AHB1PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET				(0x3800UL)	//we need the RCC to enable clock access to GPIO A
#define RCC_BASE				(AHB1PERIPH_BASE + RCC_OFFSET)



#define GPIOAEN					(1U << 0) // shift '1' to position 0 (enable GPIO A clock)

#define PIN5					(1U << 5)
#define LED_PIN 				PIN5

#define __IO volatile

//typedef struct
//{
//
//};GPIO_TypeDef;

typedef struct
{
	volatile uint32_t MODER;    /*!< GPIO port mode register,               	Address offset: 0x00 */
	volatile uint32_t DUMMY[4];
	volatile uint32_t ODR;      /*!< GPIO port output data register,        	Address offset: 0x14 */
} GPIO_TypeDef;

typedef struct
{
	volatile uint32_t DUMMY[12];
	volatile uint32_t AHB1ENR;  /*!< RCC AHB1 peripheral clock enable register,    Address offset: 0x30 */
} RCC_TypeDef;

#define RCC		((RCC_TypeDef*)RCC_BASE)
#define GPIOA	((GPIO_TypeDef*)GPIOA_BASE)

int main (void)
{
	/* 1. Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;
	/* 2. Set PA5 as output pin*/
	GPIOA->MODER |= (1U << 10); // Set bit 10 to 1
	GPIOA->MODER &=~ (1U << 11); // Set bit 11 to 0


	while (1)
	{
		/* 3. Set PA5 as output pin*/
//		GPIOA->ODR |= LED_PIN;

		/* 4. Experiment 2: toogle PA5 */
		GPIOA->ODR ^= LED_PIN;
		for (int i = 0; i < 100000; ++i) {

		}
	}
}
