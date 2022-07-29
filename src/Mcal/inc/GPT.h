 /******************************************************************************
 *
 * Module: GPT
 *
 * File Name: GPT.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - GPT Driver
 *
 * Author: Omar Reda
 ******************************************************************************/

#ifndef GPT_H
#define GPT_H

/*
 * Macros for GPT Status
 */
#define GPT_INITIALIZED                (1U)
#define GPT_NOT_INITIALIZED            (0U)

#include "Std_Types.h"

/* GPT Pre-Compile Configuration Header file */
#include "GPT_Cfg.h"

#include "Common_Macros.h"

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Gpt_ChannelType used by the GPT APIs */
typedef uint8 Gpt_ChannelType;

/* Type definition for Gpt_ValueType used by the GPT APIs */
typedef uint32 Gpt_ValueType;

/* Type definition for Gpt_PrescalerType used by the GPT APIs */
typedef uint8 Gpt_PrescalerType;

/* Type definition for Gpt_ModeType used by the GPT APIs */
typedef enum
{
  GPT_MODE_NORMAL, Gpt_MODE_SLEEP
} Gpt_ModeType;

/* Type definition for Gpt_RunningMode used by the GPT APIs */
typedef enum
{
  GPT_ONE_SHOT, GPT_CONTINUOUS
} Gpt_RunningMode;

/* Type definition for Gpt_ConfigChannel used by the GPT APIs */
typedef struct
{
  Gpt_ChannelType Gpt_ChannelNum;
  Gpt_RunningMode Gpt_ChannelRunningMode;
  Gpt_PrescalerType   Gpt_Prescaler;
}Gpt_ConfigChannel;

/* Type definition for Gpt_ConfigType used by the GPT APIs */
typedef struct
{
	Gpt_ConfigChannel Channels[GPT_CONFIGURED_CHANNLES];
}Gpt_ConfigType; 


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/* Function for GPT Initialization API */
void Gpt_Init(const Gpt_ConfigType* ConfigPtr);

/* Function for GPT Timer Start API */
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);

/* Function for GPT Set Callback API */
void Gpt_setCallBack(void(*ptr)(void));
/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Gpt and other modules */
extern const Gpt_ConfigType  Gpt_Configuration;

#endif /* GPT_H */
