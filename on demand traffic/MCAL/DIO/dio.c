/*
 * dio.c
 *
 * Created: 2/9/2023 8:03:55 PM
 *  Author: A7mad
 */ 

#include "dio.h"

void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t stat)
{
	switch (portNumber)
	{
	case PORT_A:
		if(stat==IN){
			DDRA &= ~(1<<pinNumber);
		}
		else if(stat==OUT){
			DDRA |= (1<<pinNumber);
		}
		break;
	case PORT_B:
		if(stat==IN){
			DDRB &= ~(1<<pinNumber);
		}
		else if(stat==OUT){
			DDRB |= (1<<pinNumber);
		}
		break;
	case PORT_C:
		if(stat==IN){
			DDRC &= ~(1<<pinNumber);
		}
		else if(stat==OUT){
			DDRC |= (1<<pinNumber);
		}
		break;	
	case PORT_D:
	     if(stat==IN){
		     DDRD &= ~(1<<pinNumber);
	     }
	     else if(stat==OUT){
		     DDRD |= (1<<pinNumber);
	     }
	     break;
	}
}

void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value){
	switch (portNumber)
	{
		case PORT_A:
		if(value==LOW){
			PORTA &= ~(1<<pinNumber);
		}
		else if(value==HIGH){
			PORTA |= (1<<pinNumber);
		}
		break;
		case PORT_B:
		if(value==LOW){
			PORTB &= ~(1<<pinNumber);
		}
		else if(value==HIGH){
			PORTB |= (1<<pinNumber);
		}
		break;
		case PORT_C:
		if(value==LOW){
			PORTC &= ~(1<<pinNumber);
		}
		else if(value==HIGH){
			PORTC |= (1<<pinNumber);
		}
		break;
		case PORT_D:
		if(value==LOW){
			PORTD &= ~(1<<pinNumber);
		}
		else if(value==HIGH){
			PORTD |= (1<<pinNumber);
		}
		break;
	}


}

void DIO_toggle(uint8_t portNumber, uint8_t pinNumber)
{
	switch(portNumber){
		case PORT_A:
		PORTA ^= (1<<pinNumber);
		break;
		case PORT_B:
		PORTB ^= (1<<pinNumber);
		break;
		case PORT_C:
		PORTC ^= (1<<pinNumber);
		break;
		case PORT_D:
		PORTD ^= (1<<pinNumber);
		break;
	}
}

void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value)
{
	switch(portNumber){
		case PORT_A:
			*value = ((PINA&(1<<pinNumber))>>pinNumber);
			
		break;
		case PORT_B:
			*value = ((PINB&(1<<pinNumber))>>pinNumber);
			
		break;
		case PORT_C:
			*value = ((PINC&(1<<pinNumber))>>pinNumber);
			
		break;
		case PORT_D:
			*value = ((PIND&(1<<pinNumber))>>pinNumber);
			
		break;
	}
}