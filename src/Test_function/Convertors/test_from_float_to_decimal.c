#include "../Test.h"

START_TEST(test_OK_from_float_to_decimal){

	float f[] = {
	     -3e10,
	     -1093.54,
	     0.0,
	     1e-03,
		 1034.23,
		 1e-28,
		 7.9228162514264337593543950335e28,
	     -7.9228162514264337593543950335e28,
		 123456800,
	};
	size_t n = sizeof(f) / sizeof(f[0]);
	for (size_t i = 0; i < n; i++) {
	  s21_decimal actual;
	  int result = s21_from_float_to_decimal(f[i], &actual);
	  ck_assert_int_eq(TEST_CONVERTORS_OK, result);
	}
}
END_TEST

START_TEST(test_ERROR_from_float_to_decimal){

	float f[] = {
	     (0. / 0.),
	     (1. / 0.),
		 1e-40,
	};
	size_t n = sizeof(f) / sizeof(f[0]);
	for (size_t i = 0; i < n; i++) {
	  s21_decimal actual;
	  int result = s21_from_float_to_decimal(f[i], &actual);
	  ck_assert_int_eq(TEST_CONVERTORS_ERROR, result);
	}

}
END_TEST

START_TEST(test_output_from_float_to_decimal){

	float float_input[] = {
	     -3e10,
	     -1093.54,
	     0.0,
	     1e-03,
		 1034.23,
		 1e-28,
		 //7.9228162514264337593543950335e28,
	     //-7.9228162514264337593543950335e28,

		 123456789.9,
	     12345678.9,
	     1234567.89,
	     123456.789,
		 12345.6789,
		 1234.56789,
		 123.456789,
	     12.3456789,
	};

	float origin_output[] = {
		-30000000000,
		-1093.54,
		0,
		0.001,
		1034.23,
		1e-28,
		//7.9228162514264337593543950335e28,//тут наверное теряется точность и надо делать s21_decimal bits[7] чтобы использовать его для расчетов и в конце переводить в обычный дец
	    //-7.9228162514264337593543950335e28,// -//-

		123456800,
		12345680,
		1234568,
		123456.8,
		12345.68,
		1234.568,
		123.4568,
		12.34568,
	};

	size_t n = sizeof(float_input) / sizeof(float_input[0]);
	for (size_t i = 0; i < n; i++) {
	  s21_decimal my_dec_output;
	  s21_from_float_to_decimal(float_input[i], &my_dec_output);//преобразование тестовых float в децимал
	  /// printf("%f \n", float_input[i]);
	  float my_float_output;
	  s21_from_decimal_to_float(my_dec_output, &my_float_output);//обратное преобразование децимала в **флоат**
	  //printf("%f \n", my_float_output);
	  //printf("my     %-50lf\norigin %-50lf\n\n", my_float_output, origin_output[i]);
	  ck_assert_float_eq(my_float_output, origin_output[i]);
	  //printf("%lf %lf\n", my_float_output, origin_output[i]);
	}

}
Suite *test_from_float_to_decimal(void) {
  Suite *s = suite_create("\033[45m-=from_float_to_decimal=-\033[0m");
  TCase *tc = tcase_create("from_float_to_decimal_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_OK_from_float_to_decimal);
  tcase_add_test(tc, test_ERROR_from_float_to_decimal);
  tcase_add_test(tc, test_output_from_float_to_decimal);
  suite_add_tcase(s, tc);
  return s;
}

// using System; ///C# https://www.programiz.com/csharp-programming/online-compiler/

// public class HelloWorld
// {
//     public static void Main(string[] args)
//     {
//         float[] numbers = { 
		    //  123456789.9f,
		    //  12345678.9f,
		    //  1234567.89f,
		    //  123456.789f,
			//  12345.6789f,
			//  1234.56789f,
			//  123.456789f,
		    //  12.3456789f,
//         };
//         decimal result;
        
//         foreach (float number in numbers)
//         {
//            try {
//               result = Convert.ToDecimal(number);
//               //Console.WriteLine("Converted the Single value {0} to {1}.", number, result);
//               Console.WriteLine("{0},", result);
//            }
//            catch (OverflowException) {
//               Console.WriteLine("{0} is out of range of the Decimal type.", number);
//            }
//         }
//     }
// }
