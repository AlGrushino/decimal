#include <check.h>

#include "s21_arithmetic.h"

void print_decimal(s21_decimal decimal) {
    for(int i = 127; i >= 0; i--) {
        printf("%d", s21_decimal_check_bit(decimal, i));
    }
    printf("\n");
}

void print_big_decimal(s21_big_decimal decimal) {
    for(int i = 255; i >= 0; i--) {
        printf("%d", s21_big_decimal_check_bit(decimal, i));
    }
    printf("\n");
}

// s21_check_bit
// нужные биты включены
START_TEST(check_bit_1) {
    // 0000 0000
    s21_big_decimal decimal = {0};
    decimal = s21_big_decimal_set_bit(decimal, 0);
    s21_big_decimal decimal2 = {0};
    decimal2 = s21_big_decimal_set_bit(decimal2, 1);
    s21_big_decimal res = {0};
    s21_add(decimal, decimal2, &res);
    print_big_decimal(res);
  
    ck_assert_int_eq(1, 1);
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
    
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_ENV);
    srunner_ntests_failed(sr);
  
    srunner_free(sr);
  
    return 0;
  }