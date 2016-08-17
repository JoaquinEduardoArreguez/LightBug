#include <avr/io.h>
#include "LightBug.h"
#define F_CPU 8000000UL
#include <util/delay.h>


struct LightBug bicho;

void LightBug_setPines(uint8_t r, uint8_t g, uint8_t b){
	bicho._pinRed 	= r;
	bicho._pinGreen = g;
	bicho._pinBlue 	= b;

	// Pines como OUTPUT LOW
	PORTB	=	0b00000000;
	DDRB	=	(1 << bicho._pinRed) | (1 << bicho._pinGreen) | (1 << bicho._pinBlue);
}

void LightBug_red(){PINB = (1 << bicho._pinRed);}
void LightBug_green(){PINB = (1 << bicho._pinGreen);}
void LightBug_blue(){PINB = (1 << bicho._pinBlue);}

volatile uint8_t cont;

void Delay_ms(int n) {
  while (n--) {
   _delay_ms(1);
 }
}

int main(void){
	
	LightBug_setPines(PB0,PB1,PB2);
	
	cont = 0;

	while(1){
		LightBug_red();
		Delay_ms(cont);		
		LightBug_green();
		Delay_ms(cont);
		LightBug_blue();
		Delay_ms(cont);

		LightBug_red();
		Delay_ms(cont);
		LightBug_green();
		Delay_ms(cont);
		LightBug_blue();
		Delay_ms(cont);
		
		cont++;
		
		if (cont == 550) { cont = 0;}

	}

	

}
