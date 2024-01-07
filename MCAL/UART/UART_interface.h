/*
 * UART_interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: First
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

void UART_voidInit	(void);

void UART_voidSendDataSync	(u8 Copy_u8Data);

void UART_voidRecvDataSync	(u8 *Copy_pu8RecievedData);

#endif /* MCAL_UART_UART_INTERFACE_H_ */
