 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Omar Reda
 ******************************************************************************/

#include "Dio.h"
#include "Dio_Regs.h"



static const Dio_ConfigChannel * Dio_PortChannels = NULL_PTR;
static uint8 Dio_Status = DIO_NOT_INITIALIZED;

/************************************************************************************
* Service Name: Dio_Init
* Service ID[hex]: 0x10
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Dio module.
************************************************************************************/
void Dio_Init(const Dio_ConfigType * ConfigPtr)
{

	/*
	* Set the module state to initialized and point to the PB configuration structure using a global pointer.
	 * This global pointer is global to be used by other functions to read the PB configuration structures
	 */
	Dio_Status       = DIO_INITIALIZED;
	Dio_PortChannels = ConfigPtr->Channels; /* address of the first Channels structure --> Channels[0] */

}

/************************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	volatile uint32 * Port_Ptr = NULL_PTR;
		/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
	switch(Dio_PortChannels[ChannelId].Port_Num)
	{
            case 0:    Port_Ptr = &GPIO_PORTA_DATA_REG;
		               break;
            case 1:    Port_Ptr = &GPIO_PORTB_DATA_REG;
		               break;
            case 2:    Port_Ptr = &GPIO_PORTC_DATA_REG;
		               break;
	    case 3:    Port_Ptr = &GPIO_PORTD_DATA_REG;
		               break;
            case 4:    Port_Ptr = &GPIO_PORTE_DATA_REG;
		               break;
            case 5:    Port_Ptr = &GPIO_PORTF_DATA_REG;
		               break;
		}
		if(Level == STD_HIGH)
		{
			/* Write Logic High */
			SET_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
		}
		else if(Level == STD_LOW)
		{
			/* Write Logic Low */
			CLEAR_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
		}

}

/************************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to return the value of the specified DIO channel.
************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	volatile uint32 * Port_Ptr = NULL_PTR;
	Dio_LevelType output = STD_LOW;



	/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
	switch(Dio_PortChannels[ChannelId].Port_Num)
		{
            case 0:    Port_Ptr = &GPIO_PORTA_DATA_REG;
		               break;
		    case 1:    Port_Ptr = &GPIO_PORTB_DATA_REG;
		               break;
		    case 2:    Port_Ptr = &GPIO_PORTC_DATA_REG;
		               break;
		    case 3:    Port_Ptr = &GPIO_PORTD_DATA_REG;
		               break;
            case 4:    Port_Ptr = &GPIO_PORTE_DATA_REG;
		               break;
            case 5:    Port_Ptr = &GPIO_PORTF_DATA_REG;
		               break;
		}
		/* Read the required channel */
	if(BIT_IS_SET(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num))
	{
		output = STD_HIGH;
	}
	else
	{
		output = STD_LOW;
	}
  return output;
}

/************************************************************************************
* Service Name: Dio_FlipChannel
* Service ID[hex]: 0x11
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to flip the level of a channel and return the level of the channel after flip.
************************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	volatile uint32 * Port_Ptr = NULL_PTR;
	Dio_LevelType output = STD_LOW;

		/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
	switch(Dio_PortChannels[ChannelId].Port_Num)
	{
            case 0:    Port_Ptr = &GPIO_PORTA_DATA_REG;
		               break;
            case 1:    Port_Ptr = &GPIO_PORTB_DATA_REG;
		               break;
            case 2:    Port_Ptr = &GPIO_PORTC_DATA_REG;
		               break;
            case 3:    Port_Ptr = &GPIO_PORTD_DATA_REG;
		               break;
            case 4:    Port_Ptr = &GPIO_PORTE_DATA_REG;
		               break;
            case 5:    Port_Ptr = &GPIO_PORTF_DATA_REG;
		               break;
        }
		/* Read the required channel and write the required level */
        if(BIT_IS_SET(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num))
          {
            CLEAR_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
	    output = STD_LOW;
	  }
	else
          {
            SET_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
	    output = STD_HIGH;
	  }

        return output;
}
