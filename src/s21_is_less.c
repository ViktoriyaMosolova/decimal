#include "s21_decimal.h"

int compareBits(s21_decimal a, s21_decimal b) {
    int CODE = EQUAL;
    for (int i = 32*3-1; i >=0 && !CODE; i--){
        if (getBit(a,i) != getBit(b,i)) {
            if (getBit(a,i) < getBit(b,i)) CODE = LESS;
            else CODE = BIG;
        }
    }
    return CODE;    
}

int s21_is_less(s21_decimal a, s21_decimal b) {
    int CODE = COMPARISON_FALSE;
    if (getSign(a) == getSign(b)) {
        int sign = getSign(a);
        int a_scale = getScale(a);
        int b_scale = getScale(b);
        if (a_scale == b_scale) {
            if (sign == 0) {//+
                if (compareBits(a,b) == LESS) CODE = COMPARISON_TRUE;
            }
            else {//-
                if (compareBits(a,b) == BIG) CODE = COMPARISON_TRUE;
            }
        } else if (a_scale > b_scale && sign == 0) { 
                CODE = COMPARISON_TRUE;
        } else if (a_scale < b_scale && sign == 1) { 
                CODE = COMPARISON_TRUE;
        }
    } else if (getSign(a) > getSign(b)) {//-a +b
        CODE = COMPARISON_TRUE;
    }
    return CODE;
}
