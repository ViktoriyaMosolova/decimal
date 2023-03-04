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

int add_bytes(s21_decimal value_1, s21_decimal value_2, s21_decimal *c) {
    s21_decimal result = {0};    
    int tmp=0;
        for (int i=0; i<96; i++) {
            int left_dec=getBit(value_1, i);
            int right_dec=getBit(value_2, i);

            if (!right_dec && !left_dec && tmp) {
                setBit(&result, i, 1);
                tmp=0;
            }

            if (right_dec && left_dec) {
                if (tmp==1) {
                    setBit(&result, i, 1);
                }
                tmp=1;
            }

            if (right_dec^left_dec) {
                if (!tmp) setBit(&result, i, 1);

            }
        }
    if (getBit(result, 96)) return 1;
    *c = result;
    return 0;
}
