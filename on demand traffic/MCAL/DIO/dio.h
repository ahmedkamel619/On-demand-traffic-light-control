/*
 * dio.h
 *
 * Created: 2/9/2023 8:04:08 PM
 *  Author: A7mad
 */ 
#include "../../Utilities/registers.h"

#ifndef DIO_H_
#define DIO_H_

//---------------------\\
// define macros for ports A,B,C and D
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
//---------------------\\

//---------------------\\
//stat defines
#define IN 0
#define OUT 1
//---------------------\\

//---------------------\\
//value defines
#define LOW 0
#define HIGH 1
//---------------------\\

//---------------------\\
// functions Prototypes 
void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t stat);// Initialize dio stat( stat is input or output)
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value); //write data to dio
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber); //toggle dio
void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value); //read dio


#endif 