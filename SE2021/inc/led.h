/**
* @file		led.h
* @brief	Contains the led API.
* @version	1.0
* @date		3 Nov 2020
* @author	ILeal
*
* Copyright(C) 2015-2020, ILeal
* All rights reserved.
*
***********************************************************************
* Software that is described here in is for illustrative purposes only
* which provides customers with programming information regarding the
* products. This software is supplied "AS IS" without any warranties.
**********************************************************************/

#ifndef LED_H_
#define LED_H_
#include <stdbool.h>

/** @defgroup LED LED
 * This package provides the core capabilities for wait functions.
 * @{
 */

/** @defgroup LED_Public_Functions LED Public Functions
 * @{
 */

/**
 * @brief 	Initialises the LED api to be able to use the integrated led.
 * @note  	This function must be called prior to any other LED functions,
 * 			and use the pins P0[22] resource.
 */
void LED_Init(char state);

/**
 * @brief	Reads the leds states.
 * @return	Bitmap with RGB
 */
char LED_GetState(void);

/**
 * @brief	Sets the leds state.
 */
void LED_SetState(char state);


/**
 * @}
 */


/**
 * @}
 */

#endif /* LED_H_ */
