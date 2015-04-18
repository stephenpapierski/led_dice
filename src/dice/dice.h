/**
 * User interface and hardware control
 * @file    dice.h
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04-17 22:45:47
 * @edited  2015-04-18 01:25:35
 */

#ifndef DICE_H
#define DICE_H

#include "../myModules.h"

/******************************************************************************/
/* Declarations                                                               */
/******************************************************************************/

typedef enum {
    READY,
    SLEEP,
    ROLL1,
    ROLL2,
    ROLLING
} EDiceState;

/******************************************************************************/
/* Library Functions                                                          */
/******************************************************************************/

/**
 * @brief Calculates the next state of the dice
 * @param   state_dice  The current state of the dice
 * @param   state_piezo The current state of the piezo
 * @return  The new state of the dice
 */
EDiceState dice_state_update(EDiceState state_dice, EPiezoState state_piezo);

/**
 * @brief Updates the hardware settings based on the passed state of the dice
 * @param state_dice    The state of the dice
 */
void dice_hardware_update(EDiceState state_dice);

#endif //DICE_H
