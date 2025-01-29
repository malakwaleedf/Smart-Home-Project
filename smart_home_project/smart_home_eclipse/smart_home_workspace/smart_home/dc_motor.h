/*
 *  File name: dc_motor.h
 *  Description: Header file for DC Motor driver
 *  Created on: Oct 5, 2024
 *  Author: Malak Waleed
 */


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*DC motor ports and pins*/
#define DC_MOTOR_PORT PORTB_ID
#define DC_MOTOR_IN1 PIN0_ID
#define DC_MOTOR_IN2 PIN1_ID
#define DC_MOTOR_EN1 PIN3_ID

/*enum data type to hold the dc moto's states*/
typedef enum{
	DC_MOTOR_STOP,
	DC_MOTOR_CLOCKWISE,
	DC_MOTOR_ANTI_CLOCKWISE
}DcMotor_State;

/*Functions prototypes*/
void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DC_MOTOR_H_ */
