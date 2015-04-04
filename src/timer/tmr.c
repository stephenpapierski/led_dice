/**
 * 
 * @file    tmr.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04- 3 19:30:33
 * @edited  2015-04- 3 19:50:22
 */

#include <avr/io.h>

#include "tmr.h"

void tmr_init(void){
    TCCR0A = 1<<WGM01; //sets Timer0 to CTC mode
    TCCR0B = 1<<CS01; //sets Timer0 @ (1MHz/8)
    OCR0A = 125; //set Timer0 to overflow every ms
    TIMSK = 1<<TOIE0; //enables Timer0 Overflow Interrupt
}
