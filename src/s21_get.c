#include "s21_decimal.h"

int getBit(s21_decimal num, int i) {
    unsigned int mask = 1u << (i % 32);
    return !(!(num.bits[i / 32] & mask));
}

int getBitBig(s21_big_decimal num, int i) {
    unsigned int mask = 1u << (i % 32);
    return !(!(num.bits[i / 32] & mask));
}

int getSign(s21_decimal num) {
    return !(!(num.bits[3] & 1u << 31));
}

int getSignBig(s21_big_decimal num) {
    return !(!(num.bits[6] & 1u << 31));
}

int getScale(s21_decimal num) {
    setSign(&num, 0);
    return num.bits[3] >> 16u;
}

int getScaleBig(s21_big_decimal num) {
    setSignBig(&num, 0);
    return num.bits[6] >> 16u;
}

int getSignFloat(int num) {
    return !(!(num & 1u << 31));
}

int getScaleFloat(int num) {
    setSignFloat(&num, 0);
    return (num >> 23u);
}

int getBitFloat(int num, int i) {
    unsigned int mask = 1u << i;
    return !(!(num & mask));
}
