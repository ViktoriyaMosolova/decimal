#include "../Test.h"

START_TEST(test_TRUE_is_equal){
	//with scale----------------------------------------
	s21_decimal first_with_scale[] = {
//
	};
	s21_decimal second_with_scale[] = {
//
	};

	size_t n = sizeof(first_with_scale) / sizeof(first_with_scale[0]);

	for (size_t i = 0; i < n; i++) {
	  
	  int result = s21_is_equal(first_with_scale[i], second_with_scale[i]);
	  ck_assert_int_eq(TEST_COMPARISON_TRUE, result);
	}

	//without scale	--------------------------------------
    s21_decimal first[] = {
//
	};
	s21_decimal second[] = {
//
	};

	size_t n = sizeof(first) / sizeof(first[0]);

	for (size_t i = 0; i < n; i++) {
	  
	  int result = s21_is_equal(first[i], second[i]);
	  ck_assert_int_eq(TEST_COMPARISON_TRUE, result);
	}
}
END_TEST

START_TEST(test_FALSE_is_equal){
	//with scale----------------------------------------
	s21_decimal first_with_scale[] = {
//
	};
	s21_decimal second_with_scale[] = {
//
	};

	size_t n = sizeof(first_with_scale) / sizeof(first_with_scale[0]);

	for (size_t i = 0; i < n; i++) {
	  
	  int result = s21_is_equal(first_with_scale[i], second_with_scale[i]);
	  ck_assert_int_eq(TEST_COMPARISON_FALSE, result);
	}

	//without scale	--------------------------------------
    s21_decimal first[] = {
//
	};
	s21_decimal second[] = {
//
	};

	size_t n = sizeof(first) / sizeof(first[0]);

	for (size_t i = 0; i < n; i++) {
	  
	  int result = s21_is_equal(first[i], second[i]);
	  ck_assert_int_eq(TEST_COMPARISON_FALSE, result);
	}
}
END_TEST

Suite *test_is_equal(void) {
  Suite *s = suite_create("\033[45m-=is_equal=-\033[0m");
  TCase *tc = tcase_create("is_equal_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_TRUE_is_equal);
  tcase_add_test(tc, test_FALSE_is_equal);
  suite_add_tcase(s, tc);
  return s;
}