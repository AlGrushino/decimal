#ifndef S21_OTHER_H
#define S21_OTHER_H

#include "../something.h"

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);


//my
void s21_mult_by_ten(s21_decimal *res);
void s21_mult_by_ten_times(s21_decimal *res, int times);
void s21_normal_rounding(unsigned int mantissa[3], unsigned long long rest);
void s21_div_by_ten(s21_decimal *res);
void s21_div_by_ten_times(s21_decimal *res, int times);
void s21_set_scale(s21_decimal *res, unsigned char scale);
int s21_get_scale(s21_decimal *res);
int s21_is_divisible_by_10(s21_decimal *dec);
void s21_div_by_ten_without_rounding(s21_decimal *res);
void s21_normalization(s21_decimal *value1, s21_decimal *value2);
int s21_get_sign(s21_decimal *res);
void s21_set_sign(s21_decimal *res, int sign);
int s21_is_equal(s21_decimal value1, s21_decimal value2);
int s21_is_not_equal(s21_decimal value1, s21_decimal value2);
int s21_is_less_bits(s21_decimal value1, s21_decimal value2);
int s21_is_less(s21_decimal value1, s21_decimal value2);
int s21_is_less_or_equal(s21_decimal value1, s21_decimal value2);
int s21_is_greater(s21_decimal value1, s21_decimal value2);
int s21_is_greater_or_equal(s21_decimal value1, s21_decimal value2);




#endif