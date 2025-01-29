/*
 *  File name: adc.h
 *  Description: Header file for ADC driver
 *  Created on: Oct 5, 2024
 *  Author: Malak Waleed
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*Functions prototypes*/
uint16 ADC_readChannel(uint8 channel_num);
void ADC_init(void);

#endif /* ADC_H_ */
