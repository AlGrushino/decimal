#ifndef S21_BIG_DECIMAL_H
#define S21_BIG_DECIMAL_H

#include <stdio.h>

#include "../bit_operations/bit_operations.h"
#include "../something.h"

/*
big decimal
*/
typedef struct s21_big {
  unsigned int bits[8];
} s21_big;

int s21_normalize_scale_big(s21_big* a, s21_big* b);
void s21_set_scale_big(s21_big* big, unsigned int scale);
unsigned int s21_get_scale_big(s21_big* big);
int s21_mul_10_big(s21_big* big);
int s21_div_10_big(s21_big* big);
void s21_to_big(s21_big* big, s21_decimal* decimal);
int s21_is_equal_big(s21_big* a, s21_big* b);

#endif