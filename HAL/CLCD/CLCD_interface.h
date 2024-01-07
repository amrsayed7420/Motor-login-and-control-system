/*******************************************************/
/****   Author : Mohamed khaled       ******************/
/****   SWC:          CLCD             ******************/
/****   Date :        5/8/2023        ******************/
/****   Version : 1.00                ******************/
/*******************************************************/
#ifndef HAL_CLCD_CLCD_INTERFACE_H_
#define HAL_CLCD_CLCD_INTERFACE_H_

#define CLCD_ROW_1		0
#define CLCD_ROW_2		1

#define CLCD_COL_1		 0
#define CLCD_COL_2		 1
#define CLCD_COL_3		 2
#define CLCD_COL_4		 3
#define CLCD_COL_5		 4
#define CLCD_COL_6		 5
#define CLCD_COL_7		 6
#define CLCD_COL_8		 7
#define CLCD_COL_9		 8
#define CLCD_COL_10		 9
#define CLCD_COL_11		 10
#define CLCD_COL_12		 11
#define CLCD_COL_13		 12
#define CLCD_COL_14		 13
#define CLCD_COL_15		 14
#define CLCD_COL_16		 15

#define CLCD_CLEAR_DISPLAY			0x01
#define CLCD_SHIFT_LEFT_DISPLAY		0b00011000
#define CLCD_SHIFT_RIGHT_DISPLAY	0b00011100



void CLCD_voidInit		(	void	);

void CLCD_voidSendCommand	(u8 Copy_u8Command	);
void CLCD_voidSendData		(u8 Copy_u8Data		);

void CLCD_voidSetPosition	(u8 Copy_u8Row , u8 Copy_u8Col);

void CLCD_voidSendExtraChar	(u8 Copy_u8PatternLocation , u8 * Copy_pu8ExtraChar , u8 Copy_u8Row , u8 Copy_u8Col );

void CLCD_voidSendString	(u8 *Copy_pu8String );


void CLCD_voidSendNumber	(u64 Copy_u64Number);

void CLCD_voidCLearDisplay(void) ;


void CLCD_voidSHIFT_LEFT_DISPLAY    (u8 *Copy_u8Data,u8 Copy_u8Row);
void CLCD_voidSHIFT_RIGHT_DISPLAY   (u8 Copy_u8Data,u8 Copy_u8Row);


#endif /* HAL_CLCD_CLCD_INTERFACE_H_ */
