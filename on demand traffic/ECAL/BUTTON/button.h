/*
 * button.h
 *
 * Created: 2/10/2023 3:16:01 PM
 *  Author: A7mad
 */ 
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/INTERRUPT/interrupt.h"

#ifndef BUTTON_H_
#define BUTTON_H_

void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin);
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value);


#endif