#include "s21_decimal.h"

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal res = {0};
  s21_decimal mul = {0};
  s21_decimal fraction = {0};
  int err = 0; division(value_1, value_2, &res); //s21_div
  if (!err) {
    s21_truncate(res, &fraction);
    s21_mul(fraction, value_2, &mul);
    err += s21_sub(value_1, mul, &res);
    *result = res;
  }
  return err;
}