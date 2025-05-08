#ifndef S21_COMPARISON_H
#define S21_COMPARISON_H

#include "../bit_operations/bit_operations.h"
#include "../something.h"

int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);
int s21_compare_num(s21_decimal one, s21_decimal two);
int s21_compare_sign(s21_decimal, s21_decimal);
int s21_compare_to_zero(s21_decimal, s21_decimal);

// 0 false
// 1 true

typedef enum s21_compare_res { FALSE = 0, TRUE = 1 } compare_res;

#endif