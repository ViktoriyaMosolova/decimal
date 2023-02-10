#include "s21_decimal.h"
#include <math.h>

#define ACCURACY powl(10, 6)


int s21_from_float_to_decimal(float src, s21_decimal *dst){
    int CODE = CONVERTORS_ERROR;
    dst->bits[0] = 0;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;

    long double fl = src;
    //printf("\n%Lf//\n", fl);
    int sign = 0;
    if(fl < 0) { 
        sign = 1;
        fl *= -1;
    }
    //printf("\n%d//\n", sign);
    if(fl < 1e-28) {
        s21_from_int_to_decimal(0, dst);
        if(fl == 0.0) CODE = CONVERTORS_OK;
    } else if(fl <= (long double)7.9228162514264337593543950335e28 && !isinf(fl)) {
        //printf("\n///%d//\n\n", !isinf(fl));
        CODE = CONVERTORS_OK;
        int scale = 0;
        //printf("\n%Lf//\n", fl);
        for(; fl > ACCURACY; fl/=10, scale--) { }
        for(long double left = 0; fl < ACCURACY && modfl(fl, &left) > 0 && scale < 28; fl *= 10, scale++) { }
        //printf("\n///%d///\n", scale);
        //printf("\n%Lf//\n", fl);

        fl = roundl(fl); //к ближ целому
        //printf("\n%Lf//\n", fl);

        if (scale < 0) { 
            fl *= powl(10, -scale); 
            scale = 0; 
        }
        //printf("\n%Lf//\n", fl);
        setSign(dst, sign);
        setScale(dst, scale);
        for (int i = 0; i < 96; i++, fl = floorl(fl / 2)) { setBit(dst, i, fmodl(fl, 2)); }
        //printf("\nCODE --%d--\n", CODE);
    } 
    //printf("\nCODE --%d--\n", CODE);
    return CODE;
}