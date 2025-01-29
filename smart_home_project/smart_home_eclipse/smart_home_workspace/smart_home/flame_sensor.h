/*
 *  File name: flame_sensor.h
 *  Description: Header file for Flame Sensor driver
 *  Created on: Oct 5, 2024
 *  Author: Malak Waleed
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include "std_types.h"

#define FLAME_SENSOR_PORT PORTD_ID
#define FLAME_SENSOR_PIN PIN2_ID

/*Function prototypes*/
void FlameSensor_init(void);
uint8 FlameSensor_getValue(void);

#endif /* FLAME_SENSOR_H_ */
