#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {

    int flag=0;
    int tmp=0;
    int scale=0;

    if (getSign(value_1) && getSign(value_2)) {
        flag=-1;
    }

    if (!getSign(value_1) && !getSign(value_2)) {
        flag=1;
    }
    if (getSign(value_1) && !getSign(value_2)) {
        setSign(&value_1, 0);
        s21_sub(value_2, value_1, result);
    }

    if (!getSign(value_1) && getSign(value_2)) {
        setSign(&value_2, 0);
        s21_sub(value_1, value_2, result);
    }

    if (getScale(value_1)==getScale(value_2)) {
        scale=getScale(value_1);
    }

    if (flag!=0) {
        for (int i=0; i<95; i++) {
            int left_dec=getBit(value_1, i);
            int right_dec=getBit(value_2, i);

            if (!right_dec && !left_dec && tmp) {
                setBit(result, i, 1);
                tmp=0;
            }

            if (right_dec && left_dec) {
                if (tmp==1) {
                    setBit(result, i, 1);
                }
                tmp=1;
            }

            if (right_dec^left_dec) {
                if (!tmp) setBit(result, i, 1);

            }
        }
    }

    if (flag==-1) { setSign(result, 1); }
    setScale(result, scale);
    return 0;

}
