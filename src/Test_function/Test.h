#ifndef SRC_TEST_TEST_H_
#define SRC_TEST_TEST_H_
#include <check.h> // CHANGE BACK LATER

#include "../s21_decimal.h"

#define TEST_CONVERTORS_OK 0
#define TEST_CONVERTORS_ERROR 1

Suite *test_from_int_to_decimal(void);
Suite *test_from_float_to_decimal(void);
Suite *test_from_decimal_to_int(void);
Suite *test_from_decimal_to_float(void);

#define TEST_COMPARISON_FALSE 0
#define TEST_COMPARISON_TRUE 1

Suite *test_is_equal(void);
Suite *test_is_less(void);
Suite *test_is_less_or_equal(void);
Suite *test_is_greater(void);
Suite *test_is_greater_or_equal(void);
Suite *test_is_not_equal(void);

#define TEST_OTHER_OK 0
#define TEST_OTHER_ERROR 1

Suite *test_floor(void);
Suite *test_round(void);
Suite *test_truncate(void);
Suite *test_negate(void);

#define TEST_ARITHMETIC_OK 0
#define TEST_ARITHMETIC_BIG 1
#define TEST_ARITHMETIC_SMALL 2
#define TEST_ARITHMETIC_ZERO_DIV 3

Suite *test_add(void);
Suite *test_div(void);
Suite *test_sub(void);
Suite *test_mul(void);
Suite *test_mod(void);

#endif  // SRC_TEST_TEST_H_