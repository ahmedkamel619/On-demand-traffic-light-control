/*
 * timer.c
 *
 * Created: 2/11/2023 2:43:30 PM
 *  Author: A7mad
 */ 
#include "timer.h"
#include <math.h>
void TIMER_mode(){
	TCCR0 = 00000000; //normal mode
}

void TIMER_start(uint16_t delaytime){
double timemaxdelay;
double timetick;
uint16_t timeintial;
uint16_t overflownum; // max delay case
uint16_t overflowreg=0; // check with it 
timetick=256.0/1000.0 ;     
timemaxdelay=65.536 ;

if(delaytime<timemaxdelay){  //  delay time below max time delay with any pre scalar
 timeintial= (timemaxdelay-delaytime)/timetick;
 overflownum=1;
}
else if(delaytime==timemaxdelay){        //  delay time equal max time delay with any pre scalar
	timeintial= 0;
    overflownum=1;
}
else if(delaytime>timemaxdelay){                                        //  delay time equal > time delay
overflownum = ceil((double)delaytime/timemaxdelay);
timeintial = 256 - (((double)delaytime/timetick)/overflownum);
}

TCNT0 = timeintial;
TCCR0 |= (1<<2) ;
while(overflowreg<overflownum){
	while( (TIFR&(1<<0))==0 );  // busy wait
	TIFR|=(1<<0);
	overflowreg++;
}

TCCR0 = 0x00;
}