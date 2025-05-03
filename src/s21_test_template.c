#include <check.h>

#include "s21_decimal.h"

// пример теста
START_TEST(s21_strncat_1) {
  char s21_str[10] = "abc";
  char str[10] = "abc";
  char cat[4] = "def";
  int n = 5;
  char *s21_res = s21_strncat(s21_str, cat, n);
  char *res = strncat(str, cat, n);
  ck_assert_str_eq(s21_res, res);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, s21_strncat_1);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  srunner_ntests_failed(sr);

  srunner_free(sr);

  return 0;
}