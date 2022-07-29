 /******************************************************************************
 *
 * Module: IntCtrl
 *
 * File Name: IntCtrl.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - IntCtrl Driver
 *
 * Author: Omar Reda
 ******************************************************************************/

#ifndef INTCRTL_H
#define INTCRTL_H


#include "Common_Macros.h"
#include "Std_Types.h"
#include "IntCtrl_CFG.h"


/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/

/* Enable Exceptions ... This Macro enable IRQ interrupts, Programmble Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions()    __asm("CPSIE I")

/* Disable Exceptions ... This Macro disable IRQ interrupts, Programmble Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Disable_Exceptions()   __asm("CPSID I")

/* Enable Faults ... This Macro enable Faults by clearing the F-bit in the FAULTMASK */
#define Enable_Faults()        __asm("CPSIE F")

/* Disable Faults ... This Macro disable Faults by setting the F-bit in the FAULTMASK */
#define Disable_Faults()       __asm("CPSID F") 

/* Go to low power mode while waiting for the next interrupt */
#define Wait_For_Interrupt()   __asm("WFI")


#define REG_SIZE        							32



#define VECTKEY               (uint32)0xFA05   
#define PRIGROUP_OFFSET        	      8
#define VECTKEY_OFFSET   	            16
#define PRI_RESERVED				        	5
#define PRI_FIELDS                  	4

#define NVIC_GR_TYPE_XXX    	       	4
#define NVIC_GR_TYPE_XXY    		      5
#define NVIC_GR_TYPE_XYY    		      6
#define NVIC_GR_TYPE_YYY    		      7

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
 
typedef uint8 InterruptGrPriority;

typedef uint8 InterruptSubGrPriority;

typedef enum
{
	GPIO_Port_A,		            
	GPIO_Port_B,		            
	GPIO_Port_C,		            
	GPIO_Port_D,		           
	GPIO_Port_E,		           
	UART_0,      	         
	UART_1,		             
	SSI_0,		                
	I2C_0,		                
	PWM0_Fault,		            
	PWM0_Gen_0,		           
	PWM0_Gen_1,		            
	PWM0_Gen_2,		            
	QEI_0,		                
	ADC0_Sequence_0,	        
	ADC0_Sequence_1,	        
	ADC0_Sequence_2,		    
	ADC0_Sequence_3,		   
	Watchdog_0_1,		       
	BIT_16_32_Bit_Timer_0A,		
	BIT_16_32_Bit_Timer_0B,		
	BIT_16_32_Bit_Timer_1A,		
	BIT_16_32_Bit_Timer_1B,		
	BIT_16_32_Bit_Timer_2A,		
	BIT_16_32_Bit_Timer_2B,		
	Analog_Comparator_0,		
	Analog_Comparator_1,		
	System_Control = 28,		
	Flash_Memory_Control,		
	GPIO_Port_F,               
	UART_2 = 33,		       
	SSI_1,		              
	Timer_3A,		            
	Timer_3B,		            
	I2C_1,		              
	QEI_1,		           
	CAN_0,		          
	CAN_1,		             
	Hibernate = 43,		     
	USB,		             
	PWM_Generator_3,	      
	uDMA_Software,		   
	uDMA_Error,
	ADC1_Sequence_0,		   
	ADC1_Sequence_1,		   
	ADC1_Sequence_2,		 
	ADC1_Sequence_3,		  											
	SSI_2 = 57,		          
	SSI_3,		           
	UART_3,		               
	UART_4,		               
	UART_5,		          
	UART_6,		        
	UART_7,		            
	I2C_2 = 68,		        
	I2C_3,				     
	BIT_16_32_Bit_Timer_4A,		
	BIT_16_32_Bit_Timer_4B,		
	BIT_16_32_Bit_Timer_5A = 92,   
	BIT_16_32_Bit_Timer_5B,		
	BIT_32_64_Bit_Timer_0A,		
	BIT_32_64_Bit_Timer_0B,	
	BIT_32_64_Bit_Timer_1A,		
	BIT_32_64_Bit_Timer_1B,		
	BIT_32_64_Bit_Timer_2A,		
	BIT_32_64_Bit_Timer_2B,		
	BIT_32_64_Bit_Timer_3A,		
	BIT_32_64_Bit_Timer_3B,		
	BIT_32_64_Bit_Timer_4A,		
	BIT_32_64_Bit_Timer_4B,		
	BIT_32_64_Bit_Timer_5A,		
	BIT_32_64_Bit_Timer_5B,		
	SYSTEM_Exception,		
	PWM1_Generator_0 = 134,		
	PWM1_Generator_1,		
	PWM1_Generator_2,		
	PWM1_Generator_3,		
	PWM1_Fault,		
}IntCtrl_InterruptType;



typedef struct
{
	IntCtrl_InterruptType intType;
	InterruptGrPriority grPriority;
	InterruptSubGrPriority subGrPriority;
}IntCtrl_Config;

typedef struct
{
	IntCtrl_Config intrTypes[IntCtrl_CONFIGURED_CHANNLES];
}IntCtrl_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
 
void IntCtrl_init(void);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by IntCtrl and other modules */
extern const IntCtrl_ConfigType IntCtrl_Configuration;



#endif /* INTCRTL_H */
