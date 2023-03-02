#include "s21_decimal.h"

int s21_add_big(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
    int CODE = ARITHMETIC_OK; 

    s21_decimal_init_zero(result);
    s21_big_decimal a, b, big_temp = {{0,0,0,0,0,0,0}};

    s21_from_decimal_to_big_decimal(value_1, &a);
    s21_from_decimal_to_big_decimal(value_2, &b);

    //---------------------------------------------------------------------
    //normalization(&a, &b); 
    //нужны одинаковые scale. возможно лучше нормализовывать именно big_dec
    //---------------------------------------------------------------------

    if(getSignBig(a) == getSignBig(b)){
        int bit, shift = 0;
        for(int i = 0; i < 6*32; i++) {         
            bit = getBitBig(a, i) + getBitBig(b, i) + shift;
            shift = bit/2;
            setBitBig(&big_temp, i , bit%2);
        }

        setScaleBig(&big_temp, getScaleBig(a));
        setSignBig(&big_temp, getSignBig(a));

        if((big_temp.bits[3] || big_temp.bits[4] || big_temp.bits[5]) != 0) s21_decimal_init_zero(result);
        else s21_from_big_decimal_to_decimal(big_temp, result);
    } else {
        //s21_sub();
    }

    // for(int i = 32*6-1; i >= 0; i--) { printf("%d", getBitBig(a, i)); } printf("\n\n");
    // for(int i = 32*6-1; i >= 0; i--) { printf("%d", getBitBig(b, i)); } printf("\n\n");
    // for(int i = 32*6-1; i >= 0; i--) { printf("%d", getBitBig(big_temp, i)); } printf("\n\n");
    // for(int i = 32*6-1; i >= 0; i--) { printf("%d", getBit(*result, i)); } printf("\n\n");

    return CODE;
}