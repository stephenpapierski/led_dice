/**
 * Interrupt handlers and utilities
 * @file    intr.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04- 3 23:55:41
 * @edited  2015-04-18 01:38:07
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include "../myModules.h"
#include "intr.h"

/******************************************************************************/
/* Library Functions                                                          */
/******************************************************************************/

void intr_init(void){
    //by default int0 set to low-level interrupt
    GIMSK |= 1<<INT0; //external interrupt request enable
}

void intr_disable_piezo(void){
    GIMSK &= ~(1<<INT0); //external interupt request disable 
    piezo_interrupt_flag(0);
}

void intr_enable_piezo(void){
    GIMSK |= 1<<INT0; //external interupt request enable
    piezo_interrupt_flag(0);
}

/******************************************************************************/
/* Interrupt Handlers                                                         */
/******************************************************************************/

/**
 * Timer0 Compare A Interrupt, Timer0 set to CTC, Triggers every 1 ms
 */
ISR(TIMER0_COMPA_vect){
    //increment led index
    led_charlieplex_index();
    //charlieplex set led
    led_update();

    //increment counters
    roll_time++;
    face_time++;
    piezo_time++;
    piezo_tap_time++;
}

/**
 * External PIEZO interrupt
 */
ISR(INT0_vect){
    piezo_interrupt_flag(1);
}
