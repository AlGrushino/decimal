#include <check.h>
#include <limits.h>

#include "s21_other.h"
#include "../something.h"


START_TEST(check_set_scale) {
    s21_decimal num1 = {{1, 0, 0, 0}};
    for (int i = 0; i < 29; i++){
        set_scale(&num1, i);
        int res = get_scale(&num1);
        ck_assert_int_eq(res, i);
    }
  }
END_TEST

START_TEST(check_set_sign) { //что делать если знак невалидный?
    s21_decimal num1 = {{0, 0, 0, 0}};
    s21_decimal num2 = {{1, 0, 0, 0}};
    s21_decimal num3 = {{INT_MAX, 0, 0, 0}};
    for (int i = 0; i < 1; i++){
        set_sign(&num1, i);
        set_sign(&num2, i);
        set_sign(&num3, i);
        int res1 = get_sign(&num1);
        int res2 = get_sign(&num2);
        int res3 = get_sign(&num3);
        ck_assert_int_eq(res1, i);
        ck_assert_int_eq(res2, i);
        ck_assert_int_eq(res3, i);
    }
  }
END_TEST

START_TEST(check_s21_is_equal) {
    for (int i = 1; i < 100; i++) {
        s21_decimal num1 = {{0, 0, 0, 0}};
        s21_decimal num2 = {{i, 0, 0, 0}};
        int res1 = s21_is_equal(num1, num2);
        ck_assert_int_eq(res1, 0);
    }

    s21_decimal num3 = {{INT_MAX, 0, 0, 0}};
    s21_decimal num4 = {{INT_MAX, 0, 0, 0}};
    int res2 = s21_is_equal(num3, num4);
    ck_assert_int_eq(res2, 1);
  }
END_TEST

START_TEST(check_s21_is_not_equal) {
    for (int i = 1; i < 100; i++) {
        s21_decimal num1 = {{0, 0, 0, 0}};
        s21_decimal num2 = {{i, 0, 0, 0}};
        int res1 = s21_is_not_equal(num1, num2);
        ck_assert_int_eq(res1, 1);
    }

    s21_decimal num3 = {{INT_MAX, 0, 0, 0}};
    s21_decimal num4 = {{INT_MAX, 0, 0, 0}};
    int res2 = s21_is_not_equal(num3, num4);
    ck_assert_int_eq(res2, 0);
  }
END_TEST

START_TEST(check_s21_is_less) {
    for (int i = 1; i < 100; i++) {
        s21_decimal num1 = {{0, 0, 0, 0}};
        s21_decimal num2 = {{i, 0, 0, 0}};
        int res1 = s21_is_less(num1, num2);
        ck_assert_int_eq(res1, 1);
    }

    s21_decimal num3 = {{INT_MAX, 0, 0, 0}};
    s21_decimal num4 = {{INT_MAX, 0, 0, 0}};
    int res2 = s21_is_less(num3, num4);
    ck_assert_int_eq(res2, 0);

    set_sign(&num3, 1);
    int res3 = s21_is_less(num3, num4);
    ck_assert_int_eq(res3, 1);

    s21_decimal num5 = {{5, 0, 0, 0}};
    s21_decimal num6 = {{INT_MAX, 0, 0, 0}};
    set_scale(&num6, 29);
    int res4 = s21_is_less(num5, num6);
    ck_assert_int_eq(res4, 0);

    s21_decimal num7 = {{INT_MAX, 0, 0, 0}};
    s21_decimal num8 = {{INT_MAX, 0, 0, 0}};
    set_sign(&num7, 1);
    set_sign(&num8, 1);
    set_scale(&num7, 27);
    set_scale(&num8, 28);
    int res5 = s21_is_less(num7, num8);
    ck_assert_int_eq(res5, 1);
  }
END_TEST


START_TEST(check_s21_is_less_or_equal) {
    for (int i = 0; i < 100; i++) {
        s21_decimal num1 = {{0, 0, 0, 0}};
        s21_decimal num2 = {{i, 0, 0, 0}};
        int res1 = s21_is_less_or_equal(num1, num2);
        ck_assert_int_eq(res1, 1);
    }

    s21_decimal num3 = {{INT_MAX, 0, 0, 0}};
    s21_decimal num4 = {{INT_MAX, 0, 0, 0}};
    int res2 = s21_is_less_or_equal(num3, num4);
    ck_assert_int_eq(res2, 1);

    set_sign(&num3, 1);
    int res3 = s21_is_less_or_equal(num3, num4);
    ck_assert_int_eq(res3, 1);

    s21_decimal num5 = {{10, 0, 0, 0}};
    s21_decimal num6 = {{INT_MAX, 0, 0, 0}};
    set_scale(&num6, 28);
    int res4 = s21_is_less_or_equal(num5, num6);
    ck_assert_int_eq(res4, 0);

    s21_decimal num7 = {{INT_MAX, 0, 0, 0}};
    s21_decimal num8 = {{INT_MAX, 0, 0, 0}};
    set_scale(&num7, 28);
    set_scale(&num8, 27);
    int res5 = s21_is_less(num7, num8);
    ck_assert_int_eq(res5, 1);
  }
END_TEST

START_TEST(check_s21_is_greater) {
    for (int i = 1; i < 100; i++) {
        s21_decimal num1 = {{i, 0, 0, 0}};
        s21_decimal num2 = {{0, 0, 0, 0}};
        int res1 = s21_is_greater(num1, num2);
        ck_assert_int_eq(res1, 1);
    }

    s21_decimal num3 = {{INT_MAX, 0, 0, 0}};
    s21_decimal num4 = {{INT_MAX, 0, 0, 0}};
    set_sign(&num4, 1);
    int res2 = s21_is_greater(num3, num4);
    ck_assert_int_eq(res2, 1);

    s21_decimal num5 = {{INT_MAX, 0, 0, 0}};
    s21_decimal num6 = {{INT_MAX, 0, 0, 0}};
    set_scale(&num5, 2);
    int res3 = s21_is_greater(num5, num6);
    ck_assert_int_eq(res3, 0);
  }
END_TEST

START_TEST(check_s21_is_greater_or_equal) {
    for (int i = 0; i < 100; i++) {
        s21_decimal num1 = {{i, 0, 0, 0}};
        s21_decimal num2 = {{0, 0, 0, 0}};
        int res1 = s21_is_greater_or_equal(num1, num2);
        ck_assert_int_eq(res1, 1);
    }

    s21_decimal num3 = {{INT_MAX, 0, 0, 0}};
    s21_decimal num4 = {{INT_MAX, 0, 0, 0}};
    int res2 = s21_is_greater_or_equal(num3, num4);
    ck_assert_int_eq(res2, 1);

    set_sign(&num4, 1);
    int res3 = s21_is_greater_or_equal(num3, num4);
    ck_assert_int_eq(res3, 1);

    s21_decimal num5 = {{10, 0, 0, 0}};
    s21_decimal num6 = {{INT_MAX, 0, 0, 0}};
    set_scale(&num6, 28);
    int res4 = s21_is_greater_or_equal(num5, num6);
    ck_assert_int_eq(res4, 1);

    s21_decimal num7 = {{INT_MAX, 0, 0, 0}};
    s21_decimal num8 = {{INT_MAX, 0, 0, 0}};
    set_scale(&num7, 27);
    set_scale(&num8, 28);
    int res5 = s21_is_greater_or_equal(num7, num8);
    ck_assert_int_eq(res5, 1);

    s21_decimal num9 = {{INT_MAX, 0, 0, 0}};
    s21_decimal num10 = {{INT_MAX, 0, 0, 0}};
    set_scale(&num9, 30);
    set_scale(&num10, 29);
    int res6 = s21_is_greater_or_equal(num7, num8);
    ck_assert_int_eq(res6, 1);
  }
END_TEST

START_TEST(check_div_by_ten_times) {
    s21_decimal num1 = {{15, 0, 0, 0}};
    div_by_ten_times(&num1, 1);
    s21_decimal res_num1 = {{2, 0, 0, 0}};
    int res = s21_is_equal(num1, res_num1);
    ck_assert_int_eq(res, 1);
  }
END_TEST

START_TEST(check_normalization) {
    s21_decimal num1 = {{150, 0, 0, 0}};
    s21_decimal num2 = {{150, 0, 0, 0}};
    set_scale(&num1, 29);
    set_scale(&num2, 5);
    int res1 = s21_is_equal(num1, num2);
    ck_assert_int_eq(res1, 0);

    s21_decimal num3 = {{150000, 0, 0, 0}};
    s21_decimal num4 = {{150000, 0, 0, 0}};
    set_scale(&num3, 30);
    set_scale(&num4, 30);
    int res2 = s21_is_equal(num3, num4);
    ck_assert_int_eq(res2, 1);

  }
END_TEST



int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    suite_add_tcase(s1, tc1_1);
  
    tcase_add_test(tc1_1, check_set_scale);
    tcase_add_test(tc1_1, check_set_sign);
    tcase_add_test(tc1_1, check_s21_is_equal);
    tcase_add_test(tc1_1, check_s21_is_not_equal);
    tcase_add_test(tc1_1, check_s21_is_less);
    tcase_add_test(tc1_1, check_s21_is_less_or_equal);
    tcase_add_test(tc1_1, check_s21_is_greater);
    tcase_add_test(tc1_1, check_s21_is_greater_or_equal);
    tcase_add_test(tc1_1, check_div_by_ten_times);
    tcase_add_test(tc1_1, check_normalization);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_ENV);
    srunner_ntests_failed(sr);
  
    srunner_free(sr);
  
    return 0;
}