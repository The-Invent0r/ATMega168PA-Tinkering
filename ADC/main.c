#include<avr/io.h>
#include<util/delay.h>

static inline void initADC0(void){
	ADMUX |= (1 << REFS0);
	ADCSRA |= (1 << ADPS1) | (1 << ADPS0);
	ADCSRA |= (1 << ADEN);
}

int main(void){
	
	uint8_t ledValue;
	uint16_t adcValue;
	uint8_t i;
	
	initADC0();
	DDRB = 0xff;
	
	
	while(1){
		ADCSRA |= (1 << ADSC);
		loop_until_bit_is_clear(ADCSRA, ADSC);
		adcValue = ADC;
		
		ledValue = (adcValue >> 7);
		
		PORTB = 0;
		
		for(i = 0; i <= ledValue; i++){
			PORTB |= (1 << i);
		}
		_delay_ms(50);
	
	}
	
	return(0);
}