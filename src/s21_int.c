#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    int CODE = CONVERTORS_OK;
    if (src.bits[0] <= 2147483647 && src.bits[1] == 0 && src.bits[2] == 0 && getScale(src) == 0) {
  		if(getSign(src) == 0) {
  			*dst = src.bits[0];
  		} else {
  			*dst = src.bits[0] * -1;
  		}
    } else {
        CODE = CONVERTORS_ERROR;
    }
    return CODE;
}
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    int CODE = CONVERTORS_OK;
	dst->bits[0]=0;
	dst->bits[1]=0;
	dst->bits[2]=0;
	dst->bits[3]=0;
    if (src < 0) {
		setSign(dst, 1);
	    dst->bits[0] = -src;
	} else {
		dst->bits[0] = src;
	}
    return CODE;
}