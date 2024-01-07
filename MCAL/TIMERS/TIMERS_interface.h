/*
 * TIMERS_interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: First
 */

#ifndef MCAL_TIMERS_TIMERS_INTERFACE_H_
#define MCAL_TIMERS_TIMERS_INTERFACE_H_


#define TIMER0_OVERFLOW				0
#define TIMER0_CTC				1




#define CTC_MODE	1
#define FAST_PWM	2


#define T1_ICU_CALLBACK					0
#define T1_CHANNEL_A_CALLBACK			1
#define T1_CHANNEL_B_CALLBACK			2
#define T1_OVF_CALLBACK					3




void TIMERS_voidT0Init	(void);

void TIMERS_voidSetPreloadValT0	(u8 Copy_u8PreloadValue );

void TIMERS_voidSetComapreMatchValueT0	( u8 Copy_u8CompareValue );

void TIMERS_T0SetCallBack	(u8 Copy_u8T0Mode , void (*Pf) (void)	);







void TIMERS_voidT1Init	(void);
void TIMERS_voidSetCompareMatchValueT1A	(u16 Copy_u16ComapreMatchValue );
void TIMERS_voidSetICRValueT1		(u16 Copy_u16ICRValue );

void TIMERS_T1SetCallBack		(u8 Copy_u8T1Mode , void(*PF)(void));

void TIMERS_voidSetBusyWait		(u32 Copy_u32BusyUSeconds	);



void TIMERS_voidSetPreloadValT1	(u16 Copy_u16PreloadValue );
//u16 TIMERS_u16GetCounterRegisterValue	(void);


#endif /* MCAL_TIMERS_TIMERS_INTERFACE_H_ */
