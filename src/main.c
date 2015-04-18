/**
 * LED Dice
 * @file    main.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-03-25 17:08:57
 * @edited  2015-04-18 01:46:03
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
/* Main Program                                                               */
/******************************************************************************/
int main(void){
    //variable declarations
    EPiezoState state_piezo;
    EDiceState state_dice = READY;

    //setup
    tmr_init();
    intr_init();
    piezo_init();
    led_init();

    //enable interrupts
    sei();

    while(1){      
        state_piezo = piezo_get_state();
        dice_hardware_update(state_dice);
        state_dice = dice_state_update(state_dice, state_piezo);
    }
}
