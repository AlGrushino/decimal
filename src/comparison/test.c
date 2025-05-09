#include <check.h>

#include "s21_comparison.h"

// s21_compare_sing
START_TEST(s21_compare_sign_1) {
  s21_decimal decimal = {{0, 0, 0, 2147483648}};
  int res = s21_compare_sign(decimal, decimal);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_compare_sign_2) {
  s21_decimal one = {{0, 0, 0, 2147483648}};
  s21_decimal two = {{0, 0, 0, 0}};

  int res = s21_compare_sign(one, two);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_compare_sign_3) {
  s21_decimal one = {{0, 0, 0, 2147483648}};
  s21_decimal two = {{0, 0, 0, 2147483648}};

  int res = s21_compare_sign(one, two);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_compare_sign_4) {
  s21_decimal one = {{0, 0, 0, 0}};
  s21_decimal two = {{0, 0, 0, 2147483648}};

  int res = s21_compare_sign(one, two);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_compare_sign_5) {
  s21_decimal one = {{0, 0, 0, 0}};
  s21_decimal two = {{0, 0, 0, 0}};

  int res = s21_compare_sign(one, two);
  ck_assert_int_eq(res, 1);
}
END_TEST

// s21_compare_to_zero
START_TEST(s21_compare_to_zero_1) {
  s21_decimal one = {{0, 0, 0, 0}};

  int res = s21_compare_to_zero(one);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_compare_to_zero_2) {
  s21_decimal one = {{0, 0, 0, 2147483648}};

  int res = s21_compare_to_zero(one);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_compare_to_zero_3) {
  s21_decimal one = {{1, 0, 0, 0}};

  int res = s21_compare_to_zero(one);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_compare_to_zero_4) {
  s21_decimal one = {{0, 1, 0, 0}};

  int res = s21_compare_to_zero(one);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_compare_to_zero_5) {
  s21_decimal one = {{0, 0, 1, 0}};

  int res = s21_compare_to_zero(one);
  ck_assert_int_eq(res, 0);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, tc1_1);

  // s21_compare_sing
  tcase_add_test(tc1_1, s21_compare_sign_1);
  tcase_add_test(tc1_1, s21_compare_sign_2);
  tcase_add_test(tc1_1, s21_compare_sign_3);
  tcase_add_test(tc1_1, s21_compare_sign_4);
  tcase_add_test(tc1_1, s21_compare_sign_5);

  // s21_compare_to_zero
  tcase_add_test(tc1_1, s21_compare_to_zero_1);
  tcase_add_test(tc1_1, s21_compare_to_zero_2);
  tcase_add_test(tc1_1, s21_compare_to_zero_3);
  tcase_add_test(tc1_1, s21_compare_to_zero_4);
  tcase_add_test(tc1_1, s21_compare_to_zero_5);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  srunner_ntests_failed(sr);

  srunner_free(sr);

  return 0;
}