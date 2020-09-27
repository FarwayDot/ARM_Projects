#ifndef __KEYPAD__
#define __KEYPAD__

#include "stm32f4xx_hal_def.h"

/*
	ROW1_PIN		//	PC8
	ROW2_PIN		//	PC6
	ROW3_PIN		//	PC5
	ROW4_PIN		 //	PA12
	COL1_PIN		//	PA11
	COL2_PIN		//	PB12
	COL3_PIN		//	PB2
	COL4_PIN		//	PB1
*/
#define  ROW1_OFF       GPIOC->BSRR |= (1 << ( ( 8) + 16 ))
#define  ROW2_OFF       GPIOC->BSRR |= (1 << ( ( 6) + 16 ))
#define  ROW3_OFF       GPIOC->BSRR |= (1 << ( ( 5) + 16 ))
#define  ROW4_OFF       GPIOA->BSRR |= (1 << ( (12) + 16 ))

#define  ROW1_ON       	GPIOC->BSRR |= (1 <<  (8))
#define  ROW2_ON       	GPIOC->BSRR |= (1 <<  (6))
#define  ROW3_ON       	GPIOC->BSRR |= (1 <<  (5))
#define  ROW4_ON       	GPIOA->BSRR |= (1 <<  (12))

#define  COL1      		(GPIOA->IDR & (1 << 11))
#define  COL2      		(GPIOB->IDR & (1 << 12))
#define  COL3      		(GPIOB->IDR & (1 <<  2))
#define  COL4      		(GPIOB->IDR & (1 <<  1))

void keypad_init(void);
char keypad_read(void);
#endif
