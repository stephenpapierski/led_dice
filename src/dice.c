/**
 * 
 * @file    dice.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-03-25 17:08:57
 * @edited  2015-04- 7 16:41:08
 */

#define F_CPU 16000000
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "defs.h"
#include "myModules.h"

/******************************************************************************/
/* Variable Declaration                                              	      */
/******************************************************************************/

unsigned char led_state;

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

int main(void){
    //setup
    tmr_init();
    intr_init();
    piezo_init();

    //enable interrupts
    sei();
    while(1){      
        led_update(); //update current led
        if (roll_flag && (roll_time < 2000)){
            led_state = led_rand_face();
        }else{
            led_state = BLANK;
            roll_flag = 0;
        }
    }
}


