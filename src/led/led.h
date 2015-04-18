/**
 * LED control module
 * @file    led.h
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04- 3 19:17:40
 * @edited  2015-04-18 01:38:29
 */

#ifndef LED_H
#define LED_H

#include "../defs.h"

/******************************************************************************/
/* Declarations                                                               */
/******************************************************************************/
#define UL_LED_DDR  (LINE1 | LINE2)         //Upper Left LED DDR
#define UR_LED_DDR  (LINE0 | LINE1)         //Upper Right
#define ML_LED_DDR  (LINE1 | LINE2)         //Middle Left
#define MC_LED_DDR  (LINE2 | LINE3)         //Middle Center
#define MR_LED_DDR  (LINE0 | LINE3)         //Middle Right
#define BL_LED_DDR  (LINE2 | LINE3)         //Bottom Left
#define BR_LED_DDR  (LINE0 | LINE1)         //Bottom Right

#define UL_LED_PORT LINE2                   //Upper Left LED PORT
#define UR_LED_PORT LINE0                   //Upper Right
#define ML_LED_PORT LINE1                   //Middle Left
#define MC_LED_PORT LINE3                   //Middle Center
#define MR_LED_PORT LINE0                   //Middle Right
#define BL_LED_PORT LINE2                   //Bottom Left
#define BR_LED_PORT LINE1                   //Bottom Right

//led byte mask for led_state
#define UL_LED 0x01                   //Upper Left LED PORT
#define UR_LED 0x02                   //Upper Right
#define ML_LED 0x04                   //Middle Left
#define MC_LED 0x08                   //Middle Center
#define MR_LED 0x10                   //Middle Right
#define BL_LED 0x20                   //Bottom Left
#define BR_LED 0x40                   //Bottom Right

//dice faces
#define BLANK   0x00
#define ONE     (MC_LED)
#define TWO     (UL_LED | BR_LED)
#define THREE   (UL_LED | MC_LED | BR_LED)
#define FOUR    (UL_LED | UR_LED | BL_LED | BR_LED)
#define FIVE    (UL_LED | UR_LED | MC_LED | BL_LED | BR_LED)
#define SIX     (UL_LED | UR_LED | ML_LED | MR_LED | BL_LED | BR_LED)
#define ALL_LED (ONE | SIX)

#define NUM_LEDS        7
#define ROLL_FACE_TIME  2000    //time each face will display while rolling
#define FACE_TIMEOUT    500000  //time number will displayed before leds turn off

//extern time counters
extern volatile unsigned int roll_time;
extern volatile unsigned int face_time;

/******************************************************************************/
/* Library Functions                                                          */
/******************************************************************************/

/**
 * @brief   Initialize led state to blank
 */
void led_init(void);

/**
 * @brief   Handles the charlieplexing of the LEDs
 */
void led_update(void);

/**
 * @brief Update the dice face
 * @param   new_led_state   The new led face to display
 */
void led_set_face(unsigned char new_led_state);

/**
 * @brief Increments which led is currently lit for charlieplexing
 */
void led_charlieplex_index(void);

/**
 * @brief Get a pseudo random face
 * @return  Random dice face
 */
unsigned char led_rand_face(void);

#endif //LED_H
