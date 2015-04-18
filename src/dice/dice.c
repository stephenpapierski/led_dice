/**
 * 
 * @file    dice.c
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04-17 22:45:44
 * @edited  2015-04-18 00:39:29
 */

#include "../myModules.h"
#include "../config.h"

#include "dice.h"


EDiceState dice_state_update(EDiceState state_dice, EPiezoState state_piezo){
    EDiceState new_dice_state = state_dice;
    switch (state_dice){
        case READY:
            //check for input
            if (state_piezo == TAP){
                piezo_tap_time = 0;
                new_dice_state = ROLL1;
            }else if (roll_time > DICE_TIMEOUT){
                new_dice_state = SLEEP;
            }
            break;
        case SLEEP:
            //return to ready state
            new_dice_state = READY;
            break;
        case ROLL1:
            new_dice_state = ROLLING;
            break;
        case ROLL2:
            new_dice_state = ROLLING;
            break;
        case ROLLING:
            if ((state_piezo == TAP) && (piezo_tap_time < DOUBLE_TAP_INTERVAL)){
                intr_disable_piezo();
                new_dice_state = ROLL2;
            }else if (roll_time > ROLL_TIME){
                intr_enable_piezo();
                new_dice_state = READY;
            }
            break;
    }
    return new_dice_state;
}

void dice_hardware_update(EDiceState state_dice){
    static unsigned int num_faces;
    static unsigned char face0;
    static unsigned char face1;

    switch (state_dice){
        case READY:
            //display current roll
            switch (num_faces){
                case 1:
                    led_state = face0;
                    break;
                case 2:
                    //display two faces
                    if (face_time > (DUAL_FACE_TIME<<1)){
                        face_time = 0;
                    }
                    if (face_time < DUAL_FACE_TIME){
                        led_state = face0;
                    }else{
                        led_state = face1;
                    }
                    break;
            }
            break;
        case SLEEP:
            //clear LEDs
            led_state = BLANK;
            led_update();

            //shut down
            pwr_down();

            break;
        case ROLL1:
            //roll 1 dice
            num_faces = 1;
            face0 = led_rand_face();
            roll_time = 0;
            face_time = 0;
            break;
        case ROLL2:
            //roll 2 dice
            num_faces = 2;
            face0 = led_rand_face();
            face1 = led_rand_face();
            roll_time = 0;
            face_time = 0;
            break;
        case ROLLING:
            if (face_time >= FACE_TIME){
                led_state = led_rand_face();
                face_time = 0;
            }

            break;
    }
}
