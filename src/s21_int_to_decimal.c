#include "s21_decimal.h"

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