#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_
typedef enum
{
	SYSTICK_COUNTER_DISABLE=0,
	SYSTICK_COUNTER_ENABLE=1,
}SYSTICKCounter_state_t;
typedef enum
{
	SYSTICK_CS_AHB_8=0,
	SYSTICK_CS_AHB=1,
}SYSTICKCounter_ClockSource_t;

uint8_t Systick_u8Enable(SYSTICKCounter_state_t State,SYSTICKCounter_ClockSource_t ClockSource,uint32_t Copy_u32ReloadValue);
void Systick_voidDelayms(uint32_t Coupy_u32NumberOf_ms);
void Systick_voidDelayMicrosec(uint32_t Coupy_u32NumberOf_Microsec);

#endif