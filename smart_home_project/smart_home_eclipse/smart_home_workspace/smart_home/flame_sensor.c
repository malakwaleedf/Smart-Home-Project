/*
 *  File name: flame_sensor.c
 *  Description: Source file for Flame Sensor driver
 *  Created on: Oct 5, 2024
 *  Author: Malak Waleed
 */

#include "flame_sensor.h"
#include "gpio.h"
#include "common_macros.h"

void FlameSensor_init(void)
{
	/*set the direction of flame sensor's pin to output*/
	GPIO_setupPinDirection(FLAME_SENSOR_PORT, FLAME_SENSOR_PIN, PIN_OUTPUT);
}

uint8 FlameSensor_getValue(void)
{
	/*return flame sensors's reading*/
	return GPIO_readPin(FLAME_SENSOR_PORT, FLAME_SENSOR_PIN);
}
