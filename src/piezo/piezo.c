/**
 * 
 * @file    piezo.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04- 4 00:17:13
 * @edited  2015-04-11 22:12:08
 */

#include "../defs.h"
#include "piezo.h"

EPiezoState state_piezo;
volatile unsigned int piezo_time;
volatile unsigned int piezo_interrupt;

void piezo_init(void){
    PIEZO_DDR &= ~(PIEZO_P); //configure PIEZO pin as input
    PIEZO_PORT |= PIEZO_P; //enable pull up resistor for PIEZO pin
    state_piezo = IDLE;
}

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
            if (piezo_time >= PIEZO_TIMEOUT){
                state_piezo = IDLE;
            }
            break;
    }
    //if (PIEZO_LOW){
    //    if (state_piezo == IDLE){
    //        state_piezo = TAP;
    //        piezo_time = 0;
    //    }else if (state_piezo == TAP){
    //        state_piezo = ACTIVE;
    //    }
    //}else if (piezo_time >= PIEZO_TIMEOUT){
    //    state_piezo = IDLE;
    //}
    return state_piezo;
}
