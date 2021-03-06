/*
 * wait.c
 *
 *  Created on: 10 Out 2017
 *      Author: psampaio
 */

#include "LPC17xx.h"

#include "wait.h"

#define SYSTICK_FREQ (SystemCoreClock / 1000)

static volatile uint32_t __ms;

void SysTick_Handler(void)
{
	__ms++;
}

/*void WAIT_Milliseconds(uint32_t millis)
{
	uint32_t start = __ms;
	while ((__ms - start) < millis) {
		__WFI();
	}
}

int32_t WAIT_Init(void)
{
	SystemCoreClockUpdate();
    LPC_TIM0->PR = (SystemCoreClock/10000000) -1;
	LPC_TIM0->MCR = 0b11;
	LPC_TIM0->CTCR = 0;
	LPC_TIM0->TCR=0b11;
	LPC_SC->PCLKSEL0 |= 1<<2;
	LPC_SC->PCLKSEL0 &= ~(1<<3);
	LPC_SC->PCONP |= 0b10;
    if (SysTick_Config(SYSTICK_FREQ) == 1) return -1;
    return 0;
}

uint32_t WAIT_GetElapsedMillis(uint32_t start)
{
	return __ms - start;
}
*/
void WAIT_ChronoUs(uint32_t waitUs){
	LPC_TIM0->MR0 = waitUs*10;
	LPC_TIM0->IR =1;
	LPC_TIM0->TCR=1;
	while((LPC_TIM0->IR & 1)==0);
	LPC_TIM0->TCR=0b11;
}
