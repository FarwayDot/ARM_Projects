#include <stm32f401re.h>
#include <stm32f4xx_hal.h>

void Led_Init(void)
{
	/*Configuracion del */
  RCC -> AHB1ENR |= (1<<0);

  	GPIOA -> MODER |= (1<<10);
  	GPIOA -> MODER &= ~(1<<0);

  	GPIOA -> OTYPER &= ~(1<<5);	//Para salida

  	GPIOA -> OSPEEDR &= ~((1<<11)|(1<<10));	//Para salida

 	GPIOA -> PUPDR &= ~((1<11)|(1<<10));	//Para resistencia pull up/down

}

void Pulsador_Init(void)
{
	GPIOA -> OTYPER &= ~(1<<5);	//Para salida

  	GPIOA -> OSPEEDR &= ~((1<<(2*5 + 1))|(1<<(2*5)));	//Para entrada

 	 GPIOA -> PUPDR &= ~((1<<(2*5 + 1))|(1<<(2*5)));	//Para resistencia pull up/down
}

void Led_On(void)
{
	GPIOA -> BSRR |= (1<<5);
}

void Led_Off(void)
{
	GPIOA -> BSRR |= (1<<21);
}

void Led_Toggle(void)
{
	GPIOA -> ODR ^= (1<<5); 
}

uint8_t Pulsador_Read(void)
{
	uint8_t val;

	if(!(GPIOC -> IDR & (1<<13)))
	 {
		val = 1;
	 }
	 else
	 {
		val = 0;
	 }

	return val;
}
