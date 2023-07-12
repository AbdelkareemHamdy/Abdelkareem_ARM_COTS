#ifndef SYSTICK_PRV_H_
#define SYSTICK_PRV_H_

/*prived elemints */
#define ONE_BIT_MASKING	    		0b1U
#define MilySec_TIME_atAHBdiv8		2000U
#define MilySec_TIME_atAHB			16000U
#define MicroSec_TIME_atAHBdiv8	    2U
#define MicroSec_TIME_atAHB	    	16U
#define NUMBER_OF_STKLOADBITSdiv8	23U
#define NUMBER_OF_STKLOADBITS	   	21U
typedef enum
{
	STK_CTRL_ENABLE		=0,
	STK_CTRL_TICKINT	=1,
	STK_CTRL_CLKSOURCE	=2,
	STK_CTRL_COUNTFLAG	=16,
}STK_CTRL_bits_t;

#endif