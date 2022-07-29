 /******************************************************************************
 *
 * Module: IntCtrl
 *
 * File Name: IntCtrl.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - IntCtrl Driver
 *
 * Author: Omar Reda
 ******************************************************************************/

#include "IntCtrl.h"
#include "IntCtrl_Regs.h"

static  volatile uint32*  PriReg_PTR		=		NULL_PTR;
static const IntCtrl_Config * Int_Channels = NULL_PTR;

/************************************************************************************
* Service Name: IntCtrl_init
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Intialize the IntCtrl driver
************************************************************************************/
void IntCtrl_init(void)
{
	Enable_Exceptions();
	Enable_Faults();
	InterruptGrPriority GrPri = 0;
	InterruptSubGrPriority SubGrPri  = 0 ;
	IntCtrl_InterruptType IntType;
	uint8 i = 0;
	uint32 GroupValue,Reg, Offset;
	APINT_REG =(VECTKEY << VECTKEY_OFFSET) | (IntCtrl_CFG_GR_PRI << PRIGROUP_OFFSET);
	Int_Channels = IntCtrl_Configuration.intrTypes;
	for(i=0; i<IntCtrl_CONFIGURED_CHANNLES; i++)
	{
		IntType = Int_Channels[i].intType;
		GrPri = Int_Channels[i].grPriority;
		SubGrPri = Int_Channels[i].subGrPriority;
		
		Reg =((Int_Channels->intType) / REG_SIZE);
		Offset = (Int_Channels->intType) % REG_SIZE;
		
		switch(Reg)
		{
			case 0: 
				SET_BIT(NVIC_EN0_REG,Offset);
				break;
			case 1: 
				SET_BIT(NVIC_EN1_REG,Offset);
				break;
			case 2: 
				SET_BIT(NVIC_EN2_REG,Offset);
   			break;
			case 3: 
				SET_BIT(NVIC_EN3_REG,Offset);
   			break;		
			default:
				break;
		}
		
		#if(IntCtrl_CFG_GR_PRI == NVIC_GR_TYPE_XXX)
		GroupValue = ((GrPri & 0x7)|(SubGrPri & 0x0));
		#elif(IntCtrl_CFG_GR_PRI == NVIC_GR_TYPE_XXY)
		GroupValue = (((GrPri & 0x3)<<1)|(SubGrPri & 0x1);
		#elif(IntCtrl_CFG_GR_PRI == NVIC_GR_TYPE_XYY)
		GroupValue = (((GrPri & 0x1)<<2)|(SubGrPri & 0x3);
		#elif(IntCtrl_CFG_GR_PRI == NVIC_GR_TYPE_YYY)
		GroupValue = (SubGrPri & 0x7);
		#endif
		
		Reg = (IntType / PRI_FIELDS);
		Offset = PRI_RESERVED + ((IntType % PRI_FIELDS) * 8);
		PriReg_PTR = &(NVIC_PRI0_REG);
		PriReg_PTR += Reg;
		*(PriReg_PTR) |= (GroupValue<<Offset);
		
		
	}
}

