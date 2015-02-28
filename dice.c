/**
 * @file    dice.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    27 February 2015
 * @version 0.1
 */

#define F_CPU 16000000
#include <avr/io.h>
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
        reset_led_ddr();
        reset_led_port();
        LINE_DDR |= led_ddr[led_index];
        LINE_PORT |= led_port[led_index];
        //_delay_ms(100);

        //reset_ddr();
        //set_ddr(led_state);
        //
        //LINE_PORT |= LINE0;
    }
}

void reset_led_ddr(){
    LINE_DDR &= ~(LINE0 | LINE1 | LINE2 | LINE3);
}

void reset_led_port(){
    LINE_PORT &= ~(LINE0 | LINE1 | LINE2 | LINE3);
}

ISR(TIMER0_OVF_vect){
    //cli();
    //LINE_PORT ^= LINE0;
    //_delay_ms(100);
    //sei();
}

ISR(INT0_vect){
    //do stuff
    (led_index >= (NUM_LEDS - 1))? led_index = 0 : led_index++;
    //roll_flag = 1;
}
