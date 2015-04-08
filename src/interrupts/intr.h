/**
 *
 * @file    intr.h
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04- 3 23:56:13
 * @edited  2015-04- 8 01:18:28
 */

#ifndef INTR_H
#define INTR_H

//extern volatile unsigned int led_index;
extern volatile unsigned short roll_flag;
extern unsigned long int roll_time;
extern unsigned long int face_time;

void intr_init(void);

#endif //INTR_H
