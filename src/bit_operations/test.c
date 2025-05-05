#include <check.h>

#include "bit_operations.h"

// s21_check_bit
// нужные биты включены
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

// все биты выключены
START_TEST(check_bit_9) {
  // 0000 0000
  int num = 0;
  int index = 0;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_10) {
  // 0000 0000
  int num = 0;
  int index = 1;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_11) {
  // 0000 0000
  int num = 0;
  int index = 2;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_12) {
  // 0000 0000
  int num = 0;
  int index = 3;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_13) {
  // 0000 0000
  int num = 0;
  int index = 4;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_14) {
  // 0000 0000
  int num = 0;
  int index = 5;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_15) {
  // 0000 0000
  int num = 0;
  int index = 6;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_16) {
  // 0000 0000
  int num = 0;
  int index = 7;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

// все биты включены
START_TEST(check_bit_17) {
  // 1111 1111
  int num = 255;
  int index = 0;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_18) {
  // 1111 1111
  int num = 255;
  int index = 1;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_19) {
  // 1111 1111
  int num = 255;
  int index = 2;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_20) {
  // 1111 1111
  int num = 255;
  int index = 3;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_21) {
  // 1111 1111
  int num = 255;
  int index = 4;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_22) {
  // 1111 1111
  int num = 255;
  int index = 5;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_23) {
  // 1111 1111
  int num = 255;
  int index = 6;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_24) {
  // 1111 1111
  int num = 255;
  int index = 7;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 1);
}
END_TEST

// нужные биты выключены
START_TEST(check_bit_25) {
  // 1111 1110
  int num = 1;
  int index = 0;
  num = ~num;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_26) {
  // 1111 1101
  int num = 2;
  int index = 1;
  num = ~num;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_27) {
  // 1111 1011
  int num = 4;
  int index = 2;
  num = ~num;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_28) {
  // 1111 0111
  int num = 8;
  int index = 3;
  num = ~num;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_29) {
  // 1110 1111
  int num = 16;
  int index = 4;
  num = ~num;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_30) {
  // 1101 1111
  int num = 32;
  int index = 5;
  num = ~num;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_31) {
  // 1011 1111
  int num = 64;
  int index = 6;
  num = ~num;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_32) {
  // 0111 1111
  int num = 128;
  int index = 7;
  num = ~num;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

// граничные значения
START_TEST(check_bit_33) {
  // 1111 1111
  int num = 255;
  int index = 8;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_34) {
  // 1111 1111
  int num = 255;
  int index = -1;
  int res = s21_check_bit(num, index);

ck_assert_int_eq(res, 0);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, tc1_1);

//   s21_check_bit
// нужные биты включены
  tcase_add_test(tc1_1, check_bit_1);
  tcase_add_test(tc1_1, check_bit_2);
  tcase_add_test(tc1_1, check_bit_3);
  tcase_add_test(tc1_1, check_bit_4);
  tcase_add_test(tc1_1, check_bit_5);
  tcase_add_test(tc1_1, check_bit_6);
  tcase_add_test(tc1_1, check_bit_7);
  tcase_add_test(tc1_1, check_bit_8);
// все биты выключены
tcase_add_test(tc1_1, check_bit_9);
tcase_add_test(tc1_1, check_bit_10);
tcase_add_test(tc1_1, check_bit_11);
tcase_add_test(tc1_1, check_bit_12);
tcase_add_test(tc1_1, check_bit_13);
tcase_add_test(tc1_1, check_bit_14);
tcase_add_test(tc1_1, check_bit_15);
tcase_add_test(tc1_1, check_bit_16);
// все биты выключены
tcase_add_test(tc1_1, check_bit_17);
tcase_add_test(tc1_1, check_bit_18);
tcase_add_test(tc1_1, check_bit_19);
tcase_add_test(tc1_1, check_bit_20);
tcase_add_test(tc1_1, check_bit_21);
tcase_add_test(tc1_1, check_bit_22);
tcase_add_test(tc1_1, check_bit_23);
tcase_add_test(tc1_1, check_bit_24);
// нужные биты выключены
tcase_add_test(tc1_1, check_bit_25);
tcase_add_test(tc1_1, check_bit_26);
tcase_add_test(tc1_1, check_bit_27);
tcase_add_test(tc1_1, check_bit_28);
tcase_add_test(tc1_1, check_bit_29);
tcase_add_test(tc1_1, check_bit_30);
tcase_add_test(tc1_1, check_bit_31);
tcase_add_test(tc1_1, check_bit_32);
// граничные значения
tcase_add_test(tc1_1, check_bit_33);
tcase_add_test(tc1_1, check_bit_34);







  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  srunner_ntests_failed(sr);

  srunner_free(sr);

  return 0;
}