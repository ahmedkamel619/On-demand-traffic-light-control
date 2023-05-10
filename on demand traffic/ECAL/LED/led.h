/*
 * led.h
 *
 * Created: 2/10/2023 10:53:37 AM
 *  Author: A7mad
 */ 
#include "../../MCAL/DIO/dio.h" 
#include "../../MCAL/TIMERS/timer.h"
#ifndef LED_H_
#define LED_H_


void LED_init(uint8_t ledPort,uint8_t ledPin);
void LED_on(uint8_t ledPort,uint8_t ledPin);
void LED_off(uint8_t ledPort,uint8_t ledPin);
void LED_toggle(uint8_t ledPort,uint8_t ledPin);

#endif