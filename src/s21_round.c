#include "s21_decimal.h"


int s21_round (s21_decimal value, s21_decimal *result) {
    for (int i = 0; i < 4; i += 1) result->bits[i] = 0;
    int sign=getSign(value);
    int scale=getScale(value);
    s21_decimal value1=value;
    //s21_decimal result1={{0,0,0,0}};

    value1.bits[3]=0;

    if (scale==0) {
        for (int i = 0; i < 4; i += 1) 
            result->bits[i] = value.bits[i];
     }
      else {
        for (int i = 0; i <scale-1; i ++) {
          unsigned long long a = value1.bits[2];
    

    for (int j = 2; j >= 0; j --) {
      value1.bits[j] = a/10;
      a= (a % 10) * (S21_MAX_UINT) + value1.bits[j - 1];
    
    }
  }
  
  if (value1.bits[0]%10<5) {
    s21_truncate(value, result);
  }
  else {
    s21_truncate(value, result);
    result->bits[0]+=1;
   
  }
  
  setScale(&value, (getScale(value) - scale));
      setSign(result, sign);
 }
 return 0;
}


int main() {
    s21_decimal b = {{4,7,0,131072}};
    s21_decimal result={{5,3,0,8}};
    //decreaseScale(&b, getScale(b));
    printDecAndBin(b);
    s21_round(b, &result);
    printDecAndBin(result);

    return 0;
}


