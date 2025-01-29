/*
 *  File name: led.h
 *  Description: Header file for LED light intensity sensor driver
 *  Created on: Oct 5, 2024
 *  Author: Malak Waleed
 */

#ifndef LED_H_
#define LED_H_

#include "std_types.h"

/*LED connection logic, 0 for positive logic and 1 for negative logic*/
#define LED_CONNECTION_LOGIC 0

/*LED colors*/
#define LED_RED_ID 1
#define LED_GREEN_ID 2
#define LED_BLUE_ID 3

/*LED ports and pins*/
#define LED_RED_PORT PORTB_ID
#define LED_RED_PIN PIN5_ID
#define LED_GREEN_PORT PORTB_ID
#define LED_GREEN_PIN PIN6_ID
#define LED_BLUE_PORT PORTB_ID
#define LED_BLUE_PIN PIN7_ID

/*data type to hold the LED number*/
typedef unsigned char LED_ID;

/*Global variable*/
extern LED_ID g_ledRedLed;
extern LED_ID g_ledGreenLed;
extern LED_ID g_ledBlueLed;

/*Function prototypes*/
void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);

#endif /* LED_H_ */
