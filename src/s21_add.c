#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *c) {
    int flag=1, end = 0;
      if (getScale(value_1) > 28 || getScale(value_2)>28) return SMALL_OR_EQ_NEGINF;
    cast_scale(&value_1, &value_2);
    if (getSign(value_1) && getSign(value_2)) flag=-1;
    if (getSign(value_1) && !getSign(value_2)) {
        setSign(&value_1, 0);
        s21_sub(value_2, value_1, c);
        flag = 0;
    }
    if (!getSign(value_1) && getSign(value_2)) {
        setSign(&value_2, 0);
        s21_sub(value_1, value_2, c);
        flag=0;
    }

    if (flag!=0) {
        end = add_bytes(value_1, value_2, c);
    }
    if (end) return LARGE_OR_EQ_INF;
    setScale(c, getScale(value_1));
    if (flag==-1) setSign(c, 1);
    return OK;
}

int add_bytes(big_decimal value_1, big_decimal value_2,
                 big_decimal *result) {
  short error = 0, tmp = 0;
  int term1, term2;
  big_init(result);
  for (int j = 0; j < 6; j++) {
    for (int i = 0; i < 32; i++) {
      term1 = getBitBig(value_1, i * j);
      term2 = getBitBig(value_2, i * j);
      if (term1 && term2) {
        if (tmp) {
          setBitBig(result, i * j);
        } else {
          tmp = 1;
        }
      } else if (term1 ^ term2) {
        if (!tmp) {
          setBitBig(result, i * j);
        }
      } else if (tmp) {
        setBitBig(result, i * j);
        tmp = 0;
      }
    }
    if (tmp && j == 5) error = 1;
  }
  return error;
}
