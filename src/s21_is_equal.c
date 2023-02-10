#include "s21_decimal.h"

int s21_is_equal(s21_decimal a, s21_decimal b) {
	int CODE = COMPARISON_FALSE;
	int sign_a = getSign(a);
	int sign_b = getSign(b);
	int scale_a = getScale(a);
	int scale_b = getScale(b);
	if((sign_a == sign_b) && (scale_a == scale_b)) {
		int flag = 1;
		for(int i = 95; flag && i >= 0; i--) { 
			if(getBit(a, i) != getBit(b, i)){ 
				flag = 0;
			}
		}
		if(flag) CODE = COMPARISON_TRUE;
	}
	return CODE;
}