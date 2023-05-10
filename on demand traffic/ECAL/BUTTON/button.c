/*
 * button.c
 *
 * Created: 2/10/2023 3:14:58 PM
 *  Author: A7mad
 */ 
#include "button.h"


void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin){
	DIO_init(buttonPort,buttonPin,IN);
}


void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value){
	DIO_read(buttonPort,buttonPin,value);
}