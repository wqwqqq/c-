#ifndef __STC32F10X_H
#define __STC32F10X_H

#define RCC_APB22ENR	*(unsigned int*)(0x40021018)
#define GPIOC_CRH			*(unsigned int*)(0x40011004)
#define GPIOC_ODR			*(unsigned int*)(0x4001100c)

#define PERIPH_BASE   ((unsigned int)0x40000000)//外设基地址
	
#define APB2PERIPH_BASE	(PERIPH_BASE+0x10000)//外设基地址+偏移量
#define	AHBPERIPH_BASE	(PERIPH_BASE+0x20000)//AHB总线基地址
#define GPIOC_BASE (APB2PERIPH_BASE+0X1000)//GPIO在APB2总线上，所以是APB2基地址+偏移量
#define RCC_BASE 		(AHBPERIPH_BASE+0x1000)//RCC基地址

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;

typedef struct
{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t BRR;
	uint32_t LCKR;
}GPIO_TypeDef;

typedef struct
{
	uint32_t CR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t APB2RSTR;
	uint32_t APB1RSTR;
	uint32_t AHBENR;
	uint32_t APB2ENR;
	uint32_t APB1ENR;
	uint32_t BDCR;
	uint32_t CSR;
}RCC_TypeDef;

#define GPIOC ((GPIO_TypeDef*)GPIOC_BASE)
#define RCC		((RCC_TypeDef*)RCC_BASE)

#endif
