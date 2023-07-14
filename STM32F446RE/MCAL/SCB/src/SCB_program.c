/*
 * SCB_program.c
 *
 *  Created on: 14 Jul 2023
 *      Author: kareem
 */


#include<stdint.h>
#include"../../../Library/stm32f446xx.h"
#include"../../../Library/ErrType.h"
#include"../inc/SCB_interface.h"
#include"../inc/SCB_prv.h"
void SCB_voidSetPriorityGroup(uint8_t Copy_u8PriorityGroup)
{
    SCB->SCB_AIRCR = (SCB_VECTKEY<<16)|(Copy_u8PriorityGroup<<8); 
}