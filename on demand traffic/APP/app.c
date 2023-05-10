/*
 * app.c
 *
 * Created: 2/11/2023 5:47:31 PM
 *  Author: A7mad
 */ 
#include "app.h"






uint8_t buttonstate; // button state after button is pressed 1=pressed 0=not pressed
uint8_t traffic_car_mode = 0;  // mode for traffic 2=red 1=yellow 0=green
int i1=500;
void APP_init(void){
LED_init(PORT_A,0); // green lamp
LED_init(PORT_A,1); // yellow lamp
LED_init(PORT_A,2); // red lamp
LED_off(PORT_A,0); 
LED_off(PORT_A,1); 
LED_off(PORT_A,2); 

BUTTON_init(PORT_D,2); // Pedestrian Button

LED_init(PORT_B,0); //  Pedestrian green lamp
LED_init(PORT_B,1); //  Pedestrian yellow lamp
LED_init(PORT_B,2); //  Pedestrian red lamp
LED_off(PORT_B,0); 
LED_off(PORT_B,1); 
LED_off(PORT_B,2); 

strt_interrupt();
//sei();
//MCUCR |= (1<<0)|(1<<1);
//GICR  |= (1<<6);                 // Enable external interrupt pin INT0




}  

void APP_start(void){
 switch(traffic_car_mode){
     case 0:                      
            LED_on(PORT_A,0);                  // Traffic  green Lamp is ON for 5 Seconds
            LED_on(PORT_B,2);                 //  Pedestrian red lamp   is On
            LED_off(PORT_B,0);               //  Pedestrian green lamp is OFF
            LED_off(PORT_A,1);
            LED_off(PORT_A,2);
            TIMER_mode();
            TIMER_start(5000);
            traffic_car_mode=1;
             break;
     case 1 :
             LED_off(PORT_A,0);
             LED_off(PORT_A,2);
             LED_on(PORT_B,2);                 //  Pedestrian red lamp   is On
             LED_off(PORT_B,0);               //  Pedestrian green lamp is OFF
            while(i1<=5000){
	            LED_toggle(PORT_A,1);        // Traffic  yellow Lamp is blinking on for 5 Seconds
	           TIMER_mode();
	            TIMER_start(i1);
	           i1 =i1+2000;
             }
            i1=1000;
            traffic_car_mode=2; 
             break;
     case  2: 
             traffic_car_mode=3;  // made for  ( USER STORY 3)
             LED_off(PORT_A,1);
             LED_off(PORT_A,0);
             LED_on(PORT_A,2);                // Traffic  red Lamp is ON for 5 Seconds
             LED_off(PORT_B,2);              //  Pedestrian red lamp   is OFF
             LED_on(PORT_B,0);               //  Pedestrian green lamp is ON
             
            TIMER_mode();
             TIMER_start(5000);
              LED_on(PORT_B,2);              //  Pedestrian red lamp   is ON
              LED_off(PORT_B,0);               //  Pedestrian green lamp is OFF
              LED_off(PORT_A,2);                // Traffic  red Lamp is OFF
              while(i1<=5000){
	              LED_toggle(PORT_A,1);        // Traffic  yellow Lamp is blinking on for 5 Seconds
	             TIMER_mode();
	              TIMER_start(i1);
	              i1 =i1+500;
              }
              i1=500;
              traffic_car_mode=0;
                break;
                
}
}
	
ISR(EXT_INT_0){
 handle_button(); 
}	  
	 
 void handle_button(){
if(traffic_car_mode==0){ // button is pressed when traffic lamp Green is ON   ( USER STORY 1)
	 // 1. Pedestrian red lamp   is ON 
	LED_on(PORT_B,2);                 //  Pedestrian red lamp   is ON
	// 2.  both yellow lamps blink for 5 seconds 
	while(i1<=5000){
		LED_toggle(PORT_A,1);
		LED_toggle(PORT_B,1);
		TIMER_mode();
		TIMER_start(i1);
		i1 =i1+500;
	}
	i1=500;
	
	//3. Traffic red lamp is ON and pedestrian green is  ON for 5 seconds 
	LED_on(PORT_A,2);                  // Traffic red Lamp is ON
	LED_off(PORT_A,0);                // Traffic green Lamp is OFF
	LED_on(PORT_B,0);                // pedestrian green Lamp is ON
	LED_off(PORT_B,2);              // pedestrian red Lamp is OFF
	TIMER_mode();
	TIMER_start(5000);
	
	
	
	
	// 4. Traffic  green Lamp is still OFF , Traffic  red Lamp is still ON  and  both yellow led blink for 5 seconds and pedestrian green still on    CF
	LED_off(PORT_A,0);                  // Traffic  green Lamp is OFF
	LED_on(PORT_A,2);                  // Traffic red Lamp is ON
	LED_on(PORT_B,0);                // pedestrian green Lamp is ON
	LED_off(PORT_B,2);              // pedestrian red Lamp is OFF
	while(i1<=5000){
		LED_toggle(PORT_A,1);        // Traffic  yellow Lamp is blinking  and Pedestrian yellow lamp is bliking on for 5 Seconds
		LED_toggle(PORT_B,1);
		TIMER_mode();
		TIMER_start(i1);
		i1 =i1+500;
	}
	
	// 5. pedestrian green lamp OFF and  pedestrian red lamp  ON and cars green on for 5 seconds    CF
	LED_off(PORT_B,0);                     //  Pedestrian green lamp is OFF
	LED_on(PORT_B,2);                     //  Pedestrian red lamp   is ON
	LED_on(PORT_A,0);                    // Traffic  green Lamp is ON
	LED_off(PORT_A,2);                  // Traffic red Lamp is OFF
	TIMER_mode();
	TIMER_start(5000);
	
	// 6. cars led on and back to normal mode & pedestrian red is still on
	
//	traffic_car_mode =0; 

}
if(traffic_car_mode==1){  // button is pressed when traffic lamp yellow is ON   ( USER STORY 2)
	
	// 1.  both yellow lamps blink for 5 seconds
	while(i1<=5000){
	LED_toggle(PORT_A,1);
	LED_toggle(PORT_B,1);
		TIMER_mode();
	TIMER_start(i1);
	i1 =i1+500;
	}
	i1=500;
	
	//2. Traffic red lamp is ON and pedestrian green is  ON for 5 seconds
	LED_on(PORT_A,2);                  // Traffic red Lamp is ON
	LED_off(PORT_A,0);                // Traffic green Lamp is OFF
	LED_on(PORT_B,0);                // pedestrian green Lamp is ON
	LED_off(PORT_B,2);              // pedestrian red Lamp is OFF
	TIMER_mode();
	TIMER_start(5000);
	
	// 3. Traffic  green Lamp is OFF and  both yellow led blink for 5 seconds and pedestrian red still on  and    CF
	LED_off(PORT_A,0);                  // Traffic  green Lamp is OFF
	LED_on(PORT_A,2);                  // Traffic red Lamp is ON
	LED_off(PORT_B,2);                // pedestrian red Lamp is OFF
	LED_on(PORT_B,0);                 //  Pedestrian green lamp is still ON
	while(i1<=5000){
		LED_toggle(PORT_A,1);        // Traffic  yellow Lamp is blinking  and Pedestrian yellow lamp is bliking on for 5 Seconds
		LED_toggle(PORT_B,1);
		TIMER_mode();
		TIMER_start(i1);
		i1 =i1+500;
	}
	
	// 4. pedestrian green lamp OFF and  pedestrian red lamp  ON and cars green on for 5 seconds    CF
	LED_off(PORT_B,0);                     //  Pedestrian green lamp is OFF
	LED_on(PORT_B,2);                     //  Pedestrian red lamp   is ON
	LED_on(PORT_A,0);                    // Traffic  green Lamp is ON
	LED_off(PORT_A,2);                  // Traffic red Lamp is OFF
	TIMER_mode();
	TIMER_start(5000);
	
	// 5. pedestrian green lamp OFF and  pedestrian red lamp  ON and cars green off  and traffic yellow lamp blinks
	LED_off(PORT_B,0);                     //  Pedestrian green lamp is OFF
	LED_on(PORT_B,2);                     //  Pedestrian red lamp   is ON
	LED_off(PORT_A,0);                    // Traffic  green Lamp is ON
	while(i1<=5000){
		LED_toggle(PORT_A,1);        
		
		TIMER_mode();
		TIMER_start(i1);
		i1 =i1+500;
	}
	i1=500;
	
	traffic_car_mode =0; 
} 
}
 
/*
if(traffic_car_mode==2){  // button is pressed when traffic lamp red is ON

   // 1. Traffic red lamp is ON and pedestrian green is  ON for 5 seconds
   LED_on(PORT_A,2);                        // Traffic red Lamp is ON
   LED_off(PORT_A,0);                      // Traffic  green Lamp is OFF
   LED_on(PORT_B,0);                      // pedestrian green Lamp is ON
   LED_off(PORT_B,2);                     //  Pedestrian red lamp   is Off
   TIMER_mode();
   TIMER_start(5000);

  // 2. Traffic red lamp is OFF & both yellow lamps blink for 5 seconds and pedestrian green still on
  
   LED_off(PORT_A,2);                       // Traffic red Lamp is OFF
   LED_on(PORT_B,0);                       // pedestrian green Lamp is   Still  ON
   LED_off(PORT_B,2);                     //  Pedestrian red lamp   is Off
   while(i1<=5000){
	   LED_toggle(PORT_A,1);        
       LED_toggle(PORT_B,1);
	   TIMER_mode();
	   TIMER_start(i1);
	   i1 =i1+500;
   }

   // 3. pedestrian green lamp OFF and  pedestrian red lamp  ON and cars green on for 5 seconds    CF
   LED_off(PORT_B,0);                          //  Pedestrian green lamp is OFF
   LED_on(PORT_B,2);                          //  Pedestrian red lamp   is ON 
   LED_on(PORT_A,0);                         // Traffic  green Lamp is ON 
   LED_off(PORT_A,2);                       // Traffic red Lamp is OFF
   TIMER_mode();
   TIMER_start(5000);   
  
   // 4. Traffic  green Lamp is OFF and  both yellow led blink for 5 seconds and pedestrian red still on    CF
   LED_off(PORT_A,0);                // Traffic  green Lamp is OFF
   LED_on(PORT_B,2);                 //  Pedestrian red lamp is still ON 
   while(i1<=5000){
	   LED_toggle(PORT_A,1);        // Traffic  yellow Lamp is blinking  and Pedestrian yellow lamp is bliking on for 5 Seconds
	   LED_toggle(PORT_B,1);
	   TIMER_mode();
	   TIMER_start(i1);
	   i1 =i1+500;
   }
   
   // 5. cars led on and back to normal mode & pedestrian red is still on
   
   traffic_car_mode =0;   
} 


}	  
	 
*/
 
