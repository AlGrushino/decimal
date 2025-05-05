#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include "../something.h"

int s21_check_bit(int num, int index);
int s21_set_bit(int num, int index);
int s21_unset_bit(int num, int index);
int s21_decimal_check_bit(s21_decimal decimal, int index);
s21_decimal s21_decimal_set_bit(s21_decimal decimal, int index);
s21_decimal s21_decimal_unset_bit(s21_decimal decimal, int index);

#endif