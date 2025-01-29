/*
 *  File name: main.c
 *  Description: Source file for smart home application
 *  Created on: Oct 7, 2024
 *  Author: Malak Waleed
 */

#define F_CPU 16000000UL

#include <util/delay.h>
#include "common_macros.h"
#include "std_types.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "ldr.h"
#include "led.h"
#include "dc_motor.h"
#include "flame_sensor.h"
#include "buzzer.h"


int main(void)
{
	/*parameters variables*/
	uint8 fire_alarm = 0;
	uint8 alarm_message[] = "Critical alert!";
	uint8 fan_flag = 0;
	uint8 fan_on_display[] = "FAN is ON      ";
	uint8 fan_off_display[] = "FAN is OFF      ";
	uint8 temp = 0;
	uint8 temp_display[] = "Temp=";
	uint16 light_intensity = 0;
	uint8 light_intensity_display[] = " LDR=";

	/*devices initialization*/
	LCD_init();
	LEDS_init();
	DcMotor_Init();
	FlameSensor_init();
	Buzzer_init();

	temp = LM35_getTemperature();
	light_intensity = LDR_getLightIntensity();
	_delay_ms(300);

	LCD_clearScreen();

	while(1){

		/*check if there is fire*/
		fire_alarm = FlameSensor_getValue();

		if(fire_alarm)
		{
			LCD_moveCursor(0, 0);
			Buzzer_on();
			LCD_displayString(alarm_message, sizeof(alarm_message));
			LCD_moveCursor(1, 0);
			LCD_displayString("                     ", sizeof("                     "));
		}
		else
		{
			Buzzer_off();
			LCD_moveCursor(0, 0);
			if(fan_flag)
			{
				LCD_displayString(fan_on_display, sizeof(fan_on_display));
			}
			else
			{
				LCD_displayString(fan_off_display, sizeof(fan_off_display));
			}

			temp = LM35_getTemperature();
			LCD_moveCursor(1, 0);
			LCD_displayString(temp_display, (sizeof(temp_display) - 1));
			LCD_intgerToString(temp);
			if(temp >= 40)
			{
				DcMotor_Rotate(DC_MOTOR_CLOCKWISE, 100);
				fan_flag = 1;
			}
			else if((temp < 40) && (temp >= 35))
			{
				DcMotor_Rotate(DC_MOTOR_CLOCKWISE, 75);
				fan_flag = 1;
			}
			else if((temp < 35) && (temp >= 30))
			{
				DcMotor_Rotate(DC_MOTOR_CLOCKWISE, 50);
				fan_flag = 1;
			}
			else if((temp < 30) && (temp >= 25))
			{
				DcMotor_Rotate(DC_MOTOR_CLOCKWISE, 25);
				fan_flag = 1;
			}
			else
			{
				DcMotor_Rotate(DC_MOTOR_STOP, 0);
				fan_flag = 0;
			}

			light_intensity = LDR_getLightIntensity();
			LCD_moveCursor(1, 7);
			LCD_displayString(light_intensity_display, (sizeof(light_intensity_display) - 1));
			LCD_intgerToString(light_intensity);
			LCD_displayCharacter('%');

			if(light_intensity <= 15)
			{
				LED_on(LED_RED_ID);
				LED_on(LED_GREEN_ID);
				LED_on(LED_BLUE_ID);
			}
			else if((light_intensity > 15) && (light_intensity <= 50))
			{
				LED_on(LED_RED_ID);
				LED_on(LED_GREEN_ID);
				LED_off(LED_BLUE_ID);
			}
			else if((light_intensity > 50) && (light_intensity <= 70))
			{
				LED_on(LED_RED_ID);
				LED_off(LED_GREEN_ID);
				LED_off(LED_BLUE_ID);
			}
			else
			{
				LED_off(LED_RED_ID);
				LED_off(LED_GREEN_ID);
				LED_off(LED_BLUE_ID);
			}
		}
	}
}
