#include <check.h>

#include "big_decimal.h"

// s21_set_scale_big
START_TEST(s21_set_scale_big_1) {
  s21_big big = {0};
  s21_set_scale_big(&big, 1);
  int res = s21_get_scale_big(&big);

  ck_assert_int_eq(1, res);
}
END_TEST

// s21_gets_scale_big
START_TEST(s21_get_scale_big_1) {
  s21_big big = {0};
  s21_set_scale_big(&big, 1);
  int res = s21_get_scale_big(&big);

  ck_assert_int_eq(1, res);
}
END_TEST

// s21_mul_10_big
START_TEST(s21_mul_10_big_1) {
  s21_big big = {{0, 0, 0, 0, 10, 0, 0, 0}};

  int res = s21_mul_10_big(&big);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(big.bits[4], 100);
}
END_TEST

START_TEST(s21_mul_10_big_2) {
  s21_big big = {{0, 0, 0, 0, 0, UINT32_MAX, 0, 0}};
  int res = s21_mul_10_big(&big);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(big.bits[5], 4294967286);
  ck_assert_int_eq(big.bits[6], 9);
}
END_TEST

START_TEST(s21_mul_10_big_3) {
  s21_big big = {{0, 0, 0, 0, 0, 0, UINT32_MAX, 0}};
  int res = s21_mul_10_big(&big);

  ck_assert_int_eq(res, 1);
}
END_TEST

// s21_div_10_big
START_TEST(s21_div_10_big_1) {
  s21_big big = {{0, 0, 0, 0, 10, 0, 0, 0}};

  int res = s21_div_10_big(&big);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(big.bits[4], 1);
}
END_TEST

START_TEST(s21_div_10_big_2) {
  s21_big big = {{0, 0, 0, 0, 0, UINT32_MAX, 0, 0}};

  int res = s21_div_10_big(&big);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(big.bits[4], 2147483648);
  ck_assert_int_eq(big.bits[5], 429496729);

  res = s21_mul_10_big(&big);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(big.bits[4], 0);
  ck_assert_int_eq(big.bits[5], UINT32_MAX);
}
END_TEST

// s21_to_big
START_TEST(s21_to_big_1) {
  s21_decimal decimal = {{10, 10, 10, 1}};
  s21_big big = {{0, 0, 0, 0, 0, 0, 0, 0}};

  s21_to_big(&big, &decimal);

  ck_assert_int_eq(big.bits[0], 10);
  ck_assert_int_eq(big.bits[1], 10);
  ck_assert_int_eq(big.bits[2], 10);
  ck_assert_int_eq(big.bits[3], 0);
  ck_assert_int_eq(big.bits[4], 0);
  ck_assert_int_eq(big.bits[5], 0);
  ck_assert_int_eq(big.bits[6], 0);
  ck_assert_int_eq(big.bits[7], 1);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, tc1_1);

  // s21_set_scale_big
  tcase_add_test(tc1_1, s21_set_scale_big_1);

  // s21_gets_scale_big
  tcase_add_test(tc1_1, s21_get_scale_big_1);

  // s21_mul_10_big
  tcase_add_test(tc1_1, s21_mul_10_big_1);
  tcase_add_test(tc1_1, s21_mul_10_big_2);
  tcase_add_test(tc1_1, s21_mul_10_big_3);

  // s21_div_10_big
  tcase_add_test(tc1_1, s21_div_10_big_1);
  tcase_add_test(tc1_1, s21_div_10_big_2);

  // s21_to_big
  tcase_add_test(tc1_1, s21_to_big_1);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  srunner_ntests_failed(sr);

  srunner_free(sr);

  return 0;
}