/*
 * HLCD_int.h
 *
 *  Created on: Feb 4, 2020
 *      Author: Mahmoud
 */

#ifndef HLCD_INT_H_
#define HLCD_INT_H_

#define HLCD_ClEARSCREEN  0x01




void HLCD_Init(void);
void HLCD_WriteCmd(u8 u8cmdcpy);
void HLCD_WriteData(u8 u8datacpy);
void HLCD_WriteNum(u8 u8datacpy);
void HLCD_enuWriteNum(u16 u16datacpy);
void HLCD_WriteString(char* pu8str);
void HLCD_GoToXY(u8 row,u8 col);

#endif /* HLCD_INT_H_ */
