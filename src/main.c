#include "s21_decimal.h"
#include <math.h>

int main() {
    s21_decimal a = {{0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFF,0}};
    s21_decimal b = {{0xFFFFFFFF,0,0xFFFFFF,0}};
    s21_decimal rez = {{0,0,0,0}};
    // int a_a = 2;
    // int b_b = 3000;
    // s21_from_int_to_decimal(a_a, &a);
    // s21_from_int_to_decimal(b_b, &b);
    // int sign1 = 0;
    // int sign2 = 0;
    // int scale1 = 5;
    // int scale2 = 5;
    // setSign(&a, sign1); setSign(&b, sign2);
    // setScale(&a, scale1); setScale(&b, scale2);

    s21_add_big(a, b, &rez);
    printDecAndBin(a); 
    printDecAndBin(b); 
    printDecAndBin(rez);

    return 0;
}

