/*
 * NVIC_program.c
 *
 *  Created on: 7 Jul 2023
 *      Author: kareem
 */
#include<stdint.h>
#include"../../../Library/stm32f446xx.h"
#include"../../../Library/ErrType.h"
#include"../inc/NVIC_interface.h"
#include"../inc/NVIC_prv.h"

uint8_t NVIC_u8EnableInterrupt(NVIC_IQR_ty perpheral)
{
    uint8_t Local_u8ErrorStatus= OK;
    uint8_t BitNumber= perpheral%32;
    uint8_t RegNumber= perpheral/32;
    if (240>=perpheral)
    {
        NVIC->NVIC_ISER[RegNumber] = 1 << BitNumber;
    }
    else
    {
        Local_u8ErrorStatus=NOK;
    }
    return Local_u8ErrorStatus;
}
uint8_t NVIC_u8DisableInterrupt(NVIC_IQR_ty perpheral)
{
    uint8_t Local_u8ErrorStatus= OK;
    uint8_t BitNumber= perpheral%32;
    uint8_t RegNumber= perpheral/32;
    if (240>=perpheral)
    {
        NVIC->NVIC_ICER[RegNumber] = 1 << BitNumber;
    }
    else
    {
        Local_u8ErrorStatus=NOK;
    }
    return Local_u8ErrorStatus;
}
uint8_t NVIC_u8SetPandingFlag(NVIC_IQR_ty perpheral)
{
    uint8_t Local_u8ErrorStatus= OK;
    uint8_t BitNumber= perpheral%32;
    uint8_t RegNumber= perpheral/32;
    if (240>=perpheral)
    {
        NVIC->NVIC_ISPR[RegNumber] = 1 << BitNumber;
    }
    else
    {
        Local_u8ErrorStatus=NOK;
    }
    return Local_u8ErrorStatus;
}
uint8_t NVIC_u8ClearPandingFlag(NVIC_IQR_ty perpheral)
{
    uint8_t Local_u8ErrorStatus= OK;
    uint8_t BitNumber= perpheral%32;
    uint8_t RegNumber= perpheral/32;
    if (240>=perpheral)
    {
        NVIC->NVIC_ICPR[RegNumber] = 1 << BitNumber;
    }
    else
    {
        Local_u8ErrorStatus=NOK;
    }
    return Local_u8ErrorStatus;
}
uint8_t NVIC_u8setIQRpriority(NVIC_IQR_ty perpheral,uint8_t prority)
{
    uint8_t Local_u8ErrorStatus= OK;
    if (240>=perpheral)
    {
        NVIC->NVIC_IPR[perpheral] = (prority << 4);
    }
    else
    {
        Local_u8ErrorStatus=NOK;
    }
    return Local_u8ErrorStatus;
}