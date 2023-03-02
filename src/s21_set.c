#include "s21_decimal.h"

void setBit(s21_decimal* num, int i, int result) {
  if (result == 1) {
    num->bits[i / 32] |=  (1u << i % 32);
  } else if (result == 0) {
    num->bits[i / 32] &= ~(1u << i % 32);
  }
}

void setBitBig(s21_big_decimal* num, int i, int result) {
  if (result == 1) {
    num->bits[i / 32] |=  (1u << i % 32);
  } else if (result == 0) {
    num->bits[i / 32] &= ~(1u << i % 32);
  }
}

void setSign(s21_decimal *num, int sign) {
    if (sign == 1) {
        num->bits[3] |= 1u << 31;
    } else {
        num->bits[3] &= ~(1u << 31);
    }
}

void setSignBig(s21_big_decimal *num, int sign) {
    if (sign == 1) {
        num->bits[6] |= 1u << 31;
    } else {
        num->bits[6] &= ~(1u << 31);
    }
}

void setScale(s21_decimal* num, unsigned int result) {
    int flag = 0;
    if(getSign(*num)) { flag = 1; }
    num->bits[3] = result << 16u;
    if(flag) { setSign(num, 1); }
}

void setScaleBig(s21_big_decimal* num, unsigned int result) {
    int flag = 0;
    if(getSignBig(*num)) { flag = 1; }
    num->bits[6] = result << 16u;
    if(flag) { setSignBig(num, 1); }
}

void setSignFloat(int *num, int sign) {
    if (sign == 1) {
        *num |= 1u << 31;
    } else {
        *num &= ~(1u << 31);
    }
}

void setScaleFloat(int* num, int result) {
    int flag = 0;
    if(getSignFloat(*num)) { flag = 1; }
    *num = result << 23u;
    if(flag) { setSignFloat(num, 1); }
}