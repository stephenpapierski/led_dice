/**
 * Contains user configuration settings
 * @file    config.h
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04-11 23:36:49
 * @edited  2015-04-13 09:56:04
 */

#ifndef CONFIG_H
#define CONFIG_H

//how close two taps must be to be a double tap (ms)
#define DOUBLE_TAP_INTERVAL     500

//how long the dice "rolls" for (ms)
#define ROLL_TIME               1000

//how long each face is displayed while rolling (ms)
#define FACE_TIME               50

//how long to display each face when two are rolled (ms)
#define DUAL_FACE_TIME          1000

//how long dice displays roll before going to sleep (ms)
#define DICE_TIMEOUT            5000

#endif //CONFIG_H
