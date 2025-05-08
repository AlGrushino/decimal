#include <check.h>

#include "s21_comparison.h"

// пример теста
START_TEST(s21_compare_sign_1) {
  s21_decimal decimal = {{0, 0, 0, 1}};
  int res = s21_compare_sign(decimal, decimal);
  ck_assert_int_eq(res, 1);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, s21_compare_sign_1);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  srunner_ntests_failed(sr);

  srunner_free(sr);

  return 0;
}