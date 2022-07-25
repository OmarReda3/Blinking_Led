 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Omar Reda
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/* Number of the configured Port Channels */
#define PORT_CONFIGURED_CHANNLES              (39U)


/* Port numbers definitons */
#define PortConf_PORTA_NUM                (uint8)0
#define PortConf_PORTB_NUM                (uint8)1
#define PortConf_PORTC_NUM                (uint8)2
#define PortConf_PORTD_NUM                (uint8)3
#define PortConf_PORTE_NUM                (uint8)4
#define PortConf_PORTF_NUM                (uint8)5


/* Pin numbers definitons */
#define PortConf_PIN0_NUM                  (uint8)0
#define PortConf_PIN1_NUM                  (uint8)1
#define PortConf_PIN2_NUM                  (uint8)2
#define PortConf_PIN3_NUM                  (uint8)3
#define PortConf_PIN4_NUM                  (uint8)4
#define PortConf_PIN5_NUM                  (uint8)5
#define PortConf_PIN6_NUM                  (uint8)6
#define PortConf_PIN7_NUM                  (uint8)7


/* Pin mode deifinitions */
#define PORT_PIN_MODE_DIO                  (uint8)0
#define PORT_PIN_MODE_ADC                  (uint8)15
#define PORT_PIN_MODE_UART                 (uint8)1
#define PORT_PIN_MODE_CAN                  (uint8)8
#define PORT_PIN_MODE_TIMER                (uint8)7
#define PORT_PIN_MODE_SSI                  (uint8)2
#define PORT_PIN_MODE_NMI                  (uint8)8
#define PORT_PIN_MODE_I2C                  (uint8)3


/* PortA Pin Index in the array of structures in Port_PBcfg.c */
#define PortConf_PORTA_PIN0_ID_INDEX        (uint8)0x00
#define PortConf_PORTA_PIN1_ID_INDEX        (uint8)0x01
#define PortConf_PORTA_PIN2_ID_INDEX        (uint8)0x02
#define PortConf_PORTA_PIN3_ID_INDEX        (uint8)0x03
#define PortConf_PORTA_PIN4_ID_INDEX        (uint8)0x04
#define PortConf_PORTA_PIN5_ID_INDEX        (uint8)0x05
#define PortConf_PORTA_PIN6_ID_INDEX        (uint8)0x06
#define PortConf_PORTA_PIN7_ID_INDEX        (uint8)0x07

/* PortB Pin Index in the array of structures in Port_PBcfg.c */
#define PortConf_PORTB_PIN0_ID_INDEX        (uint8)0x08
#define PortConf_PORTB_PIN1_ID_INDEX        (uint8)0x09
#define PortConf_PORTB_PIN2_ID_INDEX        (uint8)0x0A
#define PortConf_PORTB_PIN3_ID_INDEX        (uint8)0x0B
#define PortConf_PORTB_PIN4_ID_INDEX        (uint8)0x0C
#define PortConf_PORTB_PIN5_ID_INDEX        (uint8)0x0D
#define PortConf_PORTB_PIN6_ID_INDEX        (uint8)0x0E
#define PortConf_PORTB_PIN7_ID_INDEX        (uint8)0x0F

/* PortC Pin Index in the array of structures in Port_PBcfg.c */
#define PortConf_PORTC_PIN4_ID_INDEX        (uint8)0x14
#define PortConf_PORTC_PIN5_ID_INDEX        (uint8)0x15
#define PortConf_PORTC_PIN6_ID_INDEX        (uint8)0x16
#define PortConf_PORTC_PIN7_ID_INDEX        (uint8)0x17

/* PortD Pin Index in the array of structures in Port_PBcfg.c */
#define PortConf_PORTD_PIN0_ID_INDEX        (uint8)0x18
#define PortConf_PORTD_PIN1_ID_INDEX        (uint8)0x19
#define PortConf_PORTD_PIN2_ID_INDEX        (uint8)0x1A
#define PortConf_PORTD_PIN3_ID_INDEX        (uint8)0x1B
#define PortConf_PORTD_PIN4_ID_INDEX        (uint8)0x1C
#define PortConf_PORTD_PIN5_ID_INDEX        (uint8)0x1D
#define PortConf_PORTD_PIN6_ID_INDEX        (uint8)0x1E
#define PortConf_PORTD_PIN7_ID_INDEX        (uint8)0x1F

/* PortE Pin Index in the array of structures in Port_PBcfg.c */
#define PortConf_PORTE_PIN0_ID_INDEX        (uint8)0x20
#define PortConf_PORTE_PIN1_ID_INDEX        (uint8)0x21
#define PortConf_PORTE_PIN2_ID_INDEX        (uint8)0x22
#define PortConf_PORTE_PIN3_ID_INDEX        (uint8)0x23
#define PortConf_PORTE_PIN4_ID_INDEX        (uint8)0x24
#define PortConf_PORTE_PIN5_ID_INDEX        (uint8)0x25

/* PortF Pin Index in the array of structures in Port_PBcfg.c */
#define PortConf_PORTF_PIN0_ID_INDEX        (uint8)0x26
#define PortConf_PORTF_PIN1_ID_INDEX        (uint8)0x27
#define PortConf_PORTF_PIN2_ID_INDEX        (uint8)0x28
#define PortConf_PORTF_PIN3_ID_INDEX        (uint8)0x29
#define PortConf_PORTF_PIN4_ID_INDEX        (uint8)0x2A



#endif /* PORT_CFG_H */
