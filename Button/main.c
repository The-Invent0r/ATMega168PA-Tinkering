#include<avr/io.h>
#include<util/delay.h>

int main(void){
	
	DDRD = 0x00;	//set data direction register for bank D as input
	PORTD = 0xff;	//enable all pull-up resistors on bank D
	DDRB = 0xff;	//Set data direction register for bank B as output
	
	while(1){
		
		if((PIND & (1 << PD2)) == 0){
			PORTB = 0b01010101;		// set the output pattern for bank B when button is pressed
		}
		
		else{
			PORTB &= ~(0b01010101);	//set the output pattern for bank B when button is not pressed.
		}
		
	}
	
	return(0);
}