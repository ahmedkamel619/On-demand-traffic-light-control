/*
 * interrupt.h
 *
 * Created: 2/11/2023 9:30:27 PM
 *  Author: A7mad
 */ 
#include "../../Utilities/registers.h"
#ifndef INTERRUPT_H_
#define INTERRUPT_H_

//Interrupt vectors
#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2

//Enable interrupts
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli()  __asm__ __volatile__ ("cli" ::: "memory") 

#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

#endif 