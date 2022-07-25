 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Omar Reda
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"



static const Port_ConfigChannel * Port_Channels = NULL_PTR;
static uint8 Port_Status = PORT_NOT_INITIALIZED;




/************************************************************************************
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to initialize the Port Driver module
************************************************************************************/

void Port_Init(const Port_ConfigType* ConfigPtr)
{
  uint8 i = 0;
  volatile uint32 * Port_Ptr = NULL_PTR;
  volatile uint32 delay = 0;


  Port_Channels = ConfigPtr->Channels;
  for(i=0; i<PORT_CONFIGURED_CHANNLES; i++)
    {
      switch(Port_Channels[i].port_num)
            {
              case  0: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                       break;
              case  1: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                       break;
              case  2: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                       break;
              case  3: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                       break;
              case  4: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                       break;
              case  5: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                       break;
            }

            SYSCTL_REGCGC2_REG |= (1<<(Port_Channels[i].port_num));
            delay = SYSCTL_REGCGC2_REG;


            if( ((PortConf_PORTD_NUM == (Port_Channels[i].port_num)) && (PortConf_PIN7_NUM == (Port_Channels[i].pin_num))) || ((PortConf_PORTF_NUM == (Port_Channels[i].port_num)) && (PortConf_PIN0_NUM == (Port_Channels[i].pin_num))) ) /* PD7 or PF0 */
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_LOCK_REG_OFFSET) = UNLOCK_VALUE;                     /* Unlock the GPIOCR register */
              SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_COMMIT_REG_OFFSET) , (Port_Channels[i].pin_num));  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
            }
            else if((PortConf_PORTC_NUM == (Port_Channels[i].port_num)) && (PortConf_PIN3_NUM >= (Port_Channels[i].pin_num))) /* PC0 to PC3 */
            {
                  /* Do Nothing ...  this is the JTAG pins */
            }
            else
            {
                  /* Do Nothing ... No need to unlock the commit register for this pin */
            }

            if(PORT_PIN_OUT == (Port_Channels[i].direction))
            {
              SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , (Port_Channels[i].pin_num));                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */

              if(STD_HIGH == (Port_Channels[i].initial_value))
                {
                  SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DATA_REG_OFFSET) , (Port_Channels[i].pin_num));          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
                }
              else
                {
                  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DATA_REG_OFFSET) , (Port_Channels[i].pin_num));        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
                }
            }
            else if(PORT_PIN_IN == (Port_Channels[i].direction))
            {
              CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , (Port_Channels[i].pin_num));             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */

              if(PULL_UP == (Port_Channels[i].resistor))
              {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET) , (Port_Channels[i].pin_num));       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
              }
              else if(PULL_DOWN == (Port_Channels[i].resistor))
              {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET) , (Port_Channels[i].pin_num));     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
              }
              else
              {
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET) , (Port_Channels[i].pin_num));     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET) , (Port_Channels[i].pin_num));   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
              }
            }
            else
            {
                  /* Do Nothing */
            }

            if(PORT_PIN_MODE_DIO == (Port_Channels[i].mode))
            {
              CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , (Port_Channels[i].pin_num));             /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
              CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , (Port_Channels[i].pin_num));                    /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << ((Port_Channels[i].pin_num) * 4));            /* Clear the PMCx bits for this pin */
              SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , (Port_Channels[i].pin_num));                /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            }
            else if(PORT_PIN_MODE_ADC == (Port_Channels[i].mode))
            {
              SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , (Port_Channels[i].pin_num));                /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
              CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , (Port_Channels[i].pin_num));                     /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << ((Port_Channels[i].pin_num) * 4));             /* Clear the PMCx bits for this pin */
              CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , (Port_Channels[i].pin_num));               /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */
            }
            else
            {
              CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , (Port_Channels[i].pin_num));               /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
              SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , (Port_Channels[i].pin_num));                        /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << ((Port_Channels[i].pin_num) * 4));              /* Clear the PMCx bits for this pin */
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((Port_Channels[i].mode) << ((Port_Channels[i].pin_num) * 4));  /* Set the PMCx bits with the value corresonding to the mode for this pin */
              SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , (Port_Channels[i].pin_num));                  /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            }

          }

        Port_Status    =   PORT_INITIALIZED;

}



/************************************************************************************
* Service Name: Port_SetPinDirection
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number
*                  Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set the port pin direction
************************************************************************************/

void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
  volatile uint32 * Port_Ptr = NULL_PTR;

   switch(Port_Channels[Pin].port_num)
     {
       case  0: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                       break;
       case  1: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                       break;
       case  2: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                       break;
       case  3: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                       break;
       case  4: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                       break;
       case  5: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                       break;
      }

      if(PORT_PIN_OUT == Direction)
        {
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , (Port_Channels[Pin].pin_num));                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
        }
      else if(PORT_PIN_IN == Direction)
        {
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , (Port_Channels[Pin].pin_num));             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        }
      else
        {
                  /* Do Nothing */
        }

}


/************************************************************************************
* Service Name: Port_SetPinMode
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number
*                  Mode - New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set the port pin mode
************************************************************************************/

void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
  volatile uint32 * Port_Ptr = NULL_PTR;

  switch(Port_Channels[Pin].port_num)
    {
              case  0: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                       break;
              case  1: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                       break;
              case  2: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                       break;
              case  3: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                       break;
              case  4: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                       break;
              case  5: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                       break;
     }

   if(PORT_PIN_MODE_DIO == Mode)
     {
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , (Port_Channels[Pin].pin_num));             /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , (Port_Channels[Pin].pin_num));                    /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
       *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << ((Port_Channels[Pin].pin_num) * 4));            /* Clear the PMCx bits for this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , (Port_Channels[Pin].pin_num));                /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
     }
    else if(PORT_PIN_MODE_ADC == Mode)
     {
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , (Port_Channels[Pin].pin_num));                /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , (Port_Channels[Pin].pin_num));                     /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
        *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << ((Port_Channels[Pin].pin_num) * 4));             /* Clear the PMCx bits for this pin */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , (Port_Channels[Pin].pin_num));               /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */
     }
     else
      {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , (Port_Channels[Pin].pin_num));               /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , (Port_Channels[Pin].pin_num));                        /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
        *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << ((Port_Channels[Pin].pin_num) * 4));              /* Clear the PMCx bits for this pin */
        *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((Port_Channels[Pin].mode) << ((Port_Channels[Pin].pin_num) * 4));  /* Set the PMCx bits with the value corresonding to the mode for this pin */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , (Port_Channels[Pin].pin_num));                  /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
      }

}

















































