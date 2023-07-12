/*******************************************************************
 * @SYSTICK_prog.c
 * @author Abdelkareem Hamdy
 * @brief The SYSTICK source file, inluding functions' definitions
 *  Created on: May 11 ,2023 
 *          Author Abdelkareem
*/
#include <stdint.h>
#include "stm32f103xx.h"
#include "ErrType.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_prv.h"

/**********************************************************************
 * @fn 
 * 
 * 
*/
uint8_t Systick_u8Enable(SYSTICKCounter_state_t State,SYSTICKCounter_ClockSource_t ClockSource,uint32_t Copy_u32ReloadValue)
{
    uint8_t LocalState_ERROR = OK;
    if ((State<=SYSTICK_COUNTER_ENABLE) && (ClockSource<=SYSTICK_CS_AHB) && (Copy_u32ReloadValue<0xFFFFFFF))
    {
        SYSTICK->STK_LOAD = Copy_u32ReloadValue;
        SYSTICK->STK_CTRL &=~(ONE_BIT_MASKING<<STK_CTRL_CLKSOURCE);
        SYSTICK->STK_CTRL |=(ClockSource<<STK_CTRL_CLKSOURCE);
        SYSTICK->STK_CTRL &=~(ONE_BIT_MASKING<<STK_CTRL_ENABLE);
        SYSTICK->STK_CTRL |=(State<<STK_CTRL_ENABLE);
    }
    else
    {
        LocalState_ERROR = NOK;
    }
    return LocalState_ERROR;
}

void Systick_voidDelayms(uint32_t Coupy_u32NumberOf_ms)
{
    Systick_u8Enable(SYSTICK_COUNTER_ENABLE,SYSTICK_CS_AHB_8,MilySec_TIME_atAHBdiv8);
    for (; Coupy_u32NumberOf_ms > 0; Coupy_u32NumberOf_ms--)
    {
        while (((SYSTICK->STK_CTRL>>STK_CTRL_COUNTFLAG)&1)==0);
    }
    SYSTICK->STK_CTRL &=~(ONE_BIT_MASKING<<STK_CTRL_ENABLE);
}
void Systick_voidDelayMicrosec(uint32_t Coupy_u32NumberOf_Microsec)
{
    Systick_u8Enable(SYSTICK_COUNTER_ENABLE,SYSTICK_CS_AHB_8,Coupy_u32NumberOf_Microsec*MicroSec_TIME_atAHBdiv8);
    Coupy_u32NumberOf_Microsec = (Coupy_u32NumberOf_Microsec>>(NUMBER_OF_STKLOADBITSdiv8));
    while (((SYSTICK->STK_CTRL>>STK_CTRL_COUNTFLAG)&1)==0);
    SYSTICK->STK_CTRL &=~(ONE_BIT_MASKING<<STK_CTRL_ENABLE);
    if(Coupy_u32NumberOf_Microsec!=0)
    {
        Systick_u8Enable(SYSTICK_COUNTER_ENABLE,SYSTICK_CS_AHB_8,Coupy_u32NumberOf_Microsec*MicroSec_TIME_atAHBdiv8);
        while (((SYSTICK->STK_CTRL>>STK_CTRL_COUNTFLAG)&1)==0);
    }
    SYSTICK->STK_CTRL &=~(ONE_BIT_MASKING<<STK_CTRL_ENABLE);
}