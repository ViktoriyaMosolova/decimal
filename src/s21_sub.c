#include "s21_decimal.h"


int s21_sub(s21_decimal a, s21_decimal b, s21_decimal *c) {
    int bitA, bitB, zaim = 0;
    for (int i = 0; i < 96; i++) {
        bitA = getBit(a, i);
        bitB = getBit(b, i);
        if (bitA == 1 && bitB == 0) {
            if (zaim == 0)
                setBit(c, i, 1);
            else
                setBit(c, i, 0), zaim = 0;
        }
        if ((bitA == 1 && bitB == 1) || (bitA == 0 && bitB == 0)) {
            if (zaim == 0)
               setBit(c, i, 0);
            else
               setBit(c, i, 1);
        }
        if (bitA == 0 && bitB == 1) {
            if (zaim == 0)
                setBit(c, i, 1), zaim = 1;
            else
                setBit(c, i, 0);
        }
    }
    return 0;
}