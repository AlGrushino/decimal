#ifndef S21_BIT_OPERATIONS_H
#define S21_BIT_OPERATIONS_H

#include "../something.h"

int s21_check_bit(int num, int index);
int s21_set_bit(int num, int index);
int s21_unset_bit(int num, int index);
int s21_decimal_check_bit(s21_decimal decimal, int index);
int s21_big_decimal_check_bit(s21_big_decimal decimal, int index);

s21_decimal s21_decimal_set_bit(s21_decimal decimal, int index);
s21_big_decimal s21_big_decimal_set_bit(s21_big_decimal decimal, int index);

s21_decimal s21_decimal_unset_bit(s21_decimal decimal, int index);
s21_big_decimal s21_big_decimal_unset_bit(s21_big_decimal decimal, int index);

s21_decimal s21_set_zero_15(s21_decimal decimal);
s21_decimal s21_set_zero_30(s21_decimal decimal);
int s21_get_sign(s21_decimal decimal);
int s21_get_big_sign(s21_big_decimal decimal);
s21_decimal s21_remove_zeroes(s21_decimal);

#endif
