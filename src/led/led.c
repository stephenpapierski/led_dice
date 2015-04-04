/**
 * 
 * @file    led.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04- 3 19:17:37
 * @edited  2015-04- 3 19:49:16
 */

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "led.h"

/******************************************************************************/
/* Variable Declaration                                         	          */
/******************************************************************************/

volatile unsigned int led_index;
unsigned char led_state;

//DDR direction setting for LEDs
const unsigned char led_ddr[7] = {
    UL_LED_DDR,
    UR_LED_DDR,
    ML_LED_DDR,
    MC_LED_DDR,
    MR_LED_DDR,
    BL_LED_DDR,
    BR_LED_DDR,
};

//PORT output setting for LEDs
const unsigned char led_port[7] = {
    UL_LED_PORT,
    UR_LED_PORT,
    ML_LED_PORT,
    MC_LED_PORT,
    MR_LED_PORT,
    BL_LED_PORT,
    BR_LED_PORT,
};

const unsigned char led_mask[7] = {
    UL_LED,
    UR_LED,
    ML_LED,
    MC_LED,
    MR_LED,
    BL_LED,
    BR_LED,
};

const unsigned char led_faces[6] = {
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX
};

/******************************************************************************/
/* Library Functions                                                          */
/******************************************************************************/

/**
 * Turns off the current LED and turns on the one specified by led_index
 */
void led_update(void){
    cli(); //disable interrupts (messes with led states)
    LINE_PORT = 0x00; //turn off current leds
    LINE_DDR = 0x00; //set all pins as inputs
    if (led_state & led_mask[led_index]){
        LINE_DDR |= led_ddr[led_index]; //set led ddr
        LINE_PORT |= led_port[led_index]; //set led port
    }
    sei(); //enable interrupts
}

/**
 * rand face
 */
unsigned char led_rand_face(void){
    int face = rand() % 6;
    return led_faces[face];
}
