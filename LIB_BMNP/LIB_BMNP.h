#include "../LIB_STDTypes/LIB_STDTypes.h"
#ifndef CSWC_PLTF_BSW_ATMEGA32_LIB_BMNP_LIB_BMNP_H_
#define CSWC_PLTF_BSW_ATMEGA32_LIB_BMNP_LIB_BMNP_H_


#define SetBit(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define	ClearBit(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define	ToggleBit(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define	GetBit(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)

typedef union
{
	struct
	{
		u8 B0 : 1;
		u8 B1 : 1;
		u8 B2 : 1;
		u8 B3 : 1;
		u8 B4 : 1;
		u8 B5 : 1;
		u8 B6 : 1;
		u8 B7 : 1;
	}Bit;
	
	u8 Byte;
}Register;


#endif /* CSWC_PLTF_BSW_ATMEGA32_LIB_BMNP_LIB_BMNP_H_ */
