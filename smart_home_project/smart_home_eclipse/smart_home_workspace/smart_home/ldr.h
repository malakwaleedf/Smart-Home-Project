/*
 *  File name: ldr.h
 *  Description: Header file for LDR light intensity sensor driver
 *  Created on: Oct 5, 2024
 *  Author: Malak Waleed
 */

#ifndef LDR_H_
#define LDR_H_

#include "std_types.h"

#define LDR_SENSOR_CHANNEL_ID 0
#define LDR_SENSOR_MAX_VOLT_VALUE 2.56
#define LDR_SENSOR_MAX_LIGHT_INTENSITY 100

/*Function prototypes*/
uint16 LDR_getLightIntensity(void);

#endif /* LDR_H_ */
