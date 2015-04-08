/**
 *
 * @file    defs.h
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-03-23 09:28:45
 * @edited  2015-04- 3 19:35:38
 */

#ifndef DEFS_H
#define DEFS_H

#include <avr/io.h>

//#define RANDOM_MAX  5   //define max number generated by rand()
#define LINE_DDR    DDRB
#define LINE_PORT   PORTB
#define LINE0       1<<PORTB0
#define LINE1       1<<PORTB1
#define LINE2       1<<PORTB4
#define LINE3       1<<PORTB3
#define PIEZO       1<<PORTB2

#endif //DEFS_H