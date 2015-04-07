/**
 *
 * @file    piezo.h
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04- 4 00:17:28
 * @edited  2015-04- 7 16:45:06
 */

#ifndef PIEZO_H
#define PIEZO_H

#define PIEZO_DDR   DDRB
#define PIEZO_PORT  PORTB
#define PIEZO_PIN   PINB
#define PIEZO_P     (1<<PB2)
#define PIEZO_LOW   !(PIEZO_PIN & PIEZO_P)

//time before piezo state is set to idle in ms
#define PIEZO_TIMEOUT   150

typedef enum { IDLE       =   0,    //piezo is idle
               ACTIVE     =   1,    //piezo is bouncing
               TAP        =   2     //piezo was just tapped
} EPiezoState;

extern volatile unsigned int piezo_time;

void piezo_init(void);

#endif //PIEZO_H
