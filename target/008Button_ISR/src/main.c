#include <stdint.h>
#include <stdio.h>

//global shared variable between main code and ISR
uint8_t volatile g_button_pressed = 0;

uint32_t g_button_press_count =0;

void button_init(void);

uint32_t volatile *pEXTTIPendReg		= (uint32_t*) (0x40013C00 + 0x14);
uint32_t volatile *pClkCtrlReg			= (uint32_t*) (0x40023800 + 0x30); //Bit 3 set to 1, for GPIOC
uint32_t volatile *pClkCtrlRegApb2		= (uint32_t*) (0x40023800 + 0x44); //Looks good
uint32_t volatile *pEXTIMaskReg 		= (uint32_t*) (0x40013C00 + 0x00);
uint32_t volatile *pEXTTIEdgeCtrlReg	= (uint32_t*) (0x40013C00 + 0x08); 
uint32_t volatile *pNVICIRQEnReg 		= (uint32_t*) (0xE000E100 + 0x04); //Check offset for EXTICR4 = 0x14


int main(void)
{
	printf("Starting...\n");
	button_init();

	while(1)
	{
		//Disable interrupt
		*pEXTIMaskReg &= ~( 1 << 13);

		if(g_button_pressed){
			//Some delay until button debouncing gets over
			for(uint32_t volatile i=0;i<500000/2;i++);
			g_button_press_count++;

			printf("Button is pressed : %lu\n",g_button_press_count);
			g_button_pressed = 0;
		}

		//Enable interrupt
		*pEXTIMaskReg |= ( 1 << 13);
    }


}

void button_init(void)
{
    *pClkCtrlReg |= ( 1 << 2); //Enable RCC for GPIOC, bit 3 set to 1
    *pClkCtrlRegApb2 |= ( 1 << 14); //SYSCFGEN, Sys Config Enable
    *pEXTTIEdgeCtrlReg |= ( 1 << 13); //EXTI - RTSR 13
    *pEXTIMaskReg |= ( 1 << 13); //Should it be 13?
    *pNVICIRQEnReg |= ( 1 << 8); //1 to Bit 5, EXTI13
}

/* This is button interrupt handler*/
void EXTI13_IRQHandler(void)
{
    //Make this flag SET . if button pressed
    g_button_pressed = 1;

    *pEXTTIPendReg |= ( 1 << 13);
}


