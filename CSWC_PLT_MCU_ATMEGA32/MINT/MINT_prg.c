/*
 * MINT_prg.h
 *
 *  Created on: Apr 10, 2020
 *      Author: Mahmoud
 */
//Libraries
#include "../../Platform/ATMEGA32_Features.h"
#include "../../LIB_BMNP/LIB_BMNP.h"
#include "../../LIB_STDTypes/LIB_STDTypes.h"
//MCAL
#include "MINT_inteface.h"
#include "MINT_config.h"
#include "MINT_private.h"

static void(*INT0)(void);
static void(*INT1)(void);
static void(*INT2)(void);

void __vector_1(void)   __attribute__((signal,used));
void __vector_2(void)   __attribute__((signal,used));
void __vector_3(void)   __attribute__((signal,used));



void MINT_NewState(MINT_Config config)
{
if(config.INT_NO==MINT_INT0)
{
if((config.INT_STATE==MINT_ON)&&(config.INT_MODE==MINT_RISINGEDGE))
{ MINT_0_RAISINGGEDGE();
	}
else if ((config.INT_STATE==MINT_ON)&&(config.INT_MODE==MINT_FALLINGEDGE))
{
	 MINT_0_FALLINGEDGE();
}
else if ((config.INT_STATE==MINT_ON)&&(config.INT_MODE==MINT_LOGICALEDGE))
{
	MINT_0_LOGICALEDGE();
}
else
 {
	ClearBit(GICR,6);
 }
}
else if (config.INT_NO==MINT_INT1)
{

	if((config.INT_STATE==MINT_ON)&&(config.INT_MODE==MINT_RISINGEDGE))
	{ MINT_1_RAISINGEDGE();
		}
	else if ((config.INT_STATE==MINT_ON)&&(config.INT_MODE==MINT_FALLINGEDGE))
	{
		 MINT_1_FALLINGEDGE();
	}
	else if ((config.INT_STATE==MINT_ON)&&(config.INT_MODE==MINT_LOGICALEDGE))
	{
		MINT_1_LOGICALEDGE();
	}
	else
	 {
		ClearBit(GICR,7);
	 }


}
else if (config.INT_NO==MINT_INT2)

{

		if((config.INT_STATE==MINT_ON)&&(config.INT_MODE==MINT_RISINGEDGE))
		{ MINT_2_RAISINGEDGE();
			}
		else if ((config.INT_STATE==MINT_ON)&&(config.INT_MODE==MINT_FALLINGEDGE))
		{
			 MINT_2_FALLINGEDGE();
		}
		else
		 {
			ClearBit(GICR,5);
		 }
}

}
void MINT_Init(void)
{
MINT_NewState(MINT_Init_INT0);
MINT_NewState(MINT_Init_INT1);
MINT_NewState(MINT_Init_INT2);
}
void MINT_INT0_CallBacK(void(*ptr)(void))
{
	INT0=ptr;
}


void MINT_INT1_CallBacK(void(*ptr)(void))
{ INT1=ptr;
	}


void MINT_INT2_CallBacK(void(*ptr)(void)){
	INT2=ptr;
}


void __vector_1(void)
{
	INT0();
	}


void __vector_2(void)
{
	INT1();
	}


void __vector_3(void)
{
	INT2();
	}
static void MINT_0_FALLINGEDGE(void)
	{SetBit(GICR,6);
	ClearBit(MCUCR,0);
	SetBit(MCUCR,1);}

static void MINT_0_RAISINGGEDGE(void)
	{SetBit(GICR,6);
	SetBit(MCUCR,0);
	SetBit(MCUCR,1);}

static void MINT_0_LOGICALEDGE(void)
{SetBit(GICR,6);
	SetBit(MCUCR,0);
	ClearBit(MCUCR,1);}

static void MINT_1_FALLINGEDGE(void)
{SetBit(GICR,7);
	ClearBit(MCUCR,2);
	SetBit(MCUCR,3);}

static void MINT_1_RAISINGEDGE(void)
{SetBit(GICR,7);
	SetBit(MCUCR,2);
	SetBit(MCUCR,3);}

static void MINT_1_LOGICALEDGE(void)
{SetBit(GICR,5);
	SetBit(MCUCR,2);
	ClearBit(MCUCR,3);}

static void MINT_2_FALLINGEDGE(void)
{SetBit(GICR,5);
	ClearBit(MCUCSR,6);}

static void MINT_2_RAISINGEDGE(void)
{
SetBit(GICR,5);
SetBit(MCUCSR,6);}
