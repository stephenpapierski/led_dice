/**
 * 
 * @file    piezo.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04- 4 00:17:13
 * @edited  2015-04- 7 16:46:23
 */

#include "../defs.h"
#include "piezo.h"

EPiezoState state_piezo;
volatile unsigned int piezo_time;

void piezo_init(void){
    LINE_DDR &= ~(PIEZO); //configure PIEZO pin as input
    LINE_PORT |= PIEZO; //enable pull up resistor for PIEZO pin
    state_piezo = IDLE;
}

EPiezoState get_piezo_state(void){
    if (PIEZO_LOW){
        if (state_piezo == IDLE){
            state_piezo = TAP;
            piezo_time = 0;
        }else if (state_piezo == TAP){
            state_piezo = ACTIVE;
        }
    }else if (piezo_time >= PIEZO_TIMEOUT){
        state_piezo = IDLE;
    }
    return state_piezo;
}
