//#ifndef SRC_TEST_TEST_H_
#define SRC_TEST_TEST_H_

#include <check.h> // CHANGE BACK LATER

#include "../s21_decimal.h"

// Отображение отладочной информации в тестах
// #define __DEBUG 1

#define TEST_OK 0
#define TEST_ERROR_CONV 1

Suite *test_from_int_to_decimal_suite(void);
Suite *test_from_float_to_decimal_suite(void);
Suite *test_from_decimal_to_int_suite(void);
Suite *test_from_decimal_to_float_suite(void);

#define TEST_COMPARISON_FALSE 0
#define TEST_COMPARISON_TRUE 1

Suite *test_is_equal_suite(void);
Suite *test_is_less_suite(void);
Suite *test_is_less_or_equal_suite(void);
Suite *test_is_greater_suite(void);
Suite *test_is_greater_or_equal_suite(void);
Suite *test_is_not_equal_suite(void);

#define TEST_OTHER_OK 0
#define TEST_OTHER_ERROR 1

Suite *floor_suite(void);
Suite *round_suite(void);
Suite *truncate_suite(void);
Suite *negate_suite(void);

#define TEST_ARITHMETIC_OK 0
#define TEST_ARITHMETIC_BIG 1
#define TEST_ARITHMETIC_SMALL 2
#define TEST_ARITHMETIC_ZERO_DIV 3

Suite *add_suite0(void);
Suite *add_suite1(void);
Suite *add_suite2(void);
Suite *add_suite3(void);
Suite *add_suite4(void);
Suite *add_suite5(void);
Suite *add_suite6(void);
Suite *add_suite7(void);
Suite *add_suite8(void);
Suite *add_suite9(void);

Suite *div_suite0(void);
Suite *div_suite1(void);
Suite *div_suite2(void);
Suite *div_suite3(void);
Suite *div_suite4(void);
Suite *div_suite5(void);
Suite *div_suite6(void);
Suite *div_suite7(void);
Suite *div_suite8(void);
Suite *div_suite9(void);
Suite *div_suite10(void);
Suite *div_suite11(void);
Suite *div_suite12(void);
Suite *div_suite13(void);
Suite *div_suite14(void);
Suite *div_suite15(void);
Suite *div_suite16(void);
Suite *div_suite17(void);
Suite *div_suite18(void);

Suite *sub_suite0(void);
Suite *sub_suite1(void);
Suite *sub_suite2(void);
Suite *sub_suite3(void);
Suite *sub_suite4(void);
Suite *sub_suite5(void);
Suite *sub_suite6(void);
Suite *sub_suite7(void);
Suite *sub_suite8(void);
Suite *sub_suite9(void);

Suite *mul_suite0(void);
Suite *mul_suite1(void);
Suite *mul_suite2(void);
Suite *mul_suite3(void);
Suite *mul_suite4(void);
Suite *mul_suite5(void);
Suite *mul_suite6(void);
Suite *mul_suite7(void);
Suite *mul_suite8(void);
Suite *mul_suite9(void);

Suite *mod_suite0(void);
Suite *mod_suite1(void);
Suite *mod_suite2(void);
Suite *mod_suite3(void);
Suite *mod_suite4(void);
Suite *mod_suite5(void);
Suite *mod_suite6(void);
Suite *mod_suite7(void);
Suite *mod_suite8(void);
Suite *mod_suite9(void);
Suite *mod_suite10(void);
Suite *mod_suite11(void);
Suite *mod_suite12(void);
Suite *mod_suite13(void);
Suite *mod_suite14(void);
Suite *mod_suite15(void);
Suite *mod_suite16(void);
Suite *mod_suite17(void);
Suite *mod_suite18(void);

#endif  // SRC_TEST_TEST_H_
