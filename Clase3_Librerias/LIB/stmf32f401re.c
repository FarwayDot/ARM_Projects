
#include <stm32f401re.h>
#include <stm32f4xx_hal.h>	//Esta libreria para que reconozca los registros

void Led_Init(void)
{
	/*GPIOA PA5 */
	RCC -> AHB1ENR |= (1<<0);		//Habilitar clock ahb1

  	GPIOA -> MODER |= (1<<(2*5));	//Como salida
  	GPIOA -> MODER &= ~(1<<(2*5 + 1));

  	GPIOA -> OTYPER &= ~(1<<5);		//Para salida push pull

  	GPIOA -> OSPEEDR &= ~((1<<11)|(1<<10));	//Velocidad 2MHz

 	GPIOA -> PUPDR &= ~(1<<(2*5));	//Para resistencia pull up/down
 	GPIOA -> PUPDR &= ~(1<<(2*5 + 1));
}

void Push_Init(void)
{
	RCC -> AHB1ENR |= (1<<2);			//Habilitar clock PORTC

	GPIOC -> MODER &= ~(1<<(2*13));		//Como entrada
	GPIOC -> MODER &= ~(1<<(2*13 + 1));

 	GPIOC -> PUPDR &= ~(1<<(2*13));		//No pull up/down
 	GPIOC -> PUPDR &= ~(1<<(2*13 + 1));
}

void Led_On(void)
{
	GPIOA -> BSRR |= (1<<5);
}

void Led_Off(void)
{
	GPIOA -> BSRR |= (1<<(5+16));
}

void Led_Toggle(void)
{
	// Este registro es para trabajar con todo el puerto
	GPIOA -> ODR ^= (1<<5);
}

uint8_t Push_Read(void)
{
	uint8_t val;

	//Para pull-up

	if(!(GPIOC -> IDR & (1<<13)))
	 {

		val = 1;	//Para encender
	 }
	 else
	 {
		val = 0;	//Para apagar
	 }

	return val;
}
