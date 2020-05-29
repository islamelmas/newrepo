/*
 * MDIO_Int.h
 *
 *  Created on: Apr 6, 2020
 *      Author: Mahmoud
 */

#ifndef CSWC_PLT_MCU_ATMEGA32_MDIO_MDIO_INT_H_
#define CSWC_PLT_MCU_ATMEGA32_MDIO_MDIO_INT_H_

#define MDIO_PORTA 0
#define MDIO_PORTB 1
#define MDIO_PORTC 2
#define MDIO_PORTD 3

#define MDIO_PIN0  0
#define MDIO_PIN1  1
#define MDIO_PIN2  2
#define MDIO_PIN3  3
#define MDIO_PIN4  4
#define MDIO_PIN5  5
#define MDIO_PIN6  6
#define MDIO_PIN7  7

#define MDIO_HIGHOUTPUT 1
#define MDIO_LOWHOUTPUT 0

#define MDIO_PULLUP 1
#define MDIO_HIGHIMPEDANCE 0

#define MDIO_OUTPUT 1
#define MDIO_INPUT 0

void MDIO_Int(void);
tenumFncErrorState MDIO_enuSetPinDir(u8 MDIO_PORTNOCPY, u8 MDIO_PINNOCPY,
		u8 MDIO_DIR);
tenumFncErrorState MDIO_enuSetPinValue(u8 MDIO_PORTNOCPY, u8 MDIO_PINNOCPY,
		u8 MDIO_Value);
tenumFncErrorState MDIO_enuGetPinValue(u8 MDIO_PORTNOCPY, u8 MDIO_PINNOCPY,
		pu8 MDIO_Value);
tenumFncErrorState MDIO_enuSetPORTDir(u8 MDIO_PORTNOCPY, u8 MDIO_DIR);
tenumFncErrorState MDIO_enuSetPORTValue(u8 MDIO_PORTNOCPY, u8 MDIO_Value);
tenumFncErrorState MDIO_enuGetPORTValue(u8 MDIO_PORTNOCPY, pu8 MDIO_Value);

#endif /* CSWC_PLT_MCU_ATMEGA32_MDIO_MDIO_INT_H_ */
