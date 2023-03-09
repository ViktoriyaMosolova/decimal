#include "s21_decimal.h"

int s21_mul(s21_decimal a, s21_decimal b, s21_decimal* c) {
    int scaleA = getScale(a), scaleB=getScale(b);
    int signA = getSign(a), signB = getSign(b);
    if (scaleA+scaleB > 28) return 1;
    setScale(c, scaleA+scaleB);
    if (signA^signB) setSign(c, 1);
    return mult_int(a,b,c);
}

int mult_int(s21_decimal a, s21_decimal b, s21_decimal* c) {
    int flag = 0, sign=getSign(*c), scale=getScale(*c);
    s21_decimal rez = {0};
    int n = getMajorBit(b);
    for (int i = 0;i <=n; i++) {
        s21_decimal tmp = a;
        if (getBit(b,i) == 1) {
            if (i!=0) shift_decimal(&tmp, i);
            flag = add_bytes(tmp, rez, c);
            if (flag) break;
            rez=*c;
        }
    }
    setScale(c,scale), setSign(c,sign);
    return flag;
}
int mult_ten(s21_decimal *a) {
    s21_decimal tmp = *a;
    s21_decimal tmp2 = *a;//проверять мажорный бит, чтоб не переполняться
    int scale = getScale(*a);
    int sign = getSign(*a);
    init(a);
    shift_decimal(&tmp, 3);
    shift_decimal(&tmp2, 1);
    if(add_bytes(tmp, tmp2 , a)) {
        printf("TO_mUCH\n");
        return 1;
    }
    setScale(a, scale);
    setSign(a, sign);
    return 0;
}