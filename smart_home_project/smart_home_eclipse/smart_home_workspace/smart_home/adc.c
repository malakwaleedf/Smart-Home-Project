/*
 *  File name: adc.c
 *  Description: Source file for ADC driver
 *  Created on: Oct 5, 2024
 *  Author: Malak Waleed
 */


#include <avr/io.h>
#include "gpio.h"
#include "common_macros.h"

void ADC_init(void)
{
	ADMUX = 0;

	/*internal reference voltage 2.56V*/
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);

	/*enable ADC*/
	SET_BIT(ADCSRA,ADEN);

	/*prescaler = 128*/
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
}

uint16 ADC_readChannel(uint8 channel_num)
{
	/*select channel num*/
	ADMUX = (ADMUX & 0xE0) | (channel_num & 0x07);

	/*start conversion*/
	SET_BIT(ADCSRA,ADSC);

	/*wait till the adc finishes conversion*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF));

	/*clear flag*/
	SET_BIT(ADCSRA,ADIF);

	/*return value*/
	return ADCW;
}

