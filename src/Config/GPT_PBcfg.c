 /******************************************************************************
 *
 * Module: Gpt
 *
 * File Name: Gpt_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Omar Reda
 ******************************************************************************/

#include "GPT.h"

const Gpt_ConfigType  Gpt_Configuration = {
	
	{TIMER0_A, GPT_CONTINUOUS, MAX_PRESCALER_VALUE}
	
};