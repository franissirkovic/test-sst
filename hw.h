#ifndef ARM_EXAMPLE_H_
#define ARM_EXAMPLE_H_

/**************************************************************************************************
 * (C) Copyright 2006, Artur Lipowski
 *
 * No guarantees, warrantees, or promises, implied or otherwise.
 * May be used for hobby or commercial purposes provided copyright
 * notice remains intact.
 *
 *************************************************************************************************/


#include <avr/io.h>


#define IS_BTN_PRESS()      (0)

#define LED0_PORT   PORTA
#define LED0_PORTD  DDRA
#define LED0_BIT    PA0

#define LED_OFF(_led_)      do { _led_##_PORT &= ~_BV(_led_##_BIT); } while (0)
#define LED_ON(_led_)      do { _led_##_PORT |= _BV(_led_##_BIT); } while (0)

#define LED_TOGGLE(_led_) \
    do { \
        if (_led_##_PORT & _BV(_led_##_BIT)) \
        { \
            LED_OFF(_led_); \
        } \
        else \
        { \
            LED_ON(_led_); \
        } \
    } while (0)


void ioinit(void);


#endif /*ARM_EXAMPLE_H_*/
