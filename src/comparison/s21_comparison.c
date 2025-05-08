#include "s21_comparison.h"

/*
@brief Сравнивает два числа s21_decimal

@param one s21_decimal
@param two s21_decimal
@return int 1 - числа равны, 0 - числа не равны
*/
int s21_is_equal(s21_decimal one, s21_decimal two) {
  compare_res res = FALSE;

  // убрать последние нули, эту функцию нужно реализовать
  // s21_remove_zeroes();
  s21_decimal one_no_zeroes = s21_remove_zeroes(one);
  s21_decimal two_no_zeroes = s21_remove_zeroes(two);

  // сравнить на ноль
  if (TRUE == s21_compare_to_zero(one_no_zeroes, two_no_zeroes)) {
    res = TRUE;
  }
  // сравнить если не ноль
  // сравнить знаки
  if (FALSE == res && TRUE == s21_compare_sign(one_no_zeroes, two_no_zeroes)) {
    res = TRUE;
  }

  return (int)res;
}

/*
@brief Сравнивает два числа s21_decimal без учёта последнего инта

@param one s21_decimal
@param two s21_decimal
@return int 1 - числа равны, 0 - числа не равны
*/
int s21_compare_num(s21_decimal one, s21_decimal two) {
  compare_res res = FALSE;

  if (one.bits[0] == two.bits[0] && one.bits[1] == two.bits[1] &&
      one.bits[2] == two.bits[2]) {
    res = TRUE;
  }

  return (int)res;
}

/*
@brief Сравнивает знаки двух числе s21_decimal

@param one s21_decimal
@param two s21_decimal
@return int 1 - знаки равны, 0 - числа не равны
*/
int s21_compare_sign(s21_decimal one, s21_decimal two) {
  compare_res res = FALSE;

  if (s21_get_sign(one) == s21_get_sign(two)) {
    res = TRUE;
  }

  return (int)res;
}

/*
@brief Сравнивает, равны ли два числа нулю

@param one s21_decimal
@param two s21_decimal
@return int 1 - оба числа равны нулю, 0 - не оба числа равны нулю
*/
// переписать эту функцию на int s21_equal_to_zero(s21_decimal);
int s21_compare_to_zero(s21_decimal one, s21_decimal two) {
  compare_res res = FALSE;

  if (0 == one.bits[0] && 0 == one.bits[1] && 0 == one.bits[2] &&
      0 == two.bits[0] && 0 == two.bits[1] && 0 == two.bits[2]) {
    res = TRUE;
  }

  return (int)res;
}

/*
@brief Сравнивает два числа на неравенство друг другу

@param s21_decimal one
@param s21_decimal two
@return int 1 - числа равны друг другу, 0 - числа не равны друг другу
*/
int s21_is_not_equal(s21_decimal one, s21_decimal two) {
  return !s21_is_equal(one, two);
}

int s21_is_greater(s21_decimal one, s21_decimal two) {}

int s21_is_greater_or_equal(s21_decimal one, s21_decimal two) {
  return s21_is_greater(one, two) || s21_is_equal(one, two);
}

int s21_is_less(s21_decimal one, s21_decimal two) {}
