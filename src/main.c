#include "s21_decimal.h"
#include <math.h>

int main() {
    s21_decimal a = {{0,0,0,0}};
    s21_decimal b = {{0,0,0,0}};
    int sign1 = 0;
    int sign2 = 0;
    int scale1 = 0;
    int scale2 = 0;
    setSign(&a, sign1); setSign(&b, sign2);
    setScale(&a, scale1); setScale(&b, scale2);
    printDecAndBin(a); printDecAndBin(b);

    return 0;
}

