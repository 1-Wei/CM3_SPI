#include "CortexM3.h"
#include "CortexM3_driver.h"
#include "spi_gpio.h"

// 1 led亮 0 led灭

extern uint32_t SystemCoreClock;

void LED_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
	
 GPIOA->OUTENCLR = 0x00;
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;				 //LED0-->PB.5 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 		 //推挽输出

 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
 GPIO_ResetBits(GPIOA,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);						 
	
//验证输入函数
// GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
// GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
// GPIO_Init(GPIOA, &GPIO_InitStructure);
	//GPIO_SetBits(GPIOA,GPIO_Pin_4);
 //GPIOA->DATA &= ~((uint32_t)GPIOA);
}

void my_delay(uint32_t time){
	time*=5000;
	while(time--){
	}
}

int main(){
	SysTick_Config(SystemCoreClock / 1000);//1ms
	char *a = "armCM3";
	uint8_t ReadBuffer[50];
	SystemInit();
	SPI_GPIO_Init();
	while(1) 
	{	
		Master_SPI_WR_String(ReadBuffer,(uint8_t*)a,6);
	}
}

