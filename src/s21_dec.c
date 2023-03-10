#include "s21_decimal.h"
//int s21_div(s21_decimal a, s21_decimal b, s21_decimal* c){}
void division(s21_decimal a, s21_decimal b, s21_decimal* c) {
    cast_scale(&a, &b);
    //printDecAndBin(a), printDecAndBin(b); 
    s21_decimal tmp = div_int(a,b,c);
    printf("here tmp: "), printDecAndBin(tmp);
    //printDecAndBin(*c); 
    s21_decimal zero={{0}};
    int scale = getScale(*c);
    //printf("S:%d\n", scale);
    int k = 0;
    while(compareBits(tmp,zero) != EQUAL && scale < 28) {
        k ++;
        //printf("here 1: "), printDecAndBin(tmp);
        mult_ten(&tmp); 
        if(mult_ten(c)) break;
         if (k == 3) {
            printf("here: "), printDecAndBin(tmp);
            printDecAndBin(*c);
        }
         
        scale++;
        s21_decimal new_tmp = div_int(tmp,b,&tmp);
        if (k == 3) {
            printf("new: "), printDecAndBin(new_tmp);
            //break;
        }
        //break;
        if(compareBits(new_tmp, b) == LESS) if(add_bytes(*c, tmp, c)) break;
        tmp = new_tmp;
       
       
       
    }
    setScale(c, scale);

}

void  shift_big_decimal(big_decimal* decimal, int shift) {
    if (shift > 0) {
        for (int i = 0; i < shift;i++) {
            int bit1 = getBitBig(*decimal, 31);
            int bit2 = getBitBig(*decimal, 63);
            int bit3 = getBitBig(*decimal, 95);
            int bit4 = getBitBig(*decimal, 127);
            int bit5 = getBitBig(*decimal, 159);
            decimal->bits[5] <<= 1;
            decimal->bits[4] <<= 1;
            decimal->bits[3] <<= 1;
            decimal->bits[2] <<= 1;
            decimal->bits[1] <<= 1;
            decimal->bits[0] <<= 1;
            setBitBig(decimal, 32, bit1);
            setBitBig(decimal, 64, bit2);
            setBitBig(decimal, 96, bit3);
            setBitBig(decimal, 128, bit4);
            setBitBig(decimal, 160, bit5);
        }
    } else {
        for (int i = 0; i < shift*(-1);i++) {
            int bit1 = getBitBig(*decimal, 32);
            int bit2 = getBitBig(*decimal, 64);
            int bit3 = getBitBig(*decimal, 96);
            int bit4 = getBitBig(*decimal, 128);
            int bit5 = getBitBig(*decimal, 160);
            decimal->bits[5] >>= 1;
            decimal->bits[4] >>= 1;
            decimal->bits[3] >>= 1;
            decimal->bits[2] >>= 1;
            decimal->bits[1] >>= 1;
            decimal->bits[0] >>= 1;
            setBitBig(decimal, 31, bit1);
            setBitBig(decimal, 63, bit2);
            setBitBig(decimal, 95, bit3);
            setBitBig(decimal, 127, bit4);
            setBitBig(decimal, 159, bit5);
        }
    }
}

void  shift_decimal(s21_decimal* decimal, int shift) {
    if (shift > 0) {
        for (int i = 0; i < shift;i++) {
            int bit1 = getBit(*decimal, 31);
            int bit2 = getBit(*decimal, 63);
            decimal->bits[2] <<= 1;
            decimal->bits[1] <<= 1;
            decimal->bits[0] <<= 1;
            setBit(decimal, 32, bit1);
            setBit(decimal, 64, bit2);
        }
    } else {
        for (int i = 0; i < shift*(-1);i++) {
            int bit1 = getBit(*decimal, 32);
            int bit2 = getBit(*decimal, 64);
            decimal->bits[2] >>= 1;
            decimal->bits[1] >>= 1;
            decimal->bits[0] >>= 1;
            setBit(decimal, 31, bit1);
            setBit(decimal, 63, bit2);
        }
    }
}


s21_decimal div_int(s21_decimal a, s21_decimal b, s21_decimal* c) { 
    s21_decimal tmp = {0};
    s21_decimal zero = {0};
    //printDecAndBin(a), printDecAndBin(b);
    if(s21_is_less(a,b)) return a; 
    init(c);
    int majorA = getMajorBit(a), majorB = getMajorBit(b);
    int shift_bite = majorA - majorB;
    shift_decimal(&b, shift_bite);
    if(compareBits(a,b)==LESS) shift_decimal(&b, -1), shift_bite--; 
    s21_sub(a,b,&tmp);
    c->bits[0] = 1;
    while(shift_bite > 0) {
        shift_decimal(&b, -1), shift_bite--;
        shift_decimal(c, 1);
        if(compareBits(tmp,b) == LESS) continue;
        if(compareBits(tmp, zero) != EQUAL)  s21_sub(tmp, b,&tmp), setBit(c, 0, 1);
    }
    //printDecAndBin(tmp);
    return tmp;
}

int ammount_digit(s21_decimal a) {
    int i = -1;
    s21_decimal zero = {{0}};
    while(!(s21_is_equal(a, zero))){
        i++;
        div_ten(&a);
    }
    return i;
}

void div_ten(s21_decimal *a) {
    s21_decimal tmp = {{10,0,0,0}};
    s21_decimal tmp2 = *a;
    div_int(tmp2, tmp, a);
}

int getMajorMax(s21_decimal a, s21_decimal b) {
    int majorA = getMajorBit(a), majorB = getMajorBit(b);
    int majorMax;
    if (majorA > majorB) majorMax = majorA;
    else majorMax = majorB;
    return majorMax;
}

void cast_scale(s21_decimal *a, s21_decimal *b) {
    int scale_a = getScale(*a);
    int scale_b = getScale(*b);
    int scale_cast;
    while (scale_a != scale_b){
        if (getMajorMax(*a,
        *b)+3 > 96) {
            printf("HI\n");
            if (scale_a > scale_b) div_ten(a), scale_a--;
            else div_ten(b), scale_b--;
        } else {
            if (scale_a > scale_b) mult_ten(b), scale_b++;
            else mult_ten(a), scale_a++;
        }
    }
   // printDecAndBin(*a);printDecAndBin(*b);
    scale_cast = scale_a;
    setScale(a, scale_cast);
    setScale(b, scale_cast);
    
}
