/*
 * EXTI_program.c
 *
 *  Created on: 15 Jul 2023
 *      Author: kareem
 */


#include <stdint.h>
#include "../../Library/stm32f446xx.h"
#include "../../Library/ErrType.h"

#include "../Inc/EXTI_interface.h"
#include "../Inc/EXTI_prv.h"

uint8_t EXTI_u8Init(EXTI_CONFIG_ty *Config)
{
    uint8_t Local_u8ErrorState = OK;
	if(((Config->Port) <= EXTI_PORTH)&&((Config->Line) <= EXTI_PIN15))
	{
		/*Rising edge set*/
		EXTI->EXTI_RTSR &=~(1<<(Config->Line));/*Bit Masking*/
		EXTI->EXTI_RTSR |= ((Config->RisingEdgeState)<<(Config->Line));
		/*falling edge set*/
		EXTI->EXTI_FTSR &=~(1<<(Config->Line));/*Bit Masking*/
		EXTI->EXTI_FTSR |= ((Config->FallingEdgeState)<<(Config->Line));
		/*Set callback function*/
		if (NULL!=(Config->Copy_pvUserFunc))
		{
			EXTI_pvGlobCallBackLine[Config->Line] = (Config->Copy_pvUserFunc);
		}
		/*Interrupt set*/
		EXTI->EXTI_IMR &=~(1<<(Config->Line));/*Bit Masking*/
		EXTI->EXTI_IMR |=((Config->InterruptState)<<(Config->Line));
		/*event Set*/
		/*
		EXTI->EXTI_EMR &=~(1<<(Config->Line));/*Bit Masking
		EXTI->EXTI_EMR |=((Config->EventState)<<(Config->Line));
		*/
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return  Local_u8ErrorState ;
}

uint8_t EXTI_u8DoSoftwareInterrupt(EXTI_Line_ty Line)
{
	uint8_t Local_u8ErrorState = OK;
	if(((Line) <= EXTI_PIN15))
	{
		/*Software Inturrept set*/
		EXTI->EXTI_SWIER =(1<<Line);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return  Local_u8ErrorState ;
}
uint8_t EXTI_u8ClearPendingFlag(EXTI_Line_ty Line)
{
	uint8_t Local_u8ErrorState = OK;
	if(((Line) <= EXTI_PIN15))
	{
		/*Clear Pending Flag*/
		EXTI->EXTI_PR =(1<<Line);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return  Local_u8ErrorState ;
}
uint8_t EXTI_u8ReadPendingFlag(EXTI_Line_ty Line,EXTI_Flag_STATUS_ty *FlagValue)
{
	uint8_t Local_u8ErrorState = OK;
	if(((Line) <= EXTI_PIN15))
	{
		/*Clear Pending Flag*/
		*FlagValue = ((EXTI->EXTI_PR) >>Line) & 1U;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return  Local_u8ErrorState ;
}
void EXTI_voidReadAllPendingFlag(uint32_t *RegisterValue)
{
	*RegisterValue = (EXTI->EXTI_PR);
}
/*ISR Functions*/
void EXTI0_IRQHandler(void)
{
	if (NULL!=EXTI_pvGlobCallBackLine[0])
	{
		EXTI_pvGlobCallBackLine[0]();
	}
	
}
void EXTI1_IRQHandler(void)
{
	if (NULL!=EXTI_pvGlobCallBackLine[1])
	{
		EXTI_pvGlobCallBackLine[1]();
	}
	
}
void EXTI2_IRQHandler(void)
{
	if (NULL!=EXTI_pvGlobCallBackLine[2])
	{
		EXTI_pvGlobCallBackLine[2]();
	}
	
}
void EXTI3_IRQHandler(void)
{
	if (NULL!=EXTI_pvGlobCallBackLine[3])
	{
		EXTI_pvGlobCallBackLine[3]();
	}
	
}
void EXTI4_IRQHandler(void)
{
	if (NULL!=EXTI_pvGlobCallBackLine[4])
	{
		EXTI_pvGlobCallBackLine[4]();
	}
	
}
void EXTI9_5_IRQHandler(void)
{
	if(((EXTI->EXTI_PR)>>5)& 1)
	{
		if (NULL!=EXTI_pvGlobCallBackLine[5])
		{
			EXTI_pvGlobCallBackLine[5]();
		}
	}
	if(((EXTI->EXTI_PR)>>6)& 1)
	{
		if (NULL!=EXTI_pvGlobCallBackLine[6])
		{
			EXTI_pvGlobCallBackLine[6]();
		}
	}
	if(((EXTI->EXTI_PR)>>7)& 1)
	{
		if (NULL!=EXTI_pvGlobCallBackLine[7])
		{
			EXTI_pvGlobCallBackLine[7]();
		}
	}
	if(((EXTI->EXTI_PR)>>8)& 1)
	{
		if (NULL!=EXTI_pvGlobCallBackLine[8])
		{
			EXTI_pvGlobCallBackLine[8]();
		}
	}
	if(((EXTI->EXTI_PR)>>9)& 1)
	{
		if (NULL!=EXTI_pvGlobCallBackLine[9])
		{
			EXTI_pvGlobCallBackLine[9]();
		}
	}
}
void EXTI15_10_IRQHandler(void)
{
	if(((EXTI->EXTI_PR)>>10)& 1)
	{
		if (NULL!=EXTI_pvGlobCallBackLine[10])
		{
			EXTI_pvGlobCallBackLine[10]();
		}
	}
	if(((EXTI->EXTI_PR)>>11)& 1)
	{
		if (NULL!=EXTI_pvGlobCallBackLine[11])
		{
			EXTI_pvGlobCallBackLine[11]();
		}
	}
	if(((EXTI->EXTI_PR)>>12)& 1)
	{
		if (NULL!=EXTI_pvGlobCallBackLine[12])
		{
			EXTI_pvGlobCallBackLine[12]();
		}
	}
	if(((EXTI->EXTI_PR)>>13)& 1)
	{
		if (NULL!=EXTI_pvGlobCallBackLine[13])
		{
			EXTI_pvGlobCallBackLine[13]();
		}
	}
	if(((EXTI->EXTI_PR)>>14)& 1)
	{
		if (NULL!=EXTI_pvGlobCallBackLine[14])
		{
			EXTI_pvGlobCallBackLine[14]();
		}
	}if(((EXTI->EXTI_PR)>>15)& 1)
	{
		if (NULL!=EXTI_pvGlobCallBackLine[15])
		{
			EXTI_pvGlobCallBackLine[15]();
		}
	}
}