#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LED/LED_interface.h"
#include "HAL/CLCD/CLCD_interface.h"
#include "HAL/KPD/KPAD_interface.h"
#define F_CPU		8000000UL
#include <util/delay.h>



int main()
{
	KPAD_voidInit();                         
	CLCD_voidInit();

	u8 KpValue = KPAD_notpressed ;


	u8 entered_pass[4]					    ;
	u8 password[4] = {'1','2','3','4'}		;

	u8 i= 0  ;
	u8 j= 0  ;




	LED_t LEDs [] = {
			{DIO_PORTB,DIO_PIN0,LED_ACTIVE_HIGH}
			,{DIO_PORTB,DIO_PIN3,LED_ACTIVE_HIGH}

			,{DIO_PORTB,DIO_PIN4,LED_ACTIVE_HIGH}
			,{DIO_PORTB,DIO_PIN5,LED_ACTIVE_HIGH}
			,{DIO_PORTB,DIO_PIN6,LED_ACTIVE_HIGH}
			,{DIO_PORTB,DIO_PIN7,LED_ACTIVE_HIGH}
	};

	LED_voidInit(&LEDs[0]);
	LED_voidInit(&LEDs[1]);

	LED_voidInit(&LEDs[2]);
	LED_voidInit(&LEDs[3]);
	LED_voidInit(&LEDs[4]);
	LED_voidInit(&LEDs[5]);


	DIO_voidSetPinDirection(DIO_PORTC,DIO_PIN7,DIO_OUTPUT) ;
	DIO_voidSetPinDirection(DIO_PORTC,DIO_PIN6,DIO_OUTPUT) ;




	while(1)
	{	u8  correct_pass = 0;
	LED_voidOff(&LEDs[0]) ;
	LED_voidOff(&LEDs[1]) ;

	LED_voidOff(&LEDs[5]) ;





	CLCD_voidCLearDisplay() ;
	CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1) ;
	CLCD_voidSendString((u8 *)"Enter password:");
	CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);


	for (i=0 ; i<4 ; )
	{
		KpValue = KPAD_u8GetPressed();

		if(KpValue != KPAD_notpressed)
		{
			CLCD_voidSendData(KpValue);
			entered_pass[i] = KpValue;
			i++ ;

		}

	}



	for(u8 j =0 ; j < 4 ; j++)
	{
		if (entered_pass[j]==password[j])
		{
			correct_pass ++ ;
		}

	}

	CLCD_voidCLearDisplay() ;








	if(correct_pass==4)   //correct 1
	{
		//CLCD_voidSendString((u8 *)"welcome")  ;
		CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1) ;
		CLCD_voidSendString((u8 *)"Welcome To Motor");
		CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);
		CLCD_voidSendString((u8 *)"Dash Board");
		LED_voidOn(&LEDs[1]) ;
		_delay_ms(3000) ;






		///////////////////////////////////////////////////////////////////////////

		         KpValue = KPAD_notpressed ;

		         while (KpValue !='2')// Exit 2
		         {
		     		CLCD_voidCLearDisplay() ;
		     		CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1) ;
		     		CLCD_voidSendString((u8 *)"1.DC Motor");
		     		CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);
		     		CLCD_voidSendString((u8 *)"2.Exit");
		        		LED_voidOff(&LEDs[2]) ;

			         KpValue = KPAD_notpressed ;


		         	while(KpValue !='1' &&  KpValue !='2' )
		         	{

		         		KpValue = KPAD_u8GetPressed();

		         	}

		         	if(KpValue=='1')  //  DC Motor 2
		         	{
		         					LED_voidOn(&LEDs[2]) ;


		         		                           KpValue = KPAD_notpressed ;

		         		                           while(KpValue !='3') //BACK 3
		         		                           {
		         		      		         		CLCD_voidCLearDisplay();
		         		      		         		CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
		         		      		         		CLCD_voidSendString((u8 *)"1.LEFT") ;
		         		      		         		CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_9);
		         		      		         		CLCD_voidSendString((u8 *)"2.RIGHT") ;
		         		      		         		CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);
		         		      		         		CLCD_voidSendString((u8 *)"3.BACK") ;
		         		                        		LED_voidOff(&LEDs[3]) ;
		         		                        		LED_voidOff(&LEDs[4]) ;
			         		                           KpValue = KPAD_notpressed ;

		         		                        	  DIO_voidSetPinValue(DIO_PORTC , DIO_PIN6 , DIO_LOW);
		         		                        	  DIO_voidSetPinValue(DIO_PORTC , DIO_PIN7 , DIO_LOW);


		         		                                    while(KpValue !='1' && KpValue !='2'&& KpValue !='3' )
		         		                                    {

		         		                                    	KpValue = KPAD_u8GetPressed();

		         		                                    }

		         		                                    if(KpValue=='1')  //  left 3
		         		                                    {
		         		                                    	LED_voidOn(&LEDs[3]) ;
		         		                                    	CLCD_voidCLearDisplay() ;
		    		         		      		         		CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
		    		         		      		         		CLCD_voidSendString((u8 *)"ROTARE LEFT") ;
		         		                                    	DIO_voidSetPinValue(DIO_PORTC , DIO_PIN7 , DIO_LOW);
		         		                                    	DIO_voidSetPinValue(DIO_PORTC , DIO_PIN6 , DIO_HIGH);
		         		                                    	_delay_ms(3000);

		         		                                    }
		         		                                    else if(KpValue=='2')  //  Right3
		         		                                    {
		         		                                    	LED_voidOn(&LEDs[4]) ;
		         		                                    	CLCD_voidCLearDisplay() ;
		    		         		      		         		CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
		    		         		      		         		CLCD_voidSendString((u8 *)"ROTARE RIGHT") ;
		         		                                    	DIO_voidSetPinValue(DIO_PORTC , DIO_PIN6 , DIO_LOW);
		         		                                    	DIO_voidSetPinValue(DIO_PORTC , DIO_PIN7 , DIO_HIGH);
		         		                                    	_delay_ms(3000);

		         		                                    }

		         		                           }


		         	}




		         	else if (KpValue=='2')    // Exit 2
		         	{
	                  	LED_voidOn(&LEDs[5]) ;
		         		DIO_voidSetPinValue(DIO_PORTC , DIO_PIN6 , DIO_LOW);
		         		DIO_voidSetPinValue(DIO_PORTC , DIO_PIN7 , DIO_LOW);

		         	}









		         }

	}
	else    //  not correct
	{
		CLCD_voidSendString((u8 *)"not correct")  ;
		LED_voidOn(&LEDs[0]) ;
		_delay_ms(1000) ;




	}

	}
}





