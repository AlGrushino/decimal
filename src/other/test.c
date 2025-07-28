#include <check.h>

#include "s21_other.h"

// s21_negate
START_TEST(s21_negate_1) {
  s21_decimal a = {0};
  int res = s21_negate(a, NULL);

  ck_assert_int_eq(res, CALC_ERR);
}
END_TEST

START_TEST(s21_negate_2) {
  s21_decimal a = {{10, 10, 10, 0}};
  s21_decimal b = {0};

  s21_decimal_set_sign(&a);
  int res = s21_negate(a, &b);

  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_negate_3) {
  s21_decimal a = {{10, 10, 10, 0}};
  s21_decimal b = {0};

  int res = s21_negate(a, &b);

  ck_assert_int_eq(res, OK);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, tc1_1);

  // s21_negate
  tcase_add_test(tc1_1, s21_negate_1);
  tcase_add_test(tc1_1, s21_negate_2);
  tcase_add_test(tc1_1, s21_negate_3);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  srunner_ntests_failed(sr);

  srunner_free(sr);

  return 0;
}