/**
 *
 * @file    dice.h
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04-17 22:45:47
 * @edited  2015-04-18 00:27:27
 */

#ifndef DICE_H
#define DICE_H

#include "../myModules.h"

typedef enum {
    READY,
    SLEEP,
    ROLL1,
    ROLL2,
    ROLLING
} EDiceState;

EDiceState dice_state_update(EDiceState state_dice, EPiezoState state_piezo);
void dice_hardware_update(EDiceState state_dice);

#endif //DICE_H
