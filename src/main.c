/**
 * 
 * @file    dice.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-03-25 17:08:57
 * @edited  2015-04-13 09:56:01
 */

#define F_CPU 16000000
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#include "defs.h"
#include "config.h"
#include "myModules.h"

/******************************************************************************/
/* Global Variable Declaration                                        	      */
/******************************************************************************/


/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
void power_down(void){
    //set sleep mode to power-down
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);

    //enable sleep, go to sleep, disable sleep
    sleep_mode();
}

int main(void){
    typedef enum { 
        READY,
        SLEEP,
        USER_INPUT,
        ROLL1,
        ROLL2,
        ROLLING
    } EDiceState;

    //variable declarations
    EDiceState dice_state;
    unsigned int num_faces = 0;
    unsigned char face0 = BLANK;
    unsigned char face1 = BLANK;

    //setup
    tmr_init();
    intr_init();
    piezo_init();
    led_init();
    dice_state = READY;

    //enable interrupts
    sei();

    while(1){      
        switch (dice_state){
            case READY:
                //check for input
                if (piezo_get_state() == TAP){
                    piezo_tap_time = 0;
                    dice_state = ROLL1;
                }else if (roll_time > DICE_TIMEOUT){
                    dice_state = SLEEP;
                }else{
                    //display current roll
                    switch (num_faces){
                        case 1:
                            led_state = face0;
                            break;
                        case 2:
                            //display two faces
                            if (face_time > (DUAL_FACE_TIME<<1)){
                                face_time = 0;
                            }
                            if (face_time < DUAL_FACE_TIME){
                                led_state = face0;
                            }else{
                                led_state = face1;
                            }

                            break;
                    }
                }
                break;
            case SLEEP:
                //put dice to sleep
                led_state = BLANK;
                //TODO power_down();
                dice_state = READY;
                break;
            case ROLL1:
                //roll 1 dice
                num_faces = 1;
                face0 = led_rand_face();
                roll_time = 0;
                face_time = 0;
                dice_state = ROLLING;
                break;
            case ROLL2:
                //roll 2 dice
                num_faces = 2;
                face0 = led_rand_face();
                face1 = led_rand_face();
                roll_time = 0;
                face_time = 0;
                dice_state = ROLLING;
                break;
            case ROLLING:
                if ((piezo_get_state() == TAP) && (piezo_tap_time < DOUBLE_TAP_INTERVAL)){
                    intr_disable_piezo();
                    dice_state = ROLL2;
                }else if (roll_time > ROLL_TIME){
                    intr_enable_piezo();
                    dice_state = READY;
                }else if (face_time >= FACE_TIME){
                    led_state = led_rand_face();
                    face_time = 0;
                }
                break;
        }
    }
}
