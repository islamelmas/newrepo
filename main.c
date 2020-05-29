#include<stdio.h>
#include<stdlib.h>
#include "main.h"

int main() {
	u16 sum1 = 0;
	u16 sum2 = 0;
	u8 arr[10];
	u16 sum;
	u8 chtoint;
	u8 i = 0;

	u8 value;
	u8 Calc_value;
	HKPAD_Init();
	HLCD_Init();
	while (1) {

		if (HKPAD_GetKeyValue(&value)) {
			Calc_value = CALC_Num(value);
			if (Calc_value == 'a') {
				HLCD_WriteCmd(HLCD_ClEARSCREEN);
			}
			else {
				HLCD_WriteData(Calc_value);
				chtoint = atoi(&Calc_value);
				arr[i] = chtoint;
				sum=Calc_Convert_to_number(arr,i++);
				HLCD_enuWriteNum(sum);

			}
		}
	}
//     if((Calc_value!='=')||(Calc_value!='+')||(Calc_value!='/')||(Calc_value!='*')||(Calc_value!='-')||(Calc_value!='a'))
//    	f=0;
//     else if((Calc_value=='+'))
//     {
//    	f=1;
//     }
//     else if((Calc_value=='='))
//     {
//    	 f=2;
//     }
//
//     if(f==0)
//     {
//    		int_value=atoi(&Calc_value);
//    	 			int_value=int_value^i;
//    	 			i+=10;
//    				sum1+=int_value;
//     }
//     HLCD_enuWriteNum(sum1);
//     if((Calc_value!='=')||(Calc_value!='+')||(Calc_value!='/')||(Calc_value!='*')||(Calc_value!='-'))
//    	 fl
//    		 {
//    			int_value=atoi(Calc_value);
//    			int_value=int_value^i;
//    			i+=10;
//    			sum1+=int_value;
//    				  }

	return 0;

}
