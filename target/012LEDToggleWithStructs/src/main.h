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

#endif // MAIN_H_

