 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Omar Reda
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

#include "Std_Types.h"

#include "Common_Macros.h"

#include "Port_Cfg.h"

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/* Description: Type definition for the symbolic name of a port pin  */
typedef uint8 Port_PinType;

/* Description: Type definition for different port pin modes */
typedef uint8 Port_PinModeType;

/* Description: Enum to hold PIN direction */
typedef enum
{
    PORT_PIN_IN,
    PORT_PIN_OUT
}Port_PinDirectionType;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,
    PULL_UP,
    PULL_DOWN
}Port_InternalResistor;

/* Description: Enum to hold whether direction of a pin is changeable or not */
typedef enum
{
  PIN_DIR_UNCHANGEABLE,
  PIN_DIR_CHANGEABLE
}Port_PinDriectionChange;

/* Description: Enum to hold whether mode of a pin is changeable or not */
typedef enum
{
  PIN_MODE_UNCHANGEABLE,
  PIN_MODE_CHANGEABLE
}Port_PinModeChange;

/* Description: Structure to configure each individual PIN:
 *	1. The PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. The number of the pin in the PORT.
 *      3. The direction of pin --> INPUT or OUTPUT
 *      4. The internal resistor --> Disable, Pull up or Pull down
 *      5. The pin mode     --> UART, DIO, CAN, LIN, ADC, I2C, ...
 *      6. The pin direction changeable or not -->   PIN_DIR_UNCHANGEABLE, PIN_DIR_CHANGEABLE
 *      7. The pin mode changeable or not     -->   PIN_MODE_UNCHANGEABLE, PIN_MODE_CHANGEABLE
 *      8. The pin initial value
 */
typedef struct
{
    uint8 port_num;
    uint8 pin_num;
    Port_PinDirectionType direction;
    Port_InternalResistor resistor;
    Port_PinModeType mode;
    Port_PinDriectionChange direction_change;
    Port_PinModeChange mode_change;
    uint8 initial_value;
}Port_ConfigChannel;


/* Description: Data Structure required for initializing the Port Driver */
typedef struct
{
  Port_ConfigChannel Channels[PORT_CONFIGURED_CHANNLES];
}Port_ConfigType;
/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

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
void Port_Init(const Port_ConfigType* ConfigPtr);


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

void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);


/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to refresh port direction
************************************************************************************/
void Port_RefreshPortDirection(void);


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

void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);



/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;



#endif /* PORT_H */
