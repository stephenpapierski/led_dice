/**
 * 
 * @file    intr.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04- 3 23:55:41
 * @edited  2015-04- 7 16:43:36
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include "../myModules.h"
#include "intr.h"

//index of led being lit for charlie plexing
volatile unsigned int led_index;
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
 * Timer0 Overflow Interrupt, Timer0 set to Normal mode
 */
ISR(TIMER0_OVF_vect){
    (led_index >= (NUM_LEDS - 1))? led_index = 0 : led_index++;

    //increment counters
    roll_time++;
    face_time++;
    piezo_time++;
}

/**
 * External PIEZO interrupt
 */
ISR(INT0_vect){
    roll_flag = 1;
    roll_time = 0;
    face_time = 0;
}
