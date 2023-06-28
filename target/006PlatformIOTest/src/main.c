#include <stdint.h>

int main(void)
{

	/* RCC
	 *	RCC: 0x4002 3800 - 0x4002 3BFF
	 *	RCC AHB1ENR Offset: 0x30
	 *		Equals to: 0x4002 3830
     *
	 *	GPIOA RCC Enable
	 *		Bit 0
	 */

	/* GPIOA
	 *	GPIOA: 0x4002 0000 - 0x4002 03FF
	 *	GPIOA Port Mode register: 0x4002 0000
	 *	GPIOA Port Mode Offset: 0x00
	 *		Equals to: 0x4002 0000
	 *
	 *	GPIOA Data Input Offset: 0x10
	 *		Equals to: 0x4002 0010
	 *
	 *	GPIOA Data Output Offset: 0x14
	 *		Equals to: 0x4002 0014
	 *
	 *	GPIOA Pin 0 Mode: PA0
	 *		Bits 0 and 1
	 *  	General Purpose Input Mode = 00
	 *
	 *  GPIOA Pin 5 Mode: LD2
	 *  	Bits 11 and 10
	 *  	General Purpose Output Mode = 01
	 *
	 *  GPIOA Pin 0 Output: PA0
	 *  	Bit 0
	 *  	LOW = turn LED off
	 *  	HIGH = turn LED on
	 *
	 *  GPIOA Pin 5 Output: LD2
	 *  	Bit 5
	 *  	0 = Red
	 *  	1 = Green
	 */

	// Store register addresses
	uint32_t volatile *const pGpioa_port_mode 			= (uint32_t*)0x40020000;
	uint32_t volatile const *const pGpioa_data_input 	= (uint32_t*)0x40020010;
	uint32_t volatile *const pGpioa_data_output 		= (uint32_t*)0x40020014;
	uint32_t volatile *const pAhb1enr_rcc 				= (uint32_t*)0x40023830;

	// Activate bits
	// rcc enable, bit 0 to 1
	*pAhb1enr_rcc = *pAhb1enr_rcc | (1 << 0);

	// gpioa port mode, bits 10, 11 to 01 (output)
	*pGpioa_port_mode &= ~(3 << 10);
	*pGpioa_port_mode |= (1 << 10);

	// gpioa port mode, bits 0, 1 to 00 (input)
	*pGpioa_port_mode &= ~(0 << 0);
	*pGpioa_port_mode &= ~(0 << 1);

	while(1)
	{
			// if PA0 = LOW
			if((*pGpioa_data_input & 0x1 ) == 0)
			{
				// gpio data output, bit 5 to 0, turn LD2 OFF
				*pGpioa_data_output &= (0 << 5);
			}
			// else, PA0 = HIGH
			else
			{
				// gpio data output, bit 5 to 1, turn LD2 ON
				*pGpioa_data_output |= (1 << 5);
			}
	}
}
