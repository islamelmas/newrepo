/*
 * MDIO_prg.c
 *
 *  Created on: Apr 6, 2020
 *      Author: Mahmoud
 */
//Libraries
#include "../../Platform/ATMEGA32_Features.h"
#include "../../LIB_BMNP/LIB_BMNP.h"
#include "../../LIB_STDTypes/LIB_STDTypes.h"
//MCAL
#include "MDIO_Config.h"
#include "MDIO_private.h"
#include "MDIO_Int.h"



void MDIO_Int(void)
{
DDRA=conc(MDIO_DIR_PINNO_7,MDIO_DIR_PINNO_6,MDIO_DIR_PINNO_5,MDIO_DIR_PINNO_4,MDIO_DIR_PINNO_3,MDIO_DIR_PINNO_2,MDIO_DIR_PINNO_1,MDIO_DIR_PINNO_0);
DDRB=conc(MDIO_DIR_PINNO_15,MDIO_DIR_PINNO_14,MDIO_DIR_PINNO_13,MDIO_DIR_PINNO_12,MDIO_DIR_PINNO_11,MDIO_DIR_PINNO_10,MDIO_DIR_PINNO_9,MDIO_DIR_PINNO_8);
DDRC=conc(MDIO_DIR_PINNO_23,MDIO_DIR_PINNO_22,MDIO_DIR_PINNO_21,MDIO_DIR_PINNO_20,MDIO_DIR_PINNO_19,MDIO_DIR_PINNO_18,MDIO_DIR_PINNO_17,MDIO_DIR_PINNO_16);
DDRD=conc(MDIO_DIR_PINNO_31,MDIO_DIR_PINNO_30,MDIO_DIR_PINNO_29,MDIO_DIR_PINNO_28,MDIO_DIR_PINNO_27,MDIO_DIR_PINNO_26,MDIO_DIR_PINNO_25,MDIO_DIR_PINNO_24);

PORTA=conc(MDIO_PORT_NO_7,MDIO_PORT_NO_6,MDIO_PORT_NO_5,MDIO_PORT_NO_4,MDIO_PORT_NO_3,MDIO_PORT_NO_2,MDIO_PORT_NO_1,MDIO_PORT_NO_0);
PORTB=conc(MDIO_PORT_NO_15,MDIO_PORT_NO_14,MDIO_PORT_NO_13,MDIO_PORT_NO_12,MDIO_PORT_NO_11,MDIO_PORT_NO_10,MDIO_PORT_NO_9,MDIO_PORT_NO_8);
PORTC=conc(MDIO_PORT_NO_23,MDIO_PORT_NO_22,MDIO_PORT_NO_21,MDIO_PORT_NO_20,MDIO_PORT_NO_19,MDIO_PORT_NO_18,MDIO_PORT_NO_17,MDIO_PORT_NO_16);
PORTD=conc(MDIO_PORT_NO_31,MDIO_PORT_NO_30,MDIO_PORT_NO_29,MDIO_PORT_NO_28,MDIO_PORT_NO_27,MDIO_PORT_NO_26,MDIO_PORT_NO_25,MDIO_PORT_NO_24);
}
tenumFncErrorState MDIO_enuSetPinDir(u8 MDIO_PORTNOCPY,u8 MDIO_PINNOCPY,u8 MDIO_DIR )
{
tenumFncErrorState enuState=LSTY_EXECUTED_SUCCESSFULLY;
switch (MDIO_PORTNOCPY) {
	case MDIO_PORTA:
		if(MDIO_DIR==MDIO_OUTPUT)
			{
			SetBit(DDRA,MDIO_PINNOCPY);
			}
		else if (MDIO_DIR==MDIO_INPUT)
			{
			ClearBit(DDRA,MDIO_PINNOCPY);
			}
	break;

	case MDIO_PORTB:
		if(MDIO_DIR==MDIO_OUTPUT)
			{
			SetBit(DDRB,MDIO_PINNOCPY);
			}
		else if (MDIO_DIR==MDIO_INPUT)
			{
			ClearBit(DDRB,MDIO_PINNOCPY);
			}
	break;

	case MDIO_PORTC:
		if(MDIO_DIR==MDIO_OUTPUT)
			{
			SetBit(DDRC,MDIO_PINNOCPY);
			}
		else if (MDIO_DIR==MDIO_INPUT)
			{
			ClearBit(DDRC,MDIO_PINNOCPY);
			}
		break;
	case MDIO_PORTD:
		if(MDIO_DIR==MDIO_OUTPUT)
			{
			SetBit(DDRD,MDIO_PINNOCPY);
			}
		else if (MDIO_DIR==MDIO_INPUT)
			{
			ClearBit(DDRD,MDIO_PINNOCPY);
			}
	break;
	default:
		break;
}
return enuState;
}
tenumFncErrorState MDIO_enuSetPinValue(u8 MDIO_PORTNOCPY,u8 MDIO_PINNOCPY,u8 MDIO_Value )
{
	tenumFncErrorState enuState=LSTY_EXECUTED_SUCCESSFULLY;
	switch (MDIO_PORTNOCPY) {
		case MDIO_PORTA:
			if(MDIO_Value==MDIO_HIGHOUTPUT)
				{
				SetBit(PORTA,MDIO_PINNOCPY);
				}
			else if (MDIO_Value==MDIO_LOWHOUTPUT)
				{
				ClearBit(PORTA,MDIO_PINNOCPY);
				}
		break;

		case MDIO_PORTB:
			if(MDIO_Value==MDIO_HIGHOUTPUT)
				{
				SetBit(PORTB,MDIO_PINNOCPY);
				}
			else if (MDIO_Value==MDIO_LOWHOUTPUT)
				{
				ClearBit(PORTB,MDIO_PINNOCPY);
				}
		break;

		case MDIO_PORTC:
			if(MDIO_Value==MDIO_HIGHOUTPUT)
				{
				SetBit(PORTC,MDIO_PINNOCPY);
				}
			else if (MDIO_Value==MDIO_LOWHOUTPUT)
				{
				ClearBit(PORTC,MDIO_PINNOCPY);
				}
			break;
		case MDIO_PORTD:
			if(MDIO_Value==MDIO_HIGHOUTPUT)
				{
				SetBit(PORTD,MDIO_PINNOCPY);
				}
			else if (MDIO_Value==MDIO_LOWHOUTPUT)
				{
				ClearBit(PORTD,MDIO_PINNOCPY);
				}
		break;
		default:
			break;
	}
	return enuState;
	}
tenumFncErrorState MDIO_enuGetPinValue(u8 MDIO_PORTNOCPY,u8 MDIO_PINNOCPY,pu8 MDIO_Value )
{
tenumFncErrorState enuState=LSTY_EXECUTED_SUCCESSFULLY;
switch (MDIO_PORTNOCPY) {
	  case MDIO_PORTA:
	  *(MDIO_Value)=GetBit(PINA,MDIO_PINNOCPY);
	  break;
	  case MDIO_PORTB:
	  	  *(MDIO_Value)=GetBit(PINB,MDIO_PINNOCPY);
	  	  break;
	  case MDIO_PORTC:
	  	  *(MDIO_Value)=GetBit(PINC,MDIO_PINNOCPY);
	  	  break;
	  case MDIO_PORTD:
	  	  *(MDIO_Value)=GetBit(PIND,MDIO_PINNOCPY);
	  	  break;
	  default:
		  break;
}

  return enuState;


}
tenumFncErrorState MDIO_enuSetPORTDir(u8 MDIO_PORTNOCPY,u8 MDIO_DIR )
{ tenumFncErrorState enu_State=LSTY_EXECUTED_SUCCESSFULLY;
	switch (MDIO_PORTNOCPY) {
		case MDIO_PORTA:
			DDRA=MDIO_DIR;
			break;
	switch (MDIO_PORTNOCPY)
		case MDIO_PORTB:
			DDRB=MDIO_DIR;
			break;
	switch (MDIO_PORTNOCPY)
		case MDIO_PORTC:
			DDRC=MDIO_DIR;
		break;
		switch (MDIO_PORTNOCPY)
		case MDIO_PORTD:
			DDRD=MDIO_DIR;
		break;
		default:
			break;

}
return enu_State;
}
tenumFncErrorState MDIO_enuSetPORTValue(u8 MDIO_PORTNOCPY,u8 MDIO_Value )
{ tenumFncErrorState enu_State=LSTY_EXECUTED_SUCCESSFULLY;
	switch (MDIO_PORTNOCPY) {
		case MDIO_PORTA:
			PORTA=MDIO_Value;
			break;
	switch (MDIO_PORTNOCPY)
		case MDIO_PORTB:
			PORTB=MDIO_Value;
			break;
	switch (MDIO_PORTNOCPY)
		case MDIO_PORTC:
			PORTC=MDIO_Value;
		break;
		switch (MDIO_PORTNOCPY)
		case MDIO_PORTD:
			PORTD=MDIO_Value;
		break;
		default:
			break;

}
return enu_State;
}
tenumFncErrorState MDIO_enuGetPORTValue(u8 MDIO_PORTNOCPY,pu8 MDIO_Value )

{ tenumFncErrorState enu_State=LSTY_EXECUTED_SUCCESSFULLY;
	switch (MDIO_PORTNOCPY) {
		case MDIO_PORTA:
			*(MDIO_Value)=PINA;
			break;
	switch (MDIO_PORTNOCPY)
		case MDIO_PORTB:
			*(MDIO_Value)=PINB;
			break;
	switch (MDIO_PORTNOCPY)
		case MDIO_PORTC:
			*(MDIO_Value)=PINC;
		break;
		switch (MDIO_PORTNOCPY)
		case MDIO_PORTD:
			*(MDIO_Value)=PIND;
		break;
		default:
			break;

}
return enu_State;
}
