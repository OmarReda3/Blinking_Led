#include "Dio.h"
#include "Port.h"
#include "GPT.h"
#include "GPT_Regs.h"
#include "IntCtrl.h"


	
void LED_toggle(void)
	
{

	Dio_LevelType state = Dio_FlipChannel(DioConf_LED1_CHANNEL_ID_INDEX);
	( *(volatile uint32 *)((volatile uint8 *)GPT_TIMER0_BASE_ADDRESS  + GPT_GPTMICR_REG_OFFSET) ) |= 0x01; 
}


void Init(void)
{
     /* Initialize Port Driver */
    Port_Init(&Port_Configuration);
    /* Initialize Dio Driver */
    Dio_Init(&Dio_Configuration);
	  /* Initialize Gpt Driver */
	  Gpt_Init(&Gpt_Configuration);
	  /* Initialize IntCtrl Driver */
	  IntCtrl_init();
	
}




int main()
{
	Enable_Interrupt();
	Init();
	Gpt_setCallBack(LED_toggle);
	Gpt_StartTimer(TIMER0_A, ONE_SECOND_16BIT_TIMER_VALUE);
	
while(1)
{
	
}


  return 0;
}
