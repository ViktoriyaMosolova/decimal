#include "s21_decimal.h"

int sub_for_poz(s21_decimal a, s21_decimal b, s21_decimal* result) {
  int tmp=0;
  for (int i = 0; i < 95; i++) {

        int left_dec = getBit(a, i);
        int right_dec = getBit(b, i);

        if (left_dec && !right_dec && tmp == 0) {
          setBit(result, i, 1);
        }
        if (left_dec && !right_dec && tmp == 1) {
          tmp = 0;
        }
        if (!left_dec && right_dec && tmp == 0) {
          setBit(result, i, 1);
          tmp = 1;
        }
        if (!left_dec && !right_dec && tmp == 1) {
          setBit(result, i, 1);
        }
  }
  return tmp;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {

  int scale=0;
  //int tmp = 0;
  if (getScale(value_1)==getScale(value_2)) 
    scale=getScale(value_1);

  if (!getSign(value_1) && !getSign(value_2)) {

    if (!s21_is_greater(value_2, value_1)){
      sub_for_poz(value_1, value_2, result);
    }
    
    if (!s21_is_greater(value_1, value_2)) {

      sub_for_poz(value_2, value_1, result);
      setSign(result, 1);
    }
  }
  

  if (!getSign(value_1) && getSign(value_2)) {
    setSign(&value_2, 0);
    s21_add(value_1, value_2, result);
  }

  if (getSign(value_1) && !getSign(value_2)) {
    setSign(&value_1, 0);
    s21_add(value_1, value_2, result);
    setSign(result, 1);
  }

  if (getSign(value_1) && getSign(value_2)) {
      setSign(&value_1, 0);
      setSign(&value_2, 0);
      s21_sub(value_1, value_2, result);
      if (getSign(*result)) setSign(result, 0);
      else setSign(result, 1);
    
  }
  setScale(result, scale);
  return 0;
}

// int main() {
//   s21_decimal a = {{3, 0, 0, 131072}}, b = {{9, 0, 0, 131072}};
//   printDecAndBin(a);
//   printDecAndBin(b);
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_sub(a, b, &result);
//   printDecAndBin(result);
// }
