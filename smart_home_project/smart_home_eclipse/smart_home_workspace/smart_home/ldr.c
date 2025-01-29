/*
 *  File name: ldr.c
 *  Description: Source file for LDR light intensity sensor driver
 *  Created on: Oct 5, 2024
 *  Author: Malak Waleed
 */


#include "ldr.h"
#include "adc.h"

uint16 LDR_getLightIntensity(void)
{
	ADC_init();
	uint16 light_intensity_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the LDR sensor is connected */
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Calculate the light intensity percentage from the ADC value*/
	light_intensity_value = (((float)adc_value)/ADC_MAXIMUM_VALUE) * LDR_SENSOR_MAX_LIGHT_INTENSITY;

	return light_intensity_value;
}
