/*
 * main.h
 *
 *  Created on: May 22, 2020
 *      Author: Mahmoud
 */

#ifndef MAIN_H_
#define MAIN_H_
#undef F_CPU
#define F_CPU 8000000u
#include "util/delay.h"
#include"LIB_BMNP/LIB_BMNP.h"
#include "LIB_STDTypes/LIB_STDTypes.h"
#include"Platform/ATMEGA32_Features.h"
#include"CSWC_PLT_MCU_ATMEGA32/MDIO/MDIO_Int.h"
#include "CSWC_PLT_MCU_ATMEGA32/MDIO/MDIO_Config.h"
#include "CSWC_PLT_MCU_ATMEGA32/MINT/MINT_inteface.h"
#include "HKPAD/HKPAD_Interface.h"
#include "HLCD/HLCD_int.h"

u8 CALC_Num(u8 keypad) {

	u8 value;
	switch (keypad)
	{
	case 0:
		 value='7';
		break;
	case 1:
		value='8';
		break;
	case 2:
		 value='9';
		break;
	case 3:
		value='/';
		break;
	case 4:
		 value='4';
		break;
	case 5:
		value='5';
		break;
	case 6:
		 value='6';
		break;
	case 7:
		value='*';
		break;
	case 8:
		 value='1';
		break;
	case 9:
		value='2';
		break;
	case 10:
		value='3';
		break;
	case 11:
			value='-';
			break;
	case 12:
		value='a';
			break;
	case 13:
			value='0';
			break;
	case 14:
			value='=';
			break;
	case 15:
			value='+';
			break;
	}
	return value;
}
u16 pow(u16 number,u16 power)
{
u16 value=0;
for(u16 i=0;i<=power;i++)
{
if (i==0)
	value=1;
else
value*=number;
	}
return value;
}
u16 Calc_Convert_to_number(u8* ptrarr,u8 size_of_arr)
{
	u16 value=0;
for(u8 i=0;i<=size_of_arr;i++)
{
	value=value+(((ptrarr[i]))*(pow(10,size_of_arr-i)));

}
return value;

}


#endif /* MAIN_H_ */
