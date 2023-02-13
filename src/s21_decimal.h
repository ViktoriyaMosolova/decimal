#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

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
#define S21_MAX_UINT 4294967296

// #define OK 0
// #define LARGE_OR_EQ_INF 1
// #define SMALL_OR_EQ_NEGINF 2
// #define DIV_BY_ZERO 3

// #define FALSE 0
// #define TRUE 1


//----------------------
#define CONVERTORS_OK 0
#define CONVERTORS_ERROR 1
//----------------------
#define COMPARISON_FALSE 0
#define COMPARISON_TRUE 1

#define EQUAL 0
#define BIG 2
#define LESS 1
//----------------------

#define OTHER_OK 0
#define OTHER_ERROR 1
//----------------------
#define ARITHMETIC_OK 0
#define ARITHMETIC_BIG 1
#define ARITHMETIC_SMALL 2
#define ARITHMETIC_ZERO_DIV 3

void printDecAndBin(s21_decimal num);
void printBits(s21_decimal num);

void setBit(s21_decimal* num, int i, int result);
void setSign(s21_decimal* num, int sign);
void setScale(s21_decimal* num, unsigned int result);

int getBit(s21_decimal num, int i);
int getSign(s21_decimal num);
int getScale(s21_decimal num);

int getBitFloat(int num, int i);
void setScaleFloat(int* num, int result);
int getSignFloat(int num);
int getScaleFloat(int num);
void setSignFloat(int *num, int sign);

int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);
int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);

int compareBits(s21_decimal a, s21_decimal b);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_negate(s21_decimal, s21_decimal*);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_round (s21_decimal value, s21_decimal *result);


#endif  //  SRC_S21_DECIMAL_H_