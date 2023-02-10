#include "s21_decimal.h"

int s21_is_less_or_equal(s21_decimal a, s21_decimal b) {
    int CODE = COMPARISON_FALSE;
	if(s21_is_less(a, b) || s21_is_equal(a, b)) CODE = COMPARISON_TRUE;
	return CODE;
}