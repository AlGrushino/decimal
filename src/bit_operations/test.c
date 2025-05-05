#include <check.h>

#include "bit_operations.h"

// s21_check_bit
// проверить граничные значения
// проверяем, что биты действительно включены
START_TEST(check_bit_1) {
    // 0000 0001
    int num = 1;
    int index = 0;
    int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_2) {
    // 0000 0010
    int num = 2;
    int index = 1;
    int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_3) {
    // 0000 0100
    int num = 4;
    int index = 2;
    int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_4) {
    // 0000 1000
    int num = 8;
    int index = 3;
    int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_5) {
    // 0001 0000
    int num = 16;
    int index = 4;
    int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_6) {
    // 0010 0000
    int num = 32;
    int index = 5;
    int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_7) {
    // 0100 0000
    int num = 64;
    int index = 6;
    int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_8) {
    // 1000 0000
    int num = 128;
    int index = 7;
    int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST


int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, tc1_1);

//   s21_check_bit
  tcase_add_test(tc1_1, check_bit_1);
  tcase_add_test(tc1_1, check_bit_2);
  tcase_add_test(tc1_1, check_bit_3);
  tcase_add_test(tc1_1, check_bit_4);
  tcase_add_test(tc1_1, check_bit_5);
  tcase_add_test(tc1_1, check_bit_6);
  tcase_add_test(tc1_1, check_bit_7);
  tcase_add_test(tc1_1, check_bit_8);



  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  srunner_ntests_failed(sr);

  srunner_free(sr);

  return 0;
}