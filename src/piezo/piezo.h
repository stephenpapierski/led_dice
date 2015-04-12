/**
 *
 * @file    piezo.h
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04- 4 00:17:28
 * @edited  2015-04-11 22:38:43
 */

#ifndef PIEZO_H
#define PIEZO_H

#define PIEZO_DDR   DDRB
#define PIEZO_PORT  PORTB
#define PIEZO_PIN   PINB
#define PIEZO_P     (1<<PB2)
#define PIEZO_LOW   !(PIEZO_PIN & PIEZO_P)

//time before piezo state is set to idle in ms
#define PIEZO_TIMEOUT   50

typedef enum { IDLE       =   0,    //piezo is idle
               ACTIVE     =   1,    //piezo is bouncing
               TAP        =   2     //piezo was just tapped
} EPiezoState;

extern volatile unsigned int piezo_time;
extern volatile unsigned int piezo_interrupt;

void piezo_init(void);
EPiezoState piezo_get_state(void);

#endif //PIEZO_H
