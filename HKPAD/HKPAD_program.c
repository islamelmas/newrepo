/*
 * HKPAD_program.c
 *
 *  Created on: Apr 16, 2020
 *      Author: Mahmoud
 */
//Libraries

#include "../LIB_BMNP/LIB_BMNP.h"
#include "../LIB_STDTypes/LIB_STDTypes.h"
#include "../Platform/ATMEGA32_Features.h"

#include "../CSWC_PLT_MCU_ATMEGA32/MDIO/MDIO_Int.h"

#include "HKPAD_Interface.h"


void HKPAD_Init()
{
DDRD=0xF0;
PORTD=0xFF;
}
void HKPAD_GetKeyValue(pu8 HKPAD_SW_NO)
{
u8 col,row;
u8 rowno;
for(col=4;col<=7;col++)
{    MDIO_enuSetPinValue(MDIO_PORTD,col,0);
	for (row=0;row<=3;row++)
	{
		MDIO_enuGetPinValue(MDIO_PORTD,row,&rowno);
		if(rowno==0)
			*(HKPAD_SW_NO)=(row*4)+(col-4);;

	}
	  MDIO_enuSetPinValue(MDIO_PORTD,col,1);
}
}


