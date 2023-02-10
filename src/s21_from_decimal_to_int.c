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