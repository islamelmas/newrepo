/*
 * HLCD.c
 *
 *  Created on: May 22, 2020
 *      Author: Mahmoud
 */
#include <util/delay.h>
#include "../Platform/ATMEGA32_Features.h"
#include "../LIB_BMNP/LIB_BMNP.h"
#include "HLCD_int.h"

void HLCD_Init(void)
{
DDRC=0xFF;
DDRA=0xFF;
HLCD_WriteCmd(HLCD_ClEARSCREEN);
_delay_ms(40);
HLCD_WriteCmd(0b00111100);
_delay_ms(1);
HLCD_WriteCmd(0b00001111);
_delay_ms(1);
HLCD_WriteCmd(0x01);
_delay_ms(2);


}
void HLCD_WriteCmd(u8 u8cmdcpy)
{
	ClearBit(PORTA,0);
	ClearBit(PORTA,1);
	PORTC=u8cmdcpy;
	SetBit(PORTA,2);
	_delay_ms(2);
	ClearBit(PORTA,2);

}
void HLCD_WriteData(u8 u8datacpy)
{
	SetBit(PORTA,0);
	ClearBit(PORTA,1);
	PORTC=u8datacpy;
	SetBit(PORTA,2);
	_delay_ms(2);
	ClearBit(PORTA,2);

}
void HLCD_WriteNum(u8 u8datacpy)
{
	SetBit(PORTA,0);
	ClearBit(PORTA,1);
	PORTC=u8datacpy+0b110000;
	SetBit(PORTA,2);
	_delay_ms(2);
	ClearBit(PORTA,2);

}
void HLCD_enuWriteNum(u16 u16datacpy) //Function to send num data
{
	  u8 i=0;
	  u8 num[5]={0};
	  s8 k;

	  while(u16datacpy>0)
	  	  {
	  		  num[i]=(u8)(u16datacpy%10);
	  	      u16datacpy/=10;

	            i++;
	  	  }
	  	  i--;


	 for(k=i;k>=0;k--)
	 {
		 HLCD_WriteNum(num[k]);

	 }


}

void HLCD_WriteString(char* pu8str) // Function to send data to string
{
int i=0;
while(pu8str[i]!='\0')
{
  HLCD_WriteData(pu8str[i]);
  i++;
  _delay_ms(10);
}
}

void HLCD_GoToXY(u8 row,u8 col)
{
switch (row)
{  case 0:
	HLCD_WriteCmd(0b10000000+col);
	break;
   case 1:
	HLCD_WriteCmd(0b11000000+col);
	break;


}


}

