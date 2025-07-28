#ifndef S21_OTHER_H
#define S21_OTHER_H

#include "../bit_operations/bit_operations.h"
#include "../something.h"

enum S21_OTHER_RES { OK, CALC_ERR };

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

#endif