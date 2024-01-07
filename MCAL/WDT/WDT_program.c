/*
 * WDT.program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo
 */


/*	Include LIB	*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* EXTI includes */

#include "WDT_interface.h"
#include "WDT_private.h"




//	SET_BIT(WDTCR_REG ,  1 );
//	CLR_BIT(WDTCR_REG ,  0 );

void WDT_VoidEnable (void)
{

	SET_BIT(WDTCR_REG ,  0 );
	SET_BIT(WDTCR_REG ,  1 );
	SET_BIT(WDTCR_REG ,  2 );


	SET_BIT(WDTCR_REG ,  3 );



}

void WDT_VoidDisable (void)
{


	CLR_BIT(WDTCR_REG ,  3 );

	SET_BIT(WDTCR_REG ,  4 );


}
