#include "s21_decimal.h"
#include <string.h>


int s21_truncate(s21_decimal value, s21_decimal *result) {
    for (int i = 0; i < 4; i += 1) result->bits[i] = 0;
    int sign=getSign(value);
    int scale=getScale(value);
    
    value.bits[3]=0;
    if (scale==0) { for (int i = 0; i < 4; i += 1) result->bits[i] = value.bits[i];
    } else {
        for (int i = 0; i <scale; i++) { 
          unsigned long long a = value.bits[2];
          for (int j = 2; j >= 0; j --) {
              value.bits[j] = a/10; //каждый бит делим на 10
              a = (a % 10) * (S21_MAX_UINT) + value.bits[j - 1];//поскольку у нас биты хранятся в инте, то остаток от деления мы прибавляем к предыдущему, домножая на различие в степенях двойки 
          }
        }
    }
  
    setScale(&value, (getScale(value) - scale));
    for (int i = 0; i < 4; i += 1) { result->bits[i]=value.bits[i]; }
    setSign(result, sign);
   return 0;
 }
    
 




// int main() {
//     s21_decimal b = {{4,7,0,131072}};
//     s21_decimal result={{5,3,0,8}};
//     //decreaseScale(&b, getScale(b));
//     printDecAndBin(b);
//     s21_truncate(b, &result);
//     printDecAndBin(result);

//     return 0;
// }

