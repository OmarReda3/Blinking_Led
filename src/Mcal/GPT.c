/******************************************************************************
 *
 * Module: Gpt
 *
 * File Name: Gpt.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Gpt Driver.
 *
 * Author: Omar Reda
 ******************************************************************************/

#include "Gpt.h"
#include "Gpt_Regs.h"



static volatile void (*callBackPtr)(void) = NULL_PTR; 

static const Gpt_ConfigChannel * Gpt_Channels = NULL_PTR;
static uint8 Gpt_Status = GPT_NOT_INITIALIZED;
static Gpt_ModeType Gpt_Mode = GPT_MODE_NORMAL;



/************************************************************************************
* Service Name: Gpt_Init
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to initialize the Gpt Driver module
************************************************************************************/
void Gpt_Init(const Gpt_ConfigType* ConfigPtr)             
{
	uint8 i = 0;
	uint8 localch = 0;
	volatile uint32 * GPT_Ptr = NULL_PTR;
	volatile uint32 delay = 0; /* for rcgc timer */
    Gpt_Channels = ConfigPtr->Channels;
    Gpt_Mode = GPT_MODE_NORMAL;
	
    for(i=0; i<GPT_CONFIGURED_CHANNLES; i++)
    {
      localch = (Gpt_Channels[i].Gpt_ChannelNum) / 2 ;   
      if(localch < 6) /* not wide */
      {
        GPT_Ptr = (volatile uint32 *)GPT_TIMER0_BASE_ADDRESS +(1000 * localch);
		SET_BIT(GPT_RCGCTIMER, localch);
		delay = GPT_RCGCTIMER;
      }
	  else if(localch < 8) /* wide but first two regs */
	  {
		  GPT_Ptr = (volatile uint32 *)GPT_WIDE_TIMER0_BASE_ADDRESS +(1000 * (localch)); 
		  SET_BIT(GPT_RCGCWTIMER, (localch-6));
		  delay = GPT_RCGCWTIMER;
	  }
      else
      {
        GPT_Ptr = (volatile uint32 *)GPT_WIDE_TIMER2_BASE_ADDRESS +(1000 * (localch-8));
		SET_BIT(GPT_RCGCWTIMER, (localch-6));
		delay = GPT_RCGCWTIMER;
      }	  

      if( (Gpt_Channels[i].Gpt_ChannelNum)%2 == 0)
      {
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMCTL_REG_OFFSET),0); /* Clear the TAEN to disable timer */
          if((Gpt_Channels[i].Gpt_ChannelRunningMode) == GPT_ONE_SHOT) 
          {
            *(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTAMR_REG_OFFSET) &= 0xFC;
            *(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTAMR_REG_OFFSET) |= 0x01; 
          }
          else 
          {
            *(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTAMR_REG_OFFSET) &= 0xFC;
            *(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTAMR_REG_OFFSET) |= 0x02;
          }
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTAMR_REG_OFFSET),4);    /* make the timer count down */
		  *(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTAPR_REG_OFFSET) = (Gpt_Channels[i].Gpt_Prescaler); /* add prescaler */
      }      
      else
      {
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMCTL_REG_OFFSET),8);  /* Clear the TBEN to disable timer */
          if((Gpt_Channels[i].Gpt_ChannelRunningMode) == GPT_ONE_SHOT)
          {
            *(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTBMR_REG_OFFSET) &= 0xFC;
            *(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTBMR_REG_OFFSET) |= 0x01; 
          }
          else 
          {
            *(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTBMR_REG_OFFSET) &= 0xFC;
            *(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTBMR_REG_OFFSET) |= 0x02;
          }
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTBMR_REG_OFFSET),4);     /* make the timer count down*/
		  *(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTBPR_REG_OFFSET) = (Gpt_Channels[i].Gpt_Prescaler);   /* add prescaler */
      }
      *(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMCFG_REG_OFFSET) = 0x04;  /* Dont operate in concatenated mode */  
    } 
	Gpt_Status = GPT_INITIALIZED;
} 






/************************************************************************************
* Service Name: Gpt_StartTimer
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Channel - Channel number
*                  Value - Value for count
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set the port pin direction
************************************************************************************/
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
  uint8 localch = Channel /2 ; 
  volatile uint32 * GPT_Ptr = NULL_PTR;
  if(localch < 6) /* not wide */
   {  
      GPT_Ptr = (volatile uint32 *)GPT_TIMER0_BASE_ADDRESS +(1000 * localch);
   }
  else if(localch < 8) /* wide but first two regs */
   {
       GPT_Ptr = (volatile uint32 *)GPT_WIDE_TIMER0_BASE_ADDRESS +(1000 * (localch)); 
   }
   else
   {
      GPT_Ptr = (volatile uint32 *)GPT_WIDE_TIMER2_BASE_ADDRESS +(1000 * (localch-8));
   }	  


	 if(Channel %2 == 0)  /* Case timer A: */
  {
    *(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTAILR_REG_OFFSET) = (uint16)Value; 
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMIMR_REG_OFFSET),0);/* enable generate interrupt  */
	  SET_BIT(*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMCTL_REG_OFFSET),0);/* set the TAEN to enable the timer  */
  }
  else        /* Case timer B: */
  {
    *(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTBILR_REG_OFFSET) = (uint16)Value; 
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMIMR_REG_OFFSET),8);/* enable generate interrupt */
	  SET_BIT(*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMCTL_REG_OFFSET),8);/* set the TAEN to enable the timer */
  }
}



void Gpt_setCallBack(void(*ptr)(void))
{
	callBackPtr = ptr;   /* Save the address of the Call back function in the global variable */
}


void TIMER0A_Handler(void){
	
	if(callBackPtr != NULL_PTR)
	{

		(*callBackPtr)();  /* call the function using pointer to function callBackPtr(); */
	}	
	
}







