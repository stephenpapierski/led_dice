/**
 * 
 * @file    piezo.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04- 4 00:17:13
 * @edited  2015-04- 4 00:17:25
 */

#include "../defs.h"
#include "piezo.h"

void piezo_init(void){
    LINE_DDR &= ~(PIEZO); //configure PIEZO pin as input
    LINE_PORT |= PIEZO; //enable pull up resistor for PIEZO pin
}
