 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Omar Reda
 ******************************************************************************/

#include "Port.h"

/* PB structure used with Port_Init API */
const Port_ConfigType Port_Configuration = {
                                        /* PORTA */
PortConf_PORTA_NUM, PortConf_PIN0_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTA_NUM, PortConf_PIN1_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTA_NUM, PortConf_PIN2_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTA_NUM, PortConf_PIN3_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTA_NUM, PortConf_PIN4_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTA_NUM, PortConf_PIN5_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTA_NUM, PortConf_PIN6_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTA_NUM, PortConf_PIN7_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,

                                        /* PORTB */
PortConf_PORTB_NUM, PortConf_PIN0_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTB_NUM, PortConf_PIN1_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTB_NUM, PortConf_PIN2_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTB_NUM, PortConf_PIN3_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTB_NUM, PortConf_PIN4_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTB_NUM, PortConf_PIN5_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTB_NUM, PortConf_PIN6_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTB_NUM, PortConf_PIN7_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,

                                        /* PORTC */
PortConf_PORTC_NUM, PortConf_PIN4_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTC_NUM, PortConf_PIN5_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTC_NUM, PortConf_PIN6_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTC_NUM, PortConf_PIN7_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,

                                        /* PORTD */
PortConf_PORTD_NUM, PortConf_PIN0_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTD_NUM, PortConf_PIN1_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTD_NUM, PortConf_PIN2_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTD_NUM, PortConf_PIN3_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTD_NUM, PortConf_PIN4_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTD_NUM, PortConf_PIN7_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,

                                        /* PORTE */
PortConf_PORTE_NUM, PortConf_PIN0_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTE_NUM, PortConf_PIN1_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTE_NUM, PortConf_PIN2_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTE_NUM, PortConf_PIN3_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTE_NUM, PortConf_PIN4_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTE_NUM, PortConf_PIN5_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,

                                        /* PORTF */
PortConf_PORTF_NUM, PortConf_PIN0_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTF_NUM, PortConf_PIN1_NUM, PORT_PIN_OUT, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTF_NUM, PortConf_PIN2_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTF_NUM, PortConf_PIN3_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW,
PortConf_PORTF_NUM, PortConf_PIN4_NUM, PORT_PIN_IN, OFF, PORT_PIN_MODE_DIO, PIN_DIR_CHANGEABLE, PIN_MODE_CHANGEABLE, STD_LOW
				         };
   
