#include "main.h"

int main(void)
{
	// GPIOA: 0x4002 0000 - 0x4002 03FF

	// GPIOA Port Mode register: 0x4002 0000
	// GPIOA Port Mode Offset: 0x00
	//	Equals to: 0x4002 0000

	// GPIOA Pin 5 Mode:
	//	Bits 11 and 10
	//	General Purpose Output Mode = 01

	// GPIOA Data Output Offset: 0x14
	//	Equals to: 0x4002 0014

	// GPIOA Pin 5 Output:
	//	Bit 5
	//	0 = Red
	//	1 = Green

	// RCC: 0x4002 3800 - 0x4002 3BFF
	// RCC AHB1ENR Offset: 0x30
	// 	Equals to: 0x4002 3830

	// GPIOA RCC Enable
	//	Bit 0

	// Store register addresses
	uint32_t *pGpioa_port_mode 		= (uint32_t*)0x40020000;
	uint32_t *pGpioa_data_output 	= (uint32_t*)0x40020014;
	uint32_t *pAhb1enr_rcc 			= (uint32_t*)0x40023830;

	// Reset register values
	//	*ahb1enr_rcc 					= (uint32_t)0x00000000;
	//	*gpioa_port_mode 				= (uint32_t)0x0C000000;
	//	*gpioa_data_output 				= (uint32_t)0x00000000;

	// Activate bits
	// rcc enable, bit 0 to 1
    	*pAhb1enr_rcc = *pAhb1enr_rcc | (1 << 0);
	// gpioa port mode, bits 10, 11 to 01
	*pGpioa_port_mode &= ~(3 << 10);
	*pGpioa_port_mode |= (1 << 10);
	// gpio data output, bit 5 to 1
	*pGpioa_data_output |= (1 << 5);


    /* Loop forever */
	while(1)
	{
		for (uint32_t i = 0; i < 100000; i++);
		*pGpioa_data_output &= ~(1 << 5);
		for (uint32_t i = 0; i < 100000; i++);
		*pGpioa_data_output |= (1 << 5);
	}
}
