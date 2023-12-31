#include "s21_math.h"

#include <check.h>
#include <math.h>
#include <stdlib.h>
#define TOL 1e-6
#define INT_MIN -2147483648
#define INT_MAX 2147483647

// test_nan
START_TEST(test_nan) {
  ck_assert_ldouble_nan(s21_pow(NAN, NAN));
  ck_assert_ldouble_nan(pow(NAN, NAN));
  ck_assert_ldouble_nan(s21_pow(-1, 5.6));
  ck_assert_ldouble_nan(pow(-1, 5.6));
  ck_assert_ldouble_nan(s21_fmod(INFINITY, INFINITY));
  ck_assert_ldouble_nan(fmod(INFINITY, INFINITY));
  ck_assert_ldouble_eq(s21_fmod(46, INFINITY), fmod(46, INFINITY));
  ck_assert_ldouble_nan(s21_ceil(NAN));
  ck_assert_ldouble_nan(ceil(NAN));
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_nan(floor(NAN));
}
END_TEST

// test_inf
START_TEST(test_inf) {
  ck_assert_ldouble_eq(s21_pow(-INFINITY, INFINITY), pow(-INFINITY, INFINITY));
  ck_assert_ldouble_eq(s21_pow(-INFINITY, -INFINITY),
                       pow(-INFINITY, -INFINITY));
}
END_TEST

// s21_abs
START_TEST(test_abs_positive) {
  int x = INT_MAX;
  int s21_result = s21_abs(x);
  int math_result = abs(x);
  ck_assert_int_eq(s21_result, math_result);
}
END_TEST

START_TEST(test_abs_negative) {
  int x = INT_MIN;
  int s21_result = s21_abs(x);
  int math_result = abs(x);
  ck_assert_int_eq(s21_result, math_result);
}
END_TEST

START_TEST(test_abs_zero) {
  int x = 0;
  int s21_result = s21_abs(x);
  int math_result = abs(x);
  ck_assert_int_eq(s21_result, math_result);
}
END_TEST

// s21_fmod
START_TEST(test_fmod_zero) {
  double x = 999.999995;
  double y = 0;
  long double s21_result = s21_fmod(x, y);
  long double math_result = fmod(x, y);

  ck_assert(isnan(s21_result) && isnan(math_result));
}
END_TEST

START_TEST(test_fmod_positive) {
  double x = 123123.13213213;
  double y = 21313.654659999;
  long double s21_result = s21_fmod(x, y);
  long double math_result = fmod(x, y);

  ck_assert_ldouble_eq(s21_result, math_result);
}
END_TEST

START_TEST(test_fmod_negative) {
  double x = -4564564.1324512;
  double y = 999.99999;
  long double s21_result = s21_fmod(x, y);
  long double math_result = fmod(x, y);

  ck_assert_ldouble_eq(s21_result, math_result);
}
END_TEST

// long double fabs(double x)
START_TEST(test_fabs_positive) {
  double x = 9999.9994569;
  long double s21_result = s21_fabs(x);
  long double math_result = fabs(x);

  ck_assert_ldouble_eq(s21_result, math_result);
}
END_TEST

START_TEST(test_fabs_negative) {
  double x = -9999.99654999;
  long double s21_result = s21_fabs(x);
  long double math_result = fabs(x);

  ck_assert_ldouble_eq(s21_result, math_result);
}
END_TEST

// ceil
START_TEST(test_ceil_positive) {
  double x = 999.12341234312;
  long double s21_result = s21_ceil(x);
  long double math_result = ceil(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

START_TEST(test_ceil_negative) {
  double x = -999.34252345;
  long double s21_result = s21_ceil(x);
  long double math_result = ceil(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

// floor
START_TEST(test_floor_positive) {
  double x;
  long double s21_result;
  long double math_result;

  x = 46546456.4646546;
  s21_result = s21_floor(x);
  math_result = floor(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

START_TEST(test_floor_negative) {
  double x;
  long double s21_result;
  long double math_result;

  x = -654564.465432146544;
  s21_result = s21_floor(x);
  math_result = floor(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

// s21_pow
START_TEST(test_pow_zero) {
  double x = 2345634.45665413, y = 0;
  long double s21_result = s21_pow(x, y);
  long double math_result = pow(x, y);

  ck_assert_ldouble_eq(s21_result, math_result);
}
END_TEST

START_TEST(test_pow_positive) {
  double x = 134, y = 3;
  long double s21_result = s21_pow(x, y);
  long double math_result = pow(x, y);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

START_TEST(test_pow_negative_1) {
  double x = -1, y = -2;
  long double s21_result = s21_pow(x, y);
  long double math_result = pow(x, y);

  ck_assert_ldouble_eq(s21_result, math_result);
}
END_TEST

START_TEST(test_pow_negative_2) {
  double test[] = {-3, 3};
  double test_1[] = {3, -3, 2, -4};
  long double s21_result = s21_pow(test[_i], test_1[_i]);
  long double math_result = pow(test[_i], test_1[_i]);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

// s21_exp
START_TEST(test_exp_positive) {
  double x = 17;
  long double s21_result = s21_exp(x);
  long double math_result = exp(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

START_TEST(test_exp_inf) {
  double x = 710;
  long double s21_result = s21_exp(x);
  long double math_result = exp(x);

  ck_assert(isinf(s21_result) && isinf(math_result));
}
END_TEST

START_TEST(test_exp_negative) {
  double x;
  long double s21_result;
  long double math_result;

  x = -13.54;
  s21_result = s21_exp(x);
  math_result = exp(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

// s21_cos
START_TEST(test_cos_positive) {
  double x = 13223.165456411;
  long double s21_result = s21_cos(x);
  long double math_result = cos(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

START_TEST(test_cos_negative) {
  double x = -65456.65456465;
  long double s21_result = s21_cos(x);
  long double math_result = cos(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

// s21_sin
START_TEST(test_sin_positive) {
  double x = 646545.146546546;
  long double s21_result = s21_sin(x);
  long double math_result = sin(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

START_TEST(test_sin_negative) {
  double x = -23132.146548465;
  long double s21_result = s21_sin(x);
  long double math_result = sin(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

// s21_sqrt
START_TEST(test_sqrt_positive) {
  double x;
  long double s21_result;
  long double math_result;

  x = 9999999999.99999999;
  s21_result = s21_sqrt(x);
  math_result = sqrt(x);
  ck_assert_ldouble_eq(s21_result, math_result);
}
END_TEST

START_TEST(test_sqrt_zero) {
  double x = 0;
  long double s21_result = s21_sqrt(x);
  long double math_result = sqrt(x);

  ck_assert_ldouble_eq(s21_result, math_result);
}
END_TEST

START_TEST(test_sqrt_negative) {
  double x = -5;
  long double s21_result = s21_sqrt(x);
  long double math_result = sqrt(x);

  // Check if both results are NaN
  ck_assert(isnan(s21_result) && isnan(math_result));
}
END_TEST

START_TEST(test_sqrt_small) {
  double x = 0.0000001;
  long double s21_result = s21_sqrt(x);
  long double math_result = sqrt(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

// s21_log
START_TEST(test_log_positive) {
  double x = 99999999.31243214123;
  long double s21_result = s21_log(x);
  long double math_result = log(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

START_TEST(test_log_negative) {
  double x = -9999999.123413243124;
  long double s21_result = s21_log(x);
  long double math_result = log(x);

  // Check if both results are NaN
  ck_assert(isnan(s21_result) && isnan(math_result));
}
END_TEST

START_TEST(test_log_zero) {
  double x = 0;
  long double s21_result = s21_log(x);
  long double math_result = log(x);

  ck_assert_ldouble_eq(s21_result, math_result);
}
END_TEST

// s21_tan
START_TEST(test_tan_positive) {
  double x = 21131.4665465;
  long double s21_result = s21_tan(x);
  long double math_result = tan(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

START_TEST(test_tan_negative) {
  double x = -43155.5654665;
  long double s21_result = s21_tan(x);
  long double math_result = tan(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

START_TEST(test_tan_zero) {
  double x = 0;
  long double s21_result = s21_tan(x);
  long double math_result = tan(x);

  ck_assert_ldouble_eq(s21_result, math_result);
}
END_TEST

// s21_acos
START_TEST(test_acos_positive) {
  double x = 1;
  long double s21_result = s21_acos(x);
  long double math_result = acos(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

START_TEST(test_acos_negative) {
  double x = -1;
  long double s21_result = s21_acos(x);
  long double math_result = acos(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

START_TEST(test_acos_zero) {
  double x = 0;
  long double s21_result = s21_asin(x);
  long double math_result = asin(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

START_TEST(test_acos_ECase_1) {
  double x = 2;
  long double s21_result = s21_acos(x);
  long double math_result = acos(x);

  // Check if both results are NaN
  ck_assert(isnan(s21_result) && isnan(math_result));
}
END_TEST

START_TEST(test_acos_ECase_2) {
  double x = -2;
  long double s21_result = s21_acos(x);
  long double math_result = s21_acos(x);

  // Check if both results are NaN
  ck_assert(isnan(s21_result) && isnan(math_result));
}
END_TEST

// s21_asin
START_TEST(test_asin_positive) {
  double x;
  long double s21_result;
  long double math_result;

  x = 1;
  s21_result = s21_asin(x);
  math_result = asin(x);
  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

START_TEST(test_asin_negative) {
  double x = -1;
  long double s21_result = s21_asin(x);
  long double math_result = asin(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

START_TEST(test_asin_zero) {
  double x = 0;
  long double s21_result = s21_asin(x);
  long double math_result = asin(x);

  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

START_TEST(test_asin_ECase_1) {
  double x = 1.9;
  long double s21_result = s21_asin(x);
  long double math_result = asin(x);

  // Check if both results are NaN
  ck_assert(isnan(s21_result) && isnan(math_result));
}
END_TEST

START_TEST(test_asin_ECase_2) {
  double x = -1.9;
  long double s21_result = s21_asin(x);
  long double math_result = asin(x);

  // Check if both results are NaN
  ck_assert(isnan(s21_result) && isnan(math_result));
}
END_TEST

// s21_atan
START_TEST(test_atan) {
  double x;
  long double s21_result;
  long double math_result;

  double test[] = {-0.4244365, 0.4244465, 13.54};
  s21_result = s21_atan(test[_i]);
  math_result = atan(test[_i]);
  ck_assert_ldouble_eq_tol(s21_result, math_result, TOL);
}
END_TEST

// Create the test suite
Suite* s21_math_suite(void) {
  Suite* suite = suite_create("s21_math");

  // test_nan
  TCase* tc_nan = tcase_create("nan");
  tcase_add_test(tc_nan, test_nan);
  suite_add_tcase(suite, tc_nan);

  // test_inf
  TCase* tc_inf = tcase_create("inf");
  tcase_add_test(tc_inf, test_inf);
  suite_add_tcase(suite, tc_inf);

  // Create a test case for abs
  TCase* tc_abs = tcase_create("abs");
  tcase_add_test(tc_abs, test_abs_positive);
  tcase_add_test(tc_abs, test_abs_negative);
  tcase_add_test(tc_abs, test_abs_zero);
  suite_add_tcase(suite, tc_abs);

  // fabs
  TCase* tc_fabs = tcase_create("fabs");
  tcase_add_test(tc_fabs, test_fabs_positive);
  tcase_add_test(tc_fabs, test_fabs_negative);
  suite_add_tcase(suite, tc_fabs);

  // fmod
  TCase* tc_fmod = tcase_create("fmod");
  tcase_add_test(tc_fmod, test_fmod_zero);
  tcase_add_test(tc_fmod, test_fmod_positive);
  tcase_add_test(tc_fmod, test_fmod_negative);
  suite_add_tcase(suite, tc_fmod);

  // ceil
  TCase* tc_ceil = tcase_create("ceil");
  tcase_add_test(tc_ceil, test_ceil_positive);
  tcase_add_test(tc_ceil, test_ceil_negative);
  suite_add_tcase(suite, tc_ceil);

  // floor
  TCase* tc_floor = tcase_create("floor");
  tcase_add_test(tc_floor, test_floor_positive);
  tcase_add_test(tc_floor, test_floor_negative);
  suite_add_tcase(suite, tc_floor);

  // pow
  TCase* tc_pow = tcase_create("pow");
  tcase_add_test(tc_pow, test_pow_zero);
  tcase_add_test(tc_pow, test_pow_positive);
  tcase_add_test(tc_pow, test_pow_negative_1);
  tcase_add_test(tc_pow, test_pow_negative_2);
  suite_add_tcase(suite, tc_pow);

  // exp
  TCase* tc_exp = tcase_create("exp");
  tcase_add_test(tc_exp, test_exp_positive);
  tcase_add_test(tc_exp, test_exp_inf);
  tcase_add_test(tc_exp, test_exp_negative);
  suite_add_tcase(suite, tc_exp);

  // cos
  TCase* tc_cos = tcase_create("cos");
  tcase_add_test(tc_cos, test_cos_positive);
  tcase_add_test(tc_cos, test_cos_negative);
  suite_add_tcase(suite, tc_cos);

  // sin
  TCase* tc_sin = tcase_create("sin");
  tcase_add_test(tc_sin, test_sin_positive);
  tcase_add_test(tc_sin, test_sin_negative);
  suite_add_tcase(suite, tc_sin);

  // sqrt
  TCase* tc_sqrt = tcase_create("sqrt");
  tcase_add_test(tc_sqrt, test_sqrt_positive);
  tcase_add_test(tc_sqrt, test_sqrt_negative);
  tcase_add_test(tc_sqrt, test_sqrt_zero);
  tcase_add_test(tc_sqrt, test_sqrt_small);
  suite_add_tcase(suite, tc_sqrt);

  // log
  TCase* tc_log = tcase_create("log");
  tcase_add_test(tc_log, test_log_positive);
  tcase_add_test(tc_log, test_log_negative);
  tcase_add_test(tc_log, test_log_zero);
  suite_add_tcase(suite, tc_log);

  // tan
  TCase* tc_tan = tcase_create("tan");
  tcase_add_test(tc_tan, test_tan_zero);
  tcase_add_test(tc_tan, test_tan_positive);
  tcase_add_test(tc_tan, test_tan_negative);
  tcase_add_test(tc_tan, test_tan_zero);
  suite_add_tcase(suite, tc_tan);

  // acos
  TCase* tc_acos = tcase_create("acos");
  tcase_add_test(tc_acos, test_acos_positive);
  tcase_add_test(tc_acos, test_acos_negative);
  tcase_add_test(tc_acos, test_acos_zero);
  tcase_add_test(tc_acos, test_acos_ECase_1);
  tcase_add_test(tc_acos, test_acos_ECase_2);
  suite_add_tcase(suite, tc_acos);

  // asin
  TCase* tc_asin = tcase_create("asin");
  tcase_add_test(tc_asin, test_asin_positive);
  tcase_add_test(tc_asin, test_asin_negative);
  tcase_add_test(tc_asin, test_asin_zero);
  tcase_add_test(tc_asin, test_asin_ECase_1);
  tcase_add_test(tc_asin, test_asin_ECase_2);
  suite_add_tcase(suite, tc_asin);

  // atan
  TCase* tc_atan = tcase_create("atan");
  tcase_add_test(tc_atan, test_atan);
  suite_add_tcase(suite, tc_atan);

  return suite;
}

// Run the test suite
int main(void) {
  Suite* suite = s21_math_suite();
  SRunner* runner = srunner_create(suite);
  srunner_run_all(runner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  // // Run gcov to get coverage report
  // system("gcov s21_math.c");

  return number_failed == 0 ? 0 : 1;
}
