#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
	int CODE = OTHER_OK;
	if(result) {
		*result = value;
		if (getSign(value)) {
		    setSign(result, 0);
		} else {
		    setSign(result, 1);
		}
	} else {
		CODE = OTHER_ERROR;
	}
	return CODE;
}