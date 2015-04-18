/**
 * Interrupt handlers and utilities
 * @file    intr.h
 * @author  Stephen Papierski <stephenpapierski@gmail.com>
 * @date    2015-04- 3 23:56:13
 * @edited  2015-04-18 01:38:05
 */

#ifndef INTR_H
#define INTR_H

/******************************************************************************/
/* Library Functions                                                          */
/******************************************************************************/

/**
 * @brief Enable int0 external low-level interrupt
 */
void intr_init(void);

/**
 * @brief Disable piezo interrupt
 */
void intr_disable_piezo(void);

/**
 * @brief Enable piezo interrupt
 */
void intr_enable_piezo(void);

#endif //INTR_H
