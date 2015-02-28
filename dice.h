/**
 * @file    dice.h
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    27 February 2015
 * @version 0.1
 */
#ifndef DICE_H
#define DICE_H

//include stuff
#define LINE_DDR    DDRB
#define LINE_PORT   PORTB
#define LINE0       1<<PORTB0
#define LINE1       1<<PORTB1
#define LINE2       1<<PORTB4
#define LINE3       1<<PORTB3
#define PIEZO       1<<PORTB2

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

#define NUM_LEDS    7

int main(void);
void reset_led_ddr(void);
void reset_led_port(void);

volatile unsigned int led_index;

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

#endif
