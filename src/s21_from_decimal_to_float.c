#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
	*dst = 0;
	int CODE = CONVERTORS_OK;
	long double tmp = 0;
	for(int i = 0; i < 96; i++) {
		if(getBit(src, i)) {
			tmp += pow(2, i);
		}
	}
	int scale = getScale(src);
	while(scale!=0) {
		tmp/=10;
		scale-=1;
	}
	if(getSign(src) == 1) tmp*=-1;
	*dst = tmp;
	return CODE;
}