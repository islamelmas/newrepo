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




#endif /* MAIN_H_ */
