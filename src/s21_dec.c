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
     //printf("shift -- %d \n",shift_bite);
    //printBin(a);printBin(b);
    s21_sub(a,b,&tmp);
    //printf("tmp - ");
    printBin(tmp);
    c->bits[0] = 1;
    while(shift_bite > 0) {
        shift_decimal(&b, -1), shift_bite--;
        shift_decimal(c, 1);
        //printf("b ")  ;      printBin(b);
        if(s21_is_less(tmp,b)) {
            continue;
        }
        //printf("b ")  ;      printBin(b);
        //printf("tmp - %d\n", s21_is_equal(tmp, zero));
        //printf("tmp - "); printBin(tmp);
        //printf("rez - "); printBin(*c);
        
        if(!s21_is_equal(tmp, zero)) /*printf("Yee! "),*/ s21_sub(tmp, b,&tmp), setBit(c, 0, 1);
        //break;
    }

    //printf("tmp - ");
    //printBin(tmp);
    return tmp;
}
int mult_div(s21_decimal a, s21_decimal b, s21_decimal* c) {
    //s21_decimal rez = {0};
    int n = getMajorBit(b);
    printf("%d\n", n);
    s21_decimal tmp = a;
    for (int i = 0;i <=n; i++) {
        if (getBit(b,i)) {
            if (i!=0) shift_decimal(&tmp, i);
            printf("t - "); printBin(tmp);
            s21_add(tmp, *c, c);
            printf("c - "); printBin(*c);
            printf("-------------\n");
        }
        tmp = a;
    }
    return 0;
}