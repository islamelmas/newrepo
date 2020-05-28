
#include "main.h"


int main()
{
    u8 value;
	HKPAD_Init();
	HLCD_Init();
	while(1)
	{


//     HLCD_WriteCmd(HLCD_ClEARSCREEN);
     if(HKPAD_GetKeyValue(&value))
     {
     HLCD_enuWriteNum(value);
     }

	}

return 0;
}
