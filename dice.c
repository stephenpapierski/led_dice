/**
 * @file    dice.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    28 February 2015
 * @version 0.1
 */

#define F_CPU 16000000
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "dice.h"

int main(void){
    TCCR0B = 0x01; //sets Timer0 to Normal mode @ 16MHz
    TIMSK = 0x02; //enables Timer0 Overflow Interrupt Enable

    MCUCR |= 0x02; //sets Interrupt0 to trigger on falling edge
    GIMSK |= 0x40; //external interupt request enable

    LINE_DDR &= ~(PIEZO); //configure PIEZO pin as input
    LINE_PORT |= PIEZO; //enable pull up resistor for PIEZO pin;
    sei();
    while(1){
        set_led(); //update current led
        if (roll_flag && roll_time < 2000){
            led_state = rand_face();
            roll_time++;
        }else{
            led_state = 0x00;
            roll_flag = 0;
        }
    }
}

/**
 * Turns off the current LED and turns on the one specified by led_index
 */
void set_led(){
    cli(); //disable interrupts (messes with led states)
    LINE_PORT = 0x00; //turn off current leds
    LINE_DDR = 0x00; //set all pins as inputs
    if (led_state & led_mask[led_index]){
        LINE_DDR |= led_ddr[led_index]; //set led ddr
        LINE_PORT |= led_port[led_index]; //set led port
    }
    sei(); //enable interrupts
}

/**
 * rand face
 */
unsigned char rand_face(){
    int face = rand();
    return led_faces[face];
}

/**
 * Timer0 Overflow Interrupt, Timer0 set to Normal mode
 */
ISR(TIMER0_OVF_vect){
    (led_index >= (NUM_LEDS - 1))? led_index = 0 : led_index++;
}

/**
 * External PIEZO interrupt
 */
ISR(INT0_vect){
    roll_flag = 1;
    roll_time = 0;
    face_time = 0;
}
