/*
 * registers.h
 *
 * Created: 2/9/2023 2:56:08 PM
 *  Author: A7mad
 */ 

#ifndef REGISTERS_H_
#define REGISTERS_H_

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
//typedef unsigned int uint32_t;


// here we are defining pins
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


//****************************
// DIO registers definition
//PortA registers
#define PORTA (*(volatile uint8_t*)(0x3B))
#define DDRA (*(volatile uint8_t*)(0x3A))
#define PINA (*(volatile uint8_t*)(0x39))
//PortB registers
#define PORTB (*(volatile uint8_t*)(0x38))
#define DDRB (*(volatile uint8_t*)(0x37))
#define PINB (*(volatile uint8_t*)(0x36))
//PortC registers
#define PORTC (*(volatile uint8_t*)(0x35))
#define DDRC (*(volatile uint8_t*)(0x34))
#define PINC (*(volatile uint8_t*)(0x33))
//PortD registers
#define PORTD (*(volatile uint8_t*)(0x32))
#define DDRD (*(volatile uint8_t*)(0x31))
#define PIND (*(volatile uint8_t*)(0x30))
//---------------------\\

//---------------------\\
// Timer0 registers definition 
#define TCCR0 (*(volatile uint8_t*)(0x53))
#define TCNT0 (*(volatile uint8_t*)(0x52))
#define TIFR (*(volatile uint8_t*)(0x58))
#define TIMSK (*(volatile uint8_t*)(0x59))
//---------------------\\



//---------------------\\
// Interrupt registers definition
#define GICR (*(volatile uint8_t*)(0x5B))
#define MCUCR (*(volatile uint8_t*)(0x55))


#endif