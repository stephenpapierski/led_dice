/**
 *
 * @file    piezo.h
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04- 4 00:17:28
 * @edited  2015-04-18 01:43:16
 */

#ifndef PIEZO_H
#define PIEZO_H

/******************************************************************************/
/* Declarations                                                  	          */
/******************************************************************************/

#define PIEZO_DDR   DDRB
#define PIEZO_PORT  PORTB
#define PIEZO_PIN   PINB
#define PIEZO_P     (1<<PB2)
#define PIEZO_LOW   !(PIEZO_PIN & PIEZO_P)

//time before piezo state is set to idle in ms (debounce time)
#define PIEZO_TIMEOUT   50

typedef enum { IDLE       =   0,    //piezo is idle
               ACTIVE     =   1,    //piezo is bouncing
               TAP        =   2     //piezo was just tapped
} EPiezoState;

extern volatile unsigned int piezo_time;
extern volatile unsigned int piezo_tap_time;

/******************************************************************************/
/* Library Functions                                               	          */
/******************************************************************************/

/**
 * @brief   Initialize piezo
 */
void piezo_init(void);

/**
 * @brief   Get the debounced state of the piezo
 * @return  Current piezo state
 */
EPiezoState piezo_get_state(void);

/**
 * @brief   Set the state of the piezo user interrupt flag
 * @param   state   0 or 1
 */
void piezo_interrupt_flag(int state);

#endif //PIEZO_H
