/*
 * on demand traffic.c
 *
 * Created: 2/9/2023 2:39:22 PM
 * Author : A7mad
 */ 


#include "APP/app.h"

int main(void)
{
APP_init();
while(1){

APP_start();
}

/*
// test for timer 
TIMER_mode();
TIMER_start(5000);

// test for dio drivers
DIO_init(PORT_A,0,IN);

DIO_init(PORT_A,0,OUT);

DIO_write(PORT_A,0,LOW);
DIO_write(PORT_A,0,HIGH);
int i1 =0;

while(i1<2){
	DIO_toggle(PORT_A,0);
	i1++ ;
}
DIO_write(PORT_A,0,LOW);

// test for LED 
LED_init(PORT_A,0);
LED_off(PORT_A,0);
LED_on(PORT_A,0);
*/
    
}

