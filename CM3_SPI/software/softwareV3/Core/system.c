#include "CortexM3.h"
#include "CortexM3_driver.h"

/*-------------------- Define clocks --------------------*/

#define __XTAL            (50000000UL)	//Oscillator frequency

#define __SYSTEM_CLOCK    (__XTAL)

/*-------------------- Clock Variable definitions --------------------*/

uint32_t SystemCoreClock = __SYSTEM_CLOCK;	//!< System Clock Frequency (Core Clock)

/*-------------------- Clock functions --------------------*/
/**
 * Update SystemCoreClock variable
 *
 * @param  none
 * @return none
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */

volatile uint32_t SystemTicks = 0;

void SystemCoreClockUpdate (void)
{
    SystemCoreClock = __SYSTEM_CLOCK;
}

void SysTick_Handler(void)
{
    SystemTicks++;
}

void Delay(uint32_t time_ms)
{
    uint32_t now = SystemTicks;

    while ((SystemTicks - now) < time_ms);
}

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System.
 */

void SystemInit (void)
{
    SystemCoreClock = __SYSTEM_CLOCK;
    NVIC_EnableIRQ(SysTick_IRQn);
    uart_init(UART, (SystemCoreClock / 115200), 1, 1, 0, 0, 0, 0);
}
