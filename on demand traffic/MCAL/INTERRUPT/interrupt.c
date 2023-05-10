/*
 * interrupt.c
 *
 * Created: 3/1/2023 2:27:58 PM
 *  Author: A7mad
 */ 
#include "interrupt.h"

void strt_interrupt(void){
	sei();
	MCUCR |= (1<<0)|(1<<1);
	GICR  |= (1<<6);                 // Enable external interrupt pin INT0
}