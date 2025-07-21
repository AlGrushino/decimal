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

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, s21_set_scale_big_1);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  srunner_ntests_failed(sr);

  srunner_free(sr);

  return 0;
}