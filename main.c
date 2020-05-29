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
	u8 f = 0;
	u8 operator;

	u8 value;
	u8 Calc_value;
	HKPAD_Init();
	HLCD_Init();
	while (1) {

		if (HKPAD_GetKeyValue(&value)) {
			Calc_value = CALC_Num(value);
			if (Calc_value == 'a') {
				HLCD_WriteCmd(HLCD_ClEARSCREEN);
				f = 0;
				i = 0;
				sum1 = 0;
				sum2 = 0;
			} else if ((Calc_value == '+') || (Calc_value == '-')
					|| (Calc_value == '*') || (Calc_value == '/')) {
				HLCD_WriteData(Calc_value);
				sum1 = Calc_Convert_to_number(arr, i - 1);
				operator = Calc_value;
				f = 1;
				i = 0;
			} else if (Calc_value == '=') {
				f = 2;
				sum2 = Calc_Convert_to_number(arr, i - 1);
				HLCD_GoToXY(1, 0);
				switch (operator) {
				case '+':
					sum = sum1 + sum2;
					break;
				case '-':
					sum = sum1 - sum2;
					break;
				case '*':
					sum = sum1 * sum2;
					break;
				case '/':
					sum = sum1 / sum2;
					break;
				default:
					break;

				}

				HLCD_enuWriteNum(sum);

			} else if (f == 1) {
				HLCD_WriteData(Calc_value);
				chtoint = atoi(&Calc_value);
				arr[i++] = chtoint;
			} else {
				HLCD_WriteData(Calc_value);
				chtoint = atoi(&Calc_value);
				arr[i++] = chtoint;

			}

		}

	}

	return 0;

}
