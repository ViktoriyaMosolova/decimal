#include "s21_decimal.h"

void  shift_decimal(s21_decimal* decimal, int shift) {
    if (shift > 0) {
        for (int i = 0; i < shift;i++) {
            int bit1 = getBit(*decimal, 31);
            int bit2 = getBit(*decimal, 63);
            decimal->bits[2] <<= 1;
            decimal->bits[1] <<= 1;
            decimal->bits[0] <<= 1;
            setBit(decimal, 32, bit1);
            setBit(decimal, 64, bit2);
        }
    } else {
        for (int i = 0; i < shift*(-1);i++) {
            int bit1 = getBit(*decimal, 32);
            int bit2 = getBit(*decimal, 64);
            decimal->bits[2] >>= 1;
            decimal->bits[1] >>= 1;
            decimal->bits[0] >>= 1;
            setBit(decimal, 31, bit1);
            setBit(decimal, 63, bit2);
        }
    }
}


s21_decimal div_int(s21_decimal a, s21_decimal b, s21_decimal* c) { 
    s21_decimal tmp = {0};
    s21_decimal zero = {0};
    if(s21_is_less(a,b)) return a; 
    init(c);
    int majorA = getMajorBit(a), majorB = getMajorBit(b);
    int shift_bite = majorA - majorB;
    shift_decimal(&b, shift_bite);
   
    if(s21_is_less(a,b)) shift_decimal(&b, -1), shift_bite--; 
    s21_sub(a,b,&tmp);
    c->bits[0] = 1;
    while(shift_bite > 0) {
        shift_decimal(&b, -1), shift_bite--;
        shift_decimal(c, 1);
        if(s21_is_less(tmp,b)) continue;
        if(!s21_is_equal(tmp, zero))  s21_sub(tmp, b,&tmp), setBit(c, 0, 1);
    }
    return tmp;
}
int mult_div(s21_decimal a, s21_decimal b, s21_decimal* c) {
    s21_decimal rez = {0};
    int n = getMajorBit(b);
    for (int i = 0;i <=n; i++) {
        s21_decimal tmp = a;
        if (getBit(b,i) == 1) {
            if (i!=0) shift_decimal(&tmp, i);
            s21_add(tmp, rez, c);
            rez=*c;
        }
    }
    return 0;
}

void mult_ten(s21_decimal a, s21_decimal *c) {
    s21_decimal tmp = a;
    shift_decimal(&tmp, 3);
    shift_decimal(&a, 1);
    s21_add(tmp, a , c);
}
void div_ten(s21_decimal a, s21_decimal *c) {
    s21_decimal tmp = {{10,0,0,0}};
    div_int(a, tmp, c);
}