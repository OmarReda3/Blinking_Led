 /******************************************************************************
 *
 * Module: IntCtrl
 *
 * File Name: IntCtrl_Regs.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - IntCtrl Driver Registers
 *
 * Author: Omar Reda
 ******************************************************************************/

#ifndef INTCTRL_REGS_H
#define INTCTRL_REGS_H
#include "Std_Types.h"

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/

/* INTCTRL Registers base addresses */
#define CORTEXM4_PERIPHERAL_BASE_ADDRESS       0xE000E000

/* SCB Registers offset addresses */
#define INTCTRL_REG    (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0xD04)))
#define APINT_REG      (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0xD0C)))
	
/* NVIC Priority Registers offset addresses */
#define NVIC_PRI0_REG             (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x400)))
#define NVIC_PRI1_REG             (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x404)))
#define NVIC_PRI2_REG             (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x408)))
#define NVIC_PRI3_REG             (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x40C)))
#define NVIC_PRI4_REG             (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x410)))
#define NVIC_PRI5_REG             (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x414)))
#define NVIC_PRI6_REG             (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x418)))
#define NVIC_PRI7_REG             (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x41C)))
#define NVIC_PRI8_REG             (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x420)))
#define NVIC_PRI9_REG             (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x424)))
#define NVIC_PRI10_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x428)))
#define NVIC_PRI11_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x42C)))
#define NVIC_PRI12_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x430)))
#define NVIC_PRI13_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x434)))
#define NVIC_PRI14_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x438)))
#define NVIC_PRI15_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x43C)))
#define NVIC_PRI16_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x440)))
#define NVIC_PRI17_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x444)))
#define NVIC_PRI18_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x448)))
#define NVIC_PRI19_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x44C)))
#define NVIC_PRI20_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x450)))
#define NVIC_PRI21_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x454)))
#define NVIC_PRI22_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x458)))
#define NVIC_PRI23_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x45C)))
#define NVIC_PRI24_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x460)))
#define NVIC_PRI25_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x464)))
#define NVIC_PRI26_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x468)))
#define NVIC_PRI27_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x46C)))
#define NVIC_PRI28_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x470)))
#define NVIC_PRI29_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x474)))
#define NVIC_PRI30_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x478)))
#define NVIC_PRI31_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x47C)))
#define NVIC_PRI32_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x480)))
#define NVIC_PRI33_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x484)))
#define NVIC_PRI34_REG            (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x488)))

/* NVIC Enable Registers offset addresses */

#define NVIC_EN0_REG              (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x100)))
#define NVIC_EN1_REG              (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x104)))
#define NVIC_EN2_REG              (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x108)))
#define NVIC_EN3_REG              (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x10C)))
#define NVIC_EN4_REG              (*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0x110)))

#endif /* INTCTRL_REGS_H */