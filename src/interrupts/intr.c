/**
 * 
 * @file    intr.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04- 3 23:55:41
 * @edited  2015-04-11 22:43:47
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include "../myModules.h"
#include "intr.h"

//index of led being lit for charlie plexing
//volatile unsigned int led_index;
//set when the dice is "rolling"
volatile unsigned short roll_flag;
//how long the dice has been "rolling"
unsigned long int roll_time;
//how long current face has been displayed
unsigned long int face_time;

/**
 * Initialize interrupts
 */
void intr_init(void){
    MCUCR |= 0x02; //sets Interrupt0 to trigger on falling edge
    GIMSK |= 1<<INT0;//0x40; //external interupt request enable
}

/**
 * Timer0 Compare A Interrupt, Timer0 set to CTC, Triggers every 1 ms
 */
ISR(TIMER0_COMPA_vect){
    led_charlieplex_index();
    led_update();

    //increment counters
    roll_time++;
    face_time++;
    piezo_time++;
}

/**
 * Timer0 Compare B Interrupt
 */
//ISR(TIMER0_COMPB_vect){
//    //do nothing
//}

/**
 * External PIEZO interrupt
 */
ISR(INT0_vect){
    //roll_flag = 1;
    piezo_interrupt = 1;
    roll_time = 0;
    face_time = 0;
    //led_state = led_rand_face();
}
