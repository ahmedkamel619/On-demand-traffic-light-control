/*
 * timer.h
 *
 * Created: 2/11/2023 2:43:40 PM
 *  Author: A7mad
 */ 

#include "../../Utilities/registers.h"
#ifndef TIMER_H_
#define TIMER_H_




void TIMER_mode();
void TIMER_delay(uint16_t delaytime); // delaytime here takes time in milli seconds , uint16 as we need 5 seconds delay which is 5000 milli seconds

#endif 