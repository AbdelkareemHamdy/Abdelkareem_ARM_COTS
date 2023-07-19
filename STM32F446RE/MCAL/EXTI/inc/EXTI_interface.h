/*
 * EXTI_interface.h
 *
 *  Created on: 15 Jul 2023
 *      Author: kareem
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


typedef enum
{
    EXTI_PORTA =0U,
    EXTI_PORTB,
    EXTI_PORTC,
    EXTI_PORTD,
    EXTI_PORTE,
    EXTI_PORTF,
    EXTI_PORTG,
    EXTI_PORTH
}EXTI_port_ty;
typedef enum
{
    EXTI_PIN00 =0U,
    EXTI_PIN01,
    EXTI_PIN02,
    EXTI_PIN03,
    EXTI_PIN04,
    EXTI_PIN05,
    EXTI_PIN06,
    EXTI_PIN07,
    EXTI_PIN08,
    EXTI_PIN09,
    EXTI_PIN10,
    EXTI_PIN11,
    EXTI_PIN12,
    EXTI_PIN13,
    EXTI_PIN14,
    EXTI_PIN15
}EXTI_Line_ty;

typedef enum
{
    EXTI_DISABLE =0U,
    EXTI_ENABLE
}EXTI_STATUS_ty;

typedef struct
{
    EXTI_port_ty Port;
    EXTI_Line_ty Line;
    EXTI_STATUS_ty InterruptState;
    EXTI_STATUS_ty EventState;
    EXTI_STATUS_ty RisingEdgeState;
    EXTI_STATUS_ty FallingEdgeState;
    void (*Copy_pvUserFunc)(void);
}EXTI_CONFIG_ty;
typedef enum
{
    EXTI_FLAG_NOT_RISE =0U,
    EXTI_FLAG_RISE
}EXTI_Flag_STATUS_ty;

uint8_t EXTI_u8Init(EXTI_CONFIG_ty *Config);
uint8_t EXTI_u8DoSoftwareInterrupt(EXTI_Line_ty Line);
uint8_t EXTI_u8ClearPendingFlag(EXTI_Line_ty Line);
uint8_t EXTI_u8ReadPendingFlag(EXTI_Line_ty Line,EXTI_Flag_STATUS_ty *FlagValue);
void EXTI_voidReadAllPendingFlag(uint32_t *RegisterValue);

#endif /* EXTI_INTERFACE_H_ */
