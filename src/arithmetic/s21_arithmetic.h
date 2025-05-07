#ifndef S21_ARITHMETIC_H
#define S21_ARITHMETIC_H

#include "../bit_operations/bit_operations.h"
#include "../something.h"

typedef enum s21_arithmetic_res {
  ARITHM_OK = 0,
  GR_EQ_ETERN = 1,
  LE_EQ_ETERN = 2,
  DIV_BY_ZERO = 3

} arithmetic_res;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

#endif