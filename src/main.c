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
    // printf("\nless\n");
    // if (s21_is_less(a,b)) printf("TRUE\n");
    // else printf("FALSE\n");
    // printf("\nless_or_equal\n");
    // if (s21_is_less_or_equal(a,b)) printf("TRUE\n");
    // else printf("FALSE\n");
    // printf("\ngreater\n");
    // if (s21_is_greater(a,b)) printf("TRUE\n");
    // else printf("FALSE\n");
    // printf("\ngreater_or_equal\n");
    // if (s21_is_greater_or_equal(a,b)) printf("TRUE\n");
    // else printf("FALSE\n");
    // printf("\nequal\n");
    // if (s21_is_equal(a,b)) printf("TRUE\n");
    // else printf("FALSE\n");
    // printf("\nnot_equal\n");
    // if (s21_is_not_equal(a,b)) printf("TRUE\n");
    // else printf("FALSE\n");

    return 0;
}

