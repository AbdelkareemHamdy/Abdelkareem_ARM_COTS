#ifndef STM32F446XX_H
#define STM32F446XX_H
/******************** Various Memories Base Addresses *****************/
#define FLASH_BASE_ADDRESS		0X08000000UL
#define SRAM_BASE_ADDRESS		0X20000000UL
#define ROM_BASE_ADDRESS		0X1FFF0000UL/*UNsure*/


/******************** AHB1 Peripheral Base Addresses *****************/
#define GPIOA_BASE_ADDRESS		0x40010800UL
#define GPIOB_BASE_ADDRESS		0x40010C00UL
#define GPIOC_BASE_ADDRESS		0x40011000UL
#define GPIOD_BASE_ADDRESS		0x40011400UL
#define GPIOE_BASE_ADDRESS		0x40011800UL
#define GPIOF_BASE_ADDRESS		0x40011C00UL
#define GPIOG_BASE_ADDRESS		0x40012000UL
					
#define RCC_BASE_ADDRESS		  0x40021000UL

/******************** Processsor Peripheral Base Addresses *****************/
#define SYSTICK_BASE_ADDRESS	0xE000E010UL


/******************** AHB2 Peripheral Base Addresses *****************/

/******************** AHB3 Peripheral Base Addresses *****************/


/******************** APB1 Peripheral Base Addresses *****************/


/******************** APB2 Peripheral Base Addresses *****************/

/******************** RCC Register Definition Structure *****************/
typedef struct
{
	uint32_t RCC_CR;
	uint32_t RCC_CFGR;
	uint32_t RCC_CIR;
	uint32_t RCC_APB2STR;
	uint32_t RCC_APB1STR;
	uint32_t RCC_AHBENR;
	uint32_t RCC_APB2ENR;
	uint32_t RCC_APB1ENR;
	uint32_t RCC_BDCR;
	uint32_t RCC_CSR;
}RCC_Reg_t;

/******************** GPIO Register Definition Structure *****************/
typedef struct
{
	volatile uint32_t GPIO_CRL[2];
  	volatile uint32_t GPIO_IDR;
	volatile uint32_t GPIO_ODR;
	volatile uint32_t GPIO_BSRR;
	volatile uint32_t GPIO_BRR;
	volatile uint32_t GPIO_LCKR;
}GPIO_RegDef_t;

/******************** SYSTICK Register Definition Structure *****************/
typedef struct
{
	volatile uint32_t STK_CTRL;
	volatile uint32_t STK_LOAD;
	volatile uint32_t STK_VAL;
	volatile uint32_t STK_CALIB;
}SYSTICK_RegDef_t;

/******************** SYSTICK Peripheral Definition *****************/
#define SYSTICK	((SYSTICK_RegDef_t*)SYSTICK_BASE_ADDRESS)

/******************** GPIO Peripheral Definition *****************/

#define GPIOA	((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB	((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC	((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
#define GPIOD	((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
#define GPIOE	((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
#define GPIOF	((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
#define GPIOG	((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)

/******************** RCC Peripheral Definition *****************/

#define RCC	((RCC_Reg_t*)RCC_BASE_ADDRESS)


#endif
