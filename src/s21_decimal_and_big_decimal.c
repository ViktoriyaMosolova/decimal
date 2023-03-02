#include "s21_decimal.h"

void s21_from_decimal_to_big_decimal(s21_decimal src, s21_big_decimal* dst){
    for (int i = 0; i < 32*3; i++) { setBitBig(dst, i, getBit(src, i)); }
    setSignBig(dst, getSign(src));
    setScaleBig(dst, getScale(src));
    //for (int i = 0; i < 32*4; i++) { printf("%d", getBit(src, i)); }
    //printf("\n");
    //for(int i = 0; i < 32*7; i++){ printf("%d", getBitBig(*dst, i)); }
    //printf("\n\n");
}

void s21_from_big_decimal_to_decimal(s21_big_decimal src, s21_decimal *dst) {
    for (int i = 0; i < 32*3; i++) { setBit(dst, i, getBitBig(src, i)); }
    setSign(dst, getSignBig(src));
    setScale(dst, getScaleBig(src));

    // for(int i = 0; i < 32*7; i++){ if(i%32 == 0) printf("\n"); printf("%d", getBitBig(src, i)); }
    // printf("\n\n");
    // for(int i = 0; i < 32*4; i++){ if(i%32 == 0) printf("\n"); printf("%d", getBit(*dst, i)); }
    // printf("\n\n");
}

void s21_decimal_init_zero(s21_decimal *src){
    src->bits[0] = 0;
    src->bits[1] = 0;
    src->bits[2] = 0;
    src->bits[3] = 0;
}