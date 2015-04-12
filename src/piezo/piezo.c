/**
 * 
 * @file    piezo.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04- 4 00:17:13
 * @edited  2015-04-12 01:29:17
 */

#include <avr/interrupt.h>

#include "../defs.h"
#include "piezo.h"

EPiezoState state_piezo;
//time since piezo triggered interrupt
volatile unsigned int piezo_time;
//has the piezo triggered an interrupt?
volatile unsigned int piezo_interrupt;
//time since piezo has been in tap state
volatile unsigned int piezo_tap_time;

void piezo_init(void){
    PIEZO_DDR &= ~(PIEZO_P); //configure PIEZO pin as input
    PIEZO_PORT |= PIEZO_P; //enable pull up resistor for PIEZO pin
    state_piezo = IDLE;
}

/**
 * Debounce the state of the piezo
 * @return piezo state
 */
EPiezoState piezo_get_state(void){
    switch (state_piezo){
        case IDLE:
            if (piezo_interrupt){
                state_piezo = TAP;
                piezo_interrupt = 0;
            }
            break;
        case TAP:
            piezo_time = 0;
            state_piezo = ACTIVE;
            break;
        case ACTIVE:
            //ignore additional interrupts
            piezo_interrupt = 0;
            if (piezo_time >= PIEZO_TIMEOUT){
                state_piezo = IDLE;
            }
            break;
    }
    return state_piezo;
}
