/*
 * UART_program.c
 *
 *  Created on: Aug 21, 2023
 *      Author: First
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"



void UART_voidInit	(void)
{
	UCSRB_REG = 0b00011000 ;

	/*Config USCRC */
	u8 Local_u8Var	= 0b10000000 ;
	/*	Async	*/
	CLR_BIT(Local_u8Var , 6 );
	/*	Disable parity */
	CLR_BIT(Local_u8Var , 5);
	CLR_BIT(Local_u8Var , 4);
	/*	1 Stop Bit */
	CLR_BIT(Local_u8Var , 3);
	/*	8 Bit Mode , UCS2 -- > 0 , UCS1,0 --> 1 */
	SET_BIT(Local_u8Var , 2 );
	SET_BIT(Local_u8Var , 1 );
		/*CPOL --> Leading Edge ( Raising )*/
	CLR_BIT(Local_u8Var , 0 );

	UCSRC_REG = Local_u8Var ;

	/*Baud Rate */
	UBRRL_REG = (u8)	 UART_BAUD_RATE;
	UBRRH_REG = (u8)	(UART_BAUD_RATE >> 8 );

}

void UART_voidSendDataSync	(u8 Copy_u8Data)
{
	/*Check if buffer is empty */
	while ( GET_BIT(UCSRA_REG , 5) == 0 );

	/*Send Data */
	UDR_REG = Copy_u8Data ;
}

void UART_voidRecvDataSync	(u8 *Copy_pu8RecievedData)
{
	/*Wait untill Recieve Data */
	while ( GET_BIT(UCSRA_REG , 7 ) == 0 ) ;
	if(Copy_pu8RecievedData != NULL)
	{
		*Copy_pu8RecievedData = UDR_REG ;
	}
}

