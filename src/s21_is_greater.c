#include "s21_decimal.h"

int s21_is_greater(s21_decimal a, s21_decimal b) {
	int CODE = COMPARISON_FALSE;
	if(s21_is_not_equal(a, b) && !s21_is_less(a, b)) CODE = COMPARISON_TRUE;
	return CODE;
}