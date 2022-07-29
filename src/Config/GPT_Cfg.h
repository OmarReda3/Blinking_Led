/**
 * Module: Gpt
 *
 * File Name: Gpt_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Gpt Driver
 *
 * Author: Omar Reda
 **/

#ifndef GPT_CFG_H
#define GPT_CFG_H



#define MAX_PRESCALER_VALUE                 255
#define ONE_SECOND_16BIT_TIMER_VALUE        62500
#define MAX_16BIT_TIMER_VALUE               65535
#define MAX_32BIT_TIMER_VALUE               15999999

/* Number of the configured GPT Channels */
#define GPT_CONFIGURED_CHANNLES             (1U)

#define TIMER_REGISTERS_COUNT               12

/* Definitions of GPT Channel Numbers */
#define TIMER0_A  0
#define TIMER0_B  1
#define TIMER1_A  2
#define TIMER1_B  3
#define TIMER2_A  4
#define TIMER2_B  5
#define TIMER3_A  6
#define TIMER3_B  7
#define TIMER4_A  8
#define TIMER4_B  9
#define TIMER5_A  10
#define TIMER5_B  11


#define TIMER0_A_WIDE  12
#define TIMER0_B_WIDE  13
#define TIMER1_A_WIDE  14
#define TIMER1_B_WIDE  15
#define TIMER2_A_WIDE  16
#define TIMER2_B_WIDE  17
#define TIMER3_A_WIDE  18
#define TIMER3_B_WIDE  19
#define TIMER4_A_WIDE  20
#define TIMER4_B_WIDE  21
#define TIMER5_A_WIDE  22
#define TIMER5_B_WIDE  23



#endif /* GPT_CFG_H */