#include "CortexM3.h"
#include "CortexM3_driver.h"
void NMIHandler(void) {
    ;
}

void HardFaultHandler(void) {
    ;
}

void MemManageHandler(void) {
    ;
}

void BusFaultHandler(void) {
    ;
}

void UsageFaultHandler(void) {
    ;
}

void SVCHandler(void) {
    ;
}

void DebugMonHandler(void) {
    ;
}

void PendSVHandler(void) {
    ;
}

void SysTickHandler(void) {
    Set_SysTick_CTRL(0);
    SCB->ICSR = SCB->ICSR | (1 << 25);
}


void UARTRXHandler(void) {
//		uart_ClearTxIRQ(UART);
//    send2LED(0x0001);
//		Delay(1000);
	int data;
    data = uart_ReceiveChar(UART);
	send2LED(data);
	uart_SendString("M3:");
    uart_SendChar(UART,data);
    uart_SendChar(UART,'\n');
}	

void UARTTXHandler(void) {
    ;
}

void UARTOVRHandler(void) {
    ;
}

void KEYHandler(void) {
		char *b = "armCM3";
		uart_SendString(b);
	  send2LED(0x0008);
		uint32_t time=7000000;
		while(time--){
		}	
		send2LED(0x0000);
}

volatile uint32_t SystemTicks=0;

void SysTick_Handler(void){
	SystemTicks++;
}

void Delay(uint32_t time_ms){
	uint32_t now = SystemTicks;
	while((SystemTicks - now ) < time_ms);
}

