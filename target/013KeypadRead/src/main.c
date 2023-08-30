#include "main.h"

int main(void)
{
	/*
		PC5	-	C1
		PC6	-	C2
		PC8	-	C3
		PC9	-	C4

		PA8	-	R1
		PA10 -	R2
		PA2	-	R3
		PA3	-	R4
	*/

	// Store register addresses
	RCC_AHB1ENR_t volatile *const pAhb1enr_rcc 			= (RCC_AHB1ENR_t*)0x40023830;

	// A
	GPIO_MODER_t volatile *const pGpioa_port_mode 		= (GPIO_MODER_t*)0x40020000;
	GPIO_OTYPER_t volatile *const pGpioa_data_output 	= (GPIO_OTYPER_t*)0x40020014;	
	
	// C
	GPIO_MODER_t volatile *const pGpioc_port_mode 		= (GPIO_MODER_t*)0x40020800;
	GPIO_OTYPER_t volatile *const pGpioc_data_output 	= (GPIO_OTYPER_t*)0x40020814;	

	// Activate bits
    pAhb1enr_rcc->gpioa_en = 1;
	pAhb1enr_rcc->gpioc_en = 1;
	
	// A
	pGpioa_port_mode->moder5 = 1;
	pGpioa_data_output->ot5 = 1;

	// C
	pGpioa_port_mode->moder5 = 1;
	pGpioa_data_output->ot5 = 1;

    /* Loop forever */
	while(1)
	{
		for (uint32_t i = 0; i < 100; i++);
		// *pGpioa_data_output &= ~(1 << 5);
		pGpioa_data_output->ot5 = 0;
		for (uint32_t i = 0; i < 100; i++);
		// *pGpioa_data_output |= (1 << 5);
		pGpioa_data_output->ot5 = 1;
	}
}
