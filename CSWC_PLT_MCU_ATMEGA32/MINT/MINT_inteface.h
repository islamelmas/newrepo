/*
 * MINT_inteface.h
 *
 *  Created on: Apr 10, 2020
 *      Author: Mahmoud
 */

#ifndef CSWC_PLT_MCU_ATMEGA32_MINT_MINT_INTEFACE_H_
#define CSWC_PLT_MCU_ATMEGA32_MINT_MINT_INTEFACE_H_

typedef enum MINT_INT_NO{
MINT_INT0=1,
MINT_INT1=2,
MINT_INT2=3
}MINT_INT_NO;
typedef enum MINT_INT_STATE{
MINT_ON=1,
MINT_OFF=2
}MINT_INT_STATE;
typedef enum MINT_INT_MODE{
MINT_RISINGEDGE=1,
MINT_FALLINGEDGE=2,
MINT_LOGICALEDGE=3}MINT_INT_MODE;

typedef struct MINT_Config{
MINT_INT_NO INT_NO;
MINT_INT_STATE INT_STATE;
MINT_INT_MODE INT_MODE;
}MINT_Config;
void MINT_Init(void);
void MINT_NewState(MINT_Config config);
void MINT_INT0_CallBacK(void(*ptr)(void));
void MINT_INT1_CallBacK(void(*ptr)(void));
void MINT_INT2_CallBacK(void(*ptr)(void));

#endif /* CSWC_PLT_MCU_ATMEGA32_MINT_MINT_INTEFACE_H_ */
