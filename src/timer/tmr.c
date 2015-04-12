/**
 * 
 * @file    tmr.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04- 3 19:30:33
 * @edited  2015-04- 9 19:29:13
 */

#include <avr/io.h>

#include "tmr.h"

void tmr_init(void){
    TCCR0A = 1<<WGM01; //sets Timer0 to CTC mode
    TCCR0B = 1<<CS01; //sets Timer0 @ (1MHz/8)
    OCR0A = 125; //set Timer0 to CompA every 1 ms
    //OCR0B = 50; // CompB every 150 us
    TIMSK = 1<<OCIE0A;//| 1<<OCIE0B; //enables Timer0 Compare A Interrupt
}
