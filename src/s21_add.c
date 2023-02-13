#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int flag=0;
    int tmp=0;
    int scale=0;

    if (getSign(value_1) && getSign(value_2)) { flag=-1; }
    if (!getSign(value_1) && !getSign(value_2)) { flag=1; }

    if (getSign(value_1) && !getSign(value_2)) {
        setSign(&value_1, 0);
        s21_sub(value_2, value_1, result);
    }

    if (!getSign(value_1) && getSign(value_2)) {
        setSign(&value_2, 0);
        s21_sub(value_1, value_2, result);
    }

    if (getScale(value_1)==getScale(value_2)) {
        scale=getScale(value_1);
    }

    // if (getScale(value_1)!=getScale(value_2)){

    //     if (getScale(value_1)>getScale(value_2)){
    //         scale=getScale(value_1);
    //         // setScale(&value_1, getScale(value_1));
    //         // setScale(&value_2, getScale(value_1));
    //          }
    //     else {
    //         scale=getScale(value_2);
    //         // setScale(&value_1, getScale(value_2));
    //         // setScale(&value_2, getScale(value_2));
    //         // printf("%d\n", getScale(value_2));
    //         // printDecAndBin(value_1);
    //         // printDecAndBin(value_2);
    //     }
    //     if (getScale(value_1)!=scale) {
    //         while (getScale(value_1)!=scale) {
                
    //         }
    //     }
        
    // }

    if (flag!=0) {
        for (int i=0; i<95; i++) {
            int left_dec=getBit(value_1, i);
            int right_dec=getBit(value_2, i);

            if (!right_dec && !left_dec && tmp) {
                setBit(result, i, 1);
                tmp=0;
            }

            if (right_dec && left_dec) {
                if (tmp==1) {  setBit(result, i, 1); }
                tmp=1;
            }

            if (right_dec^left_dec) {
                if (!tmp) setBit(result, i, 1);
            }
        }
    }

    if (flag==-1) {
        setSign(result, 1);
        setScale(result, scale);
    }
    return 0;
}

// int main() {
//      s21_decimal a = {{3, 0, 0, 2147483648}}, b = {{9, 0, 0, 0}};
//      printDecAndBin(a);
//      printDecAndBin(b);
//     //  printf("%d\n", getScale(a));
//     //  printf("%d\n", getScale(b));
//      s21_decimal result={{0,0,0,0}};
//    s21_add(a, b, &result);
//    printDecAndBin(result);
// }
