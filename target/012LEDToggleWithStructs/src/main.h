#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>

typedef struct
{
	uint32_t	gpioa_en		:1;
	uint32_t	gpiob_en		:1;
	uint32_t	gpioc_en		:1;
	uint32_t	gpiod_en		:1;
	uint32_t	gpioe_en		:1;
    uint32_t    reserved1       :2;
	uint32_t	gpioh_en		:1;
	uint32_t	reserved2		:4;
	uint32_t	crc_en  		:1;
    uint32_t    reserved3       :8;
    uint32_t    dma1_en         :1;
    uint32_t    dma2_en         :1;
    uint32_t    reserved4       :9;
}RCC_AHB1ENR_t;

typedef struct
{
	uint32_t	moder0			:2;
	uint32_t	moder1			:2;
	uint32_t	moder2			:2;
	uint32_t	moder3			:2;
	uint32_t	moder4			:2;
	uint32_t	moder5			:2;
	uint32_t	moder6			:2;
	uint32_t	moder7			:2;
	uint32_t	moder8			:2;
	uint32_t	moder9			:2;
	uint32_t	moder10			:2;
	uint32_t	moder11			:2;
	uint32_t	moder12			:2;
	uint32_t	moder13			:2;
	uint32_t	moder14			:2;
	uint32_t	moder15			:2;
	
}GPIO_MODER_t;

typedef struct
{
	uint32_t	ot0		:1;
	uint32_t	ot1		:1;
	uint32_t	ot2		:1;
	uint32_t	ot3		:1;
	uint32_t	ot4		:1;
	uint32_t	ot5		:1;
	uint32_t	ot6		:1;
	uint32_t	ot7		:1;
	uint32_t	ot8		:1;
	uint32_t	ot9		:1;
	uint32_t	ot10	:1;
	uint32_t	ot11	:1;
	uint32_t	ot12	:1;
	uint32_t	ot13	:1;
	uint32_t	ot14	:1;
	uint32_t	ot15	:1;
	uint32_t    reserved3       :16;

}GPIO_OTYPER_t;

#endif // MAIN_H_

