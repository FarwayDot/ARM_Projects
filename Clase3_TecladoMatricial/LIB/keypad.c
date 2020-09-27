#include "stm32f4xx_hal.h"
#include "keypad.h"

void keypad_init(void){
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
	RCC->AHB1ENR   |= (1<<2) | (1<<1) | (1<< 0);

	GPIOC->MODER   &= ~(1 << (2*(8) + 1));	//	C8
	GPIOC->MODER   |=  (1 <<  2*(8) );
	GPIOC->OTYPER  &= ~(1 <<    (8) );
	GPIOC->OSPEEDR |=  (1 << (2*(8) + 1) ) |  (1 <<  2*(8) );		//	01: 25 MHz Medium speed
	GPIOC->PUPDR   &= ~(1 << (2*(8) + 1) ) & ~(1 << (2*(8)) );

	GPIOC->MODER   &= ~(1 << (2*(6) + 1));	//	C6
	GPIOC->MODER   |=  (1 <<  2*(6) );
	GPIOC->OTYPER  &= ~(1 <<    (6) );
	GPIOC->OSPEEDR |=  (1 << (2*(6) + 1) ) |  (1 <<  2*(6) );		//	01: 25 MHz Medium speed
	GPIOC->PUPDR   &= ~(1 << (2*(6) + 1) ) & ~(1 << (2*(6)) );

	GPIOC->MODER   &= ~(1 << (2*(5) + 1));	//	C5
	GPIOC->MODER   |=  (1 <<  2*(5) );
	GPIOC->OTYPER  &= ~(1 <<    (5) );
	GPIOC->OSPEEDR |=  (1 << (2*(5) + 1) ) |  (1 <<  2*(5) );		//	01: 25 MHz Medium speed
	GPIOC->PUPDR   &= ~(1 << (2*(5) + 1) ) & ~(1 << (2*(5)) );
	
	GPIOA->MODER   &= ~(1 << (2*(12) + 1));	//	A12
	GPIOA->MODER   |=  (1 <<  2*(12) );
	GPIOA->OTYPER  &= ~(1 <<    (12) );
	GPIOA->OSPEEDR |=  (1 << (2*(12) + 1) ) |  (1 <<  2*(12) );		//	01: 25 MHz Medium speed
	GPIOA->PUPDR   &= ~(1 << (2*(12) + 1) ) & ~(1 << (2*(12)) );

	//	A11
	GPIOA->MODER &= ~(1 << (2*(11) + 1) ) & ~(1 << (2*(11)) );	//	00: Input (reset state)
	GPIOA->PUPDR |=  (1 << (2*(11)) );
	GPIOA->PUPDR &= ~(1 << (2*(11) + 1) );		//	00: No pull-up, pull-down
	//	B12
	GPIOB->MODER &= ~(1 << (2*(12) + 1) ) & ~(1 << (2*(12)) );	//	00: Input (reset state)
	GPIOB->PUPDR |=  (1 << (2*(12)) );
	GPIOB->PUPDR &= ~(1 << (2*(12) + 1) );		//	00: No pull-up, pull-down
	//	B2
	GPIOB->MODER &= ~(1 << (2*( 2) + 1) ) & ~(1 << (2*( 2)) );	//	00: Input (reset state)
	GPIOB->PUPDR |=  (1 << (2*( 2)) );
	GPIOB->PUPDR &= ~(1 << (2*( 2) + 1) );		//	00: No pull-up, pull-down
	//	B1
	GPIOB->MODER &= ~(1 << (2*( 1) + 1) ) & ~(1 << (2*( 1)) );	//	00: Input (reset state)
	GPIOB->PUPDR |=  (1 << (2*( 1)) );
	GPIOB->PUPDR &= ~(1 << (2*( 1) + 1) );		//	00: No pull-up, pull-down

	GPIOC->BSRR |= (1 << ( ( 8) + 16 ));		//	RESET
	GPIOC->BSRR |= (1 << ( ( 6) + 16 ));
	GPIOC->BSRR |= (1 << ( ( 5) + 16 ));
	GPIOA->BSRR |= (1 << ( (12) + 16 ));

}

char keypad_read(void){
	char letras[4][4]={	{'1','2','3','A'},
						{'4','5','6','B'},
						{'7','8','9','C'},
						{'*','0','#','D'}};
	int  i=0;
	char valor=0;

	for(i=0;i<4;i++){
		if(i==0){
			ROW2_ON;
			ROW3_ON;
			ROW4_ON;
			ROW1_OFF;
			HAL_Delay(10);
			while ( !COL1 ){valor=letras[0][0];}	//1
			while ( !COL2 ){valor=letras[0][1];}	//2
			while ( !COL3 ){valor=letras[0][2];}	//3
			while ( !COL4 ){valor=letras[0][3];}	//A
		}
		if(i==1){
			ROW1_ON;
			ROW3_ON;
			ROW4_ON;
			ROW2_OFF;
			HAL_Delay(10);
			while ( !COL1 ){valor=letras[1][0];}	//4
			while ( !COL2 ){valor=letras[1][1];}	//5
			while ( !COL3 ){valor=letras[1][2];}	//6
			while ( !COL4 ){valor=letras[1][3];}	//B
		}
		if(i==2){
			ROW1_ON;
			ROW2_ON;
			ROW4_ON;
			ROW3_OFF;
			HAL_Delay(10);
			while ( !COL1 ){valor=letras[2][0];}	//7
			while ( !COL2 ){valor=letras[2][1];}	//8
			while ( !COL3 ){valor=letras[2][2];}	//9
			while ( !COL4 ){valor=letras[2][3];}	//C
		}
		if(i==3){
			ROW1_ON;
			ROW2_ON;
			ROW3_ON;
			ROW4_OFF;
			HAL_Delay(10);
			while ( !COL1 ){valor=letras[3][0];}	//*
			while ( !COL2 ){valor=letras[3][1];}	//0
			while ( !COL3 ){valor=letras[3][2];}	//+
			while ( !COL4 ){valor=letras[3][3];}	//D
		}
	}
	
	return valor;
}



