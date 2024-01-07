/*
 * TIMERS_program.c
 *
 *  Created on: Aug 15, 2023
 *      Author: First
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"



static void (*Glo_ApfNotification_timer [2] ) ( void ) = { NULL , NULL } ;

static void (*GloPFChannelA_Notification)(void) = NULL ;




void TIMERS_voidT0Init	(void)
{

	/*		OVF Mode	*/
//	CLR_BIT(TCCR0_REG , 6 );
//	CLR_BIT(TCCR0_REG , 3 );

	/* CTC Mode */
//		CLR_BIT(TCCR0_REG , 6 );
//		SET_BIT(TCCR0_REG , 3 );

	/* FAST PWM Mode */
		SET_BIT(TCCR0_REG , 6 );
		SET_BIT(TCCR0_REG , 3 );

	/* OC0 Disconnected */
//	CLR_BIT(TCCR0_REG , 5);
//	CLR_BIT(TCCR0_REG , 4);

	/* OC0 NON INTERTING */
	SET_BIT(TCCR0_REG , 5);
	CLR_BIT(TCCR0_REG , 4);



	/* Enable PIE */
	/*PIE OVF*/
//	SET_BIT(TIMSK_REG , 0 );
	/* PIE CTC*/
//	SET_BIT(TIMSK_REG , 1 );

	//OCR0_REG = COMPARE_MATCH_VALUE ;
	/*Start Timer , with prescaler 8 */
	CLR_BIT(TCCR0_REG , 2 );
	SET_BIT(TCCR0_REG , 1 );
	CLR_BIT(TCCR0_REG , 0 );

//
////	//1 1 0 External clock source on T0 pin. Clock on falling edge.
//	SET_BIT(TCCR0_REG , 2 );
//	SET_BIT(TCCR0_REG , 1 );
//	CLR_BIT(TCCR0_REG , 0 );

}
void TIMERS_voidSetPreloadValT0	(u8 Copy_u8PreloadValue )
{
	TCNT0_REG = Copy_u8PreloadValue ;
}
void TIMERS_voidSetComapreMatchValueT0	( u8 Copy_u8CompareValue )
{
	OCR0_REG = Copy_u8CompareValue ;
}










void TIMERS_T0SetCallBack	(u8 Copy_u8T0Mode , void (*Pf) (void)	)
{
	if ( Pf != NULL )
	{
		switch( Copy_u8T0Mode )
		{
		case TIMER0_OVERFLOW :
			Glo_ApfNotification_timer[0] = Pf ;
			break ;
		case TIMER0_CTC :
			Glo_ApfNotification_timer[1] = Pf ;

			break ;

		default:
			break;
		}
	}
}
/* ISR for timer0 overflow */
void __vector_11	(void)	__attribute__((signal));
void __vector_11	(void)
{
	if (Glo_ApfNotification_timer[0] != NULL)
	{
		Glo_ApfNotification_timer[0]();
	}


}
/* ISR for timer0 CTC */
void __vector_10	(void)	__attribute__((signal));
void __vector_10 (void)
{
	if (Glo_ApfNotification_timer[1] != NULL)
	{
		Glo_ApfNotification_timer[1]();
	}


}

/*==============================================*/
/*			TIMER1				*/
void TIMERS_voidT1Init	(void)
{
#if TIMERS_T1_MODE == FAST_PWM
	/*Fast PWM	(14) --> TOP = ICR1 */
	CLR_BIT(TCCR1A_REG , 0 );
	SET_BIT(TCCR1A_REG , 1);
	SET_BIT(TCCR1B_REG , 3 );
	SET_BIT(TCCR1B_REG , 4 );
#elif	TIMERS_T1_MODE == CTC_MODE
		CLR_BIT(TCCR1A_REG , 0 );
		CLR_BIT(TCCR1A_REG , 1);
		SET_BIT(TCCR1B_REG , 3 );
		CLR_BIT(TCCR1B_REG , 4 );
#endif

	/* NonInverted Mode */
	SET_BIT(TCCR1A_REG , 7);
	CLR_BIT(TCCR1A_REG , 6 );



	/* SET ICR1 (TOP) */
	TIMERS_voidSetICRValueT1(20000);


	/* PIE CTC For TIMER1 Channel A*/
//	SET_BIT(TIMSK_REG , 4);


	/* Prescaler  = /8 */
	CLR_BIT(TCCR1B_REG , 0 );
	SET_BIT(TCCR1B_REG , 1 );
	CLR_BIT(TCCR1B_REG , 2 );

}

void TIMERS_voidSetCompareMatchValueT1A	(u16 Copy_u16ComapreMatchValue )
{
	/*	CTC TIME , COMPARE MATCH VALUE */
	/*	For Setting Duty Cycle */
	OCR1A_REG = Copy_u16ComapreMatchValue ;
}
void TIMERS_voidSetICRValueT1		(u16 Copy_u16ICRValue )
{
	ICR1_REG = Copy_u16ICRValue ;
}
void TIMERS_voidSetBusyWait		(u32 Copy_u32BusyUSeconds	)
{

	u32	Local_u32Counter	=	(u32)( Copy_u32BusyUSeconds ) / (T1_CMPR_MATCH_CHA_VALUE);
	for(u32 Local_u32Iterator = 0 ; Local_u32Iterator < Local_u32Counter ; Local_u32Iterator++)
	{
		/*Wait until flag raised*/
		while(GET_BIT(TIFR_REG , 4) == 0 );
		SET_BIT(TIFR_REG  , 4 );
	}
}
void TIMERS_T1SetCallBack		(u8 Copy_u8T1Mode , void(*PF)(void))
{
	if ( PF != NULL)
	{

	switch(Copy_u8T1Mode )
	{
	case T1_CHANNEL_A_CALLBACK :
		GloPFChannelA_Notification = PF ;
		break;
	case T1_CHANNEL_B_CALLBACK :
		break;
	case T1_OVF_CALLBACK:
		break;
	default :
		break;
	}
	}
}

void __vector_7	(void) __attribute__((signal));
void __vector_7	(void)
{

	if(GloPFChannelA_Notification != NULL)
	{
		GloPFChannelA_Notification();
	}
//	static u16 Counter = 0 ;
//	Counter ++ ;
//	if(GloPFChannelA_Notification != NULL)
//	{
//		if(Counter == T1_SW_COUNTER_CTC_CHANNEL_A )
//		{
//
//		GloPFChannelA_Notification();
//		Counter = 0;
//		}
//	}
}


void TIMERS_voidSetPreloadValT1	(u16 Copy_u16PreloadValue )
{
	TCNT1_REG = Copy_u16PreloadValue ;
}
//u16 TIMERS_u16GetCounterRegisterValue	(void)
//{
//	return TCNT1_REG ;
//}
