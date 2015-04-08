/**
 * 
 * @file    dice.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-03-25 17:08:57
 * @edited  2015-04- 8 01:28:24
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

typedef enum { READY        =   0,
               SLEEP        =   1,
               USER_INPUT   =   2,
               ROLL1        =   3,
               ROLL2        =   4
} EDiceState;

//unsigned char led_state;
EDiceState dice_state;

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

int main(void){
    //setup
    tmr_init();
    intr_init();
    piezo_init();
    dice_state = READY;

    //enable interrupts
    sei();
    while(1){      
        led_update(); //update current led
        led_state = TWO;
        //led_state = led_rand_face();
        //if (roll_flag){
        //    //led_state = led_rand_face();
        //    roll_flag = 0;
        //}
        //if (roll_flag && (roll_time < 2000)){
        //    led_state = led_rand_face();
        //}else{
        //    led_state = BLANK;
        //    roll_flag = 0;
        //}
        //switch (dice_state){
        //    case READY:
        //        //dice is ready for input
        //        //if piezo state == tap
        //        //  dice_state = USER_INPUT
        //        //  timer = 0
        //        break;
        //    case SLEEP:
        //        //put dice to sleep
        //        break;
        //    case USER_INPUT:
        //        //device is receiving user input
        //        //if dice_state == tap
        //        //  dice_state = ROLL2
        //        //else if timer > timeout
        //        //  dice_state = ROLL1
        //        break;
        //    case ROLL1:
        //        //roll 1 dice
        //        break;
        //    case ROLL2:
        //        //roll 2 dice
        //        break;
        //}
    }
}
