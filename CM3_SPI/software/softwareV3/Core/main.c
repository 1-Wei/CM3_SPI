#include "CortexM3.h"
#include "CortexM3_driver.h"

extern uint32_t SystemCoreClock;
void SystemInit(void);

int main(void)
{
  SysTick_Config(SystemCoreClock / 1000);  //1ms
  SystemInit();
	char *a = "hello\n";
	uart_SendString(a);
//	
//	GPIO_Init();
//	GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
//	
//	if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_0) == 1)
//	{
//		GPIO_ResetBits(GPIOA,GPIO_Pin_0);
//	}
//	GPIO_Write(GPIOA, (uint16_t)(GPIOA->DATA));
//	
//	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4) == 0)
//	{
//		GPIO_ResetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
//		
//	}
//	else
//	{
//		GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
//	}

//    while (1)
//    {
//        *(volatile uint32_t *) (0x60000000 + 0x0) = 0xffff;
//    }
}
