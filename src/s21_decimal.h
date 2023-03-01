#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 30
#define MINUS 2147483648



typedef struct {
    unsigned int bits[4];
} s21_decimal;
//--------------print-----------------//
char* printBin(s21_decimal);
char* toBinary(int);
char* additionString(char*, char*);
void coup(char*);
void printDecAndBin(s21_decimal);
char* multiplicationString(char *, char *);
char* powTwo(int);
int toDec(char *); 
//--------------print-----------------//

#define MAX_NUM 30
#define MINUS 2147483648
#define OK 0
#define LARGE_OR_EQ_INF 1
#define SMALL_OR_EQ_NEGINF 2
#define DIV_BY_ZERO 3
#define FALSE 0
#define TRUE 1
#define EQUAL 0
#define BIG 2
#define LESS 1

void printDecAndBin(s21_decimal num);
void setBit(s21_decimal* num, int i, int result);
void setSign(s21_decimal* num, int sign);
void setScale(s21_decimal* num, unsigned int result);
int getBit(s21_decimal num, int i);
int getMajorBit(s21_decimal num);
int getSign(s21_decimal num);
void printBits(s21_decimal num);
int getScale(s21_decimal num);
// --------COMPARE---------- //
int s21_is_less(s21_decimal a, s21_decimal b);
int s21_is_equal(s21_decimal a, s21_decimal b);
int s21_is_greater(s21_decimal a, s21_decimal b);
int s21_is_greater_or_equal(s21_decimal a, s21_decimal b);
int s21_is_less_or_equal(s21_decimal a, s21_decimal b);
int s21_is_not_equal(s21_decimal a, s21_decimal b);
// --------COMPARE---------- //
int compareBits(s21_decimal a, s21_decimal b);
void init(s21_decimal* a);
void  shift_decimal(s21_decimal* decimal, int shift); // shift pozitive -> right
// void invert_value_2_for_sub(s21_decimal *num);
// char* printBin(s21_decimal num);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void mult_div(s21_decimal a, s21_decimal b, s21_decimal* c);
void mult_ten(s21_decimal *a);
int sub_for_poz(s21_decimal a, s21_decimal b, s21_decimal* result);
s21_decimal div_int(s21_decimal a, s21_decimal b, s21_decimal* c);
void div_ten(s21_decimal *a) ;
void division(s21_decimal a, s21_decimal b, s21_decimal* c);
char* toBinary(int n);
char* additionString(char* a, char* b);
void coup(char* tex);
void printDecAndBin(s21_decimal num);
char* multiplicationString(char *a, char *b);
char* powTwo(int b);
int toDec(char *bin);
int ammount_digit(s21_decimal a);

#endif  //  SRC_S21_DECIMAL_H_