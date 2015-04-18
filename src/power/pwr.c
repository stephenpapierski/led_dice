/**
 * Power management
 * @file    pwr.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04-15 23:38:45
 * @edited  2015-04-18 01:44:08
 */

#include <avr/sleep.h>

#include "pwr.h"

/******************************************************************************/
/* Library Functions                                              	          */
/******************************************************************************/

void pwr_down(void){
    //set sleep mode to power-down
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);

    //enable sleep, go to sleep, disable sleep
    sleep_mode();
}
