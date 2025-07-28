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

// s21_normalize_scale_big
// scale_a > scale_b
START_TEST(s21_normalize_scale_big_1) {
  s21_big a = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_big b = {{10, 0, 0, 0, 0, 0, 0, 0}};

  s21_set_scale_big(&b, 4);
  ck_assert_int_eq(4, s21_get_scale_big(&b));

  int res = s21_normalize_scale_big(&a, &b);
  ck_assert_int_eq(res, 0);

  int scale_a = 0;
  int scale_b = 0;

  int res_scale_a = s21_get_scale_big(&a);
  int res_scale_b = s21_get_scale_big(&b);

  ck_assert_int_eq(res_scale_a, res_scale_b);
  ck_assert_int_eq(scale_a, res_scale_a);
  ck_assert_int_eq(scale_b, res_scale_b);
  ck_assert_int_eq(a.bits[0], 100000);
}
END_TEST

START_TEST(s21_normalize_scale_big_2) {
  s21_big a = {{0, 0, 0, 0, 0, 0, 1, 0}};
  s21_big b = {{1000000000, 0, 0, 0, 0, 0, 0, 0}};

  s21_set_scale_big(&b, 28);
  ck_assert_int_eq(28, s21_get_scale_big(&b));

  int res = s21_normalize_scale_big(&a, &b);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_normalize_scale_big_3) {
  s21_big a = {{0, 0, 0, 0, 0, 0, 1, 0}};
  s21_big b = {{0, 0, 0, 1000000000, 0, 0, 0, 0}};

  s21_set_scale_big(&b, 14);
  ck_assert_int_eq(14, s21_get_scale_big(&b));

  int res = s21_normalize_scale_big(&a, &b);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_get_scale_big(&a), s21_get_scale_big(&b));
  ck_assert_int_eq(a.bits[6], 1000000000);
  ck_assert_int_eq(b.bits[3], 10000);

  int scale_a = s21_get_scale_big(&a);
  int scale_b = s21_get_scale_big(&b);

  ck_assert_int_eq(scale_a, 5);
  ck_assert_int_eq(scale_b, 5);
}
END_TEST

// scale_b > scale_a
START_TEST(s21_normalize_scale_big_4) {
  s21_big a = {{0, 0, 0, 1000000000, 0, 0, 0, 0}};
  s21_big b = {{0, 0, 0, 0, 0, 0, 1, 0}};

  s21_set_scale_big(&a, 14);
  ck_assert_int_eq(14, s21_get_scale_big(&a));

  int res = s21_normalize_scale_big(&a, &b);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_get_scale_big(&a), s21_get_scale_big(&b));
  ck_assert_int_eq(b.bits[6], 1000000000);
  ck_assert_int_eq(a.bits[3], 10000);

  int scale_a = s21_get_scale_big(&a);
  int scale_b = s21_get_scale_big(&b);

  ck_assert_int_eq(scale_a, 5);
  ck_assert_int_eq(scale_b, 5);
}
END_TEST

START_TEST(s21_normalize_scale_big_5) {
  s21_big a = {{1000000000, 0, 0, 0, 0, 0, 0, 0}};
  s21_big b = {{0, 0, 0, 0, 0, 0, 1, 0}};

  s21_set_scale_big(&a, 28);
  ck_assert_int_eq(28, s21_get_scale_big(&a));

  int res = s21_normalize_scale_big(&b, &a);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_normalize_scale_big_6) {
  s21_big a = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_big b = {{10, 0, 0, 0, 0, 0, 0, 0}};

  s21_set_scale_big(&a, 4);
  ck_assert_int_eq(4, s21_get_scale_big(&a));

  int res = s21_normalize_scale_big(&b, &a);
  ck_assert_int_eq(res, 0);

  int scale_a = 0;
  int scale_b = 0;

  int res_scale_a = s21_get_scale_big(&b);
  int res_scale_b = s21_get_scale_big(&a);

  ck_assert_int_eq(res_scale_a, res_scale_b);
  ck_assert_int_eq(scale_a, res_scale_a);
  ck_assert_int_eq(scale_b, res_scale_b);
  ck_assert_int_eq(b.bits[0], 100000);
}
END_TEST

START_TEST(s21_normalize_scale_big_7) {
  s21_big a = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_big b = {{10, 0, 0, 0, 0, 0, 0, 0}};

  int scale_a = 4;
  int scale_b = 4;

  s21_set_scale_big(&a, scale_a);
  s21_set_scale_big(&b, scale_b);
  ck_assert_int_eq(4, s21_get_scale_big(&b));
  ck_assert_int_eq(4, s21_get_scale_big(&a));

  int res = s21_normalize_scale_big(&a, &b);
  ck_assert_int_eq(res, 0);

  int res_scale_a = s21_get_scale_big(&a);
  int res_scale_b = s21_get_scale_big(&b);

  ck_assert_int_eq(res_scale_a, res_scale_b);
  ck_assert_int_eq(scale_a, res_scale_a);
  ck_assert_int_eq(scale_b, res_scale_b);
  ck_assert_int_eq(a.bits[0], 10);
  ck_assert_int_eq(b.bits[0], 10);
}
END_TEST

START_TEST(s21_normalize_scale_big_8) {
  s21_big a = {{0, 0, 0, 0, 0, 0, 1, 0}};
  s21_big b = {{1000000000, 0, 0, 0, 0, 0, 0, 0}};

  s21_set_scale_big(&b, 28);
  ck_assert_int_eq(28, s21_get_scale_big(&b));

  int res = s21_normalize_scale_big(&b, &a);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_normalize_scale_big_9) {
  s21_big a = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_big b = {{10, 0, 0, 0, 0, 0, 0, 0}};

  s21_set_scale_big(&b, 4);
  ck_assert_int_eq(4, s21_get_scale_big(&b));

  int res = s21_normalize_scale_big(&b, &a);
  ck_assert_int_eq(res, 0);

  int scale_a = 0;
  int scale_b = 0;

  int res_scale_a = s21_get_scale_big(&a);
  int res_scale_b = s21_get_scale_big(&b);

  ck_assert_int_eq(res_scale_a, res_scale_b);
  ck_assert_int_eq(scale_a, res_scale_a);
  ck_assert_int_eq(scale_b, res_scale_b);
  ck_assert_int_eq(a.bits[0], 100000);
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

  // s21_normalize_scale_big
  tcase_add_test(tc1_1, s21_normalize_scale_big_1);
  tcase_add_test(tc1_1, s21_normalize_scale_big_2);
  tcase_add_test(tc1_1, s21_normalize_scale_big_3);
  tcase_add_test(tc1_1, s21_normalize_scale_big_4);
  tcase_add_test(tc1_1, s21_normalize_scale_big_5);
  tcase_add_test(tc1_1, s21_normalize_scale_big_6);
  tcase_add_test(tc1_1, s21_normalize_scale_big_7);
  tcase_add_test(tc1_1, s21_normalize_scale_big_8);
  tcase_add_test(tc1_1, s21_normalize_scale_big_9);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  srunner_ntests_failed(sr);

  srunner_free(sr);

  return 0;
}