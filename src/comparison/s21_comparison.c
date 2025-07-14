#include "s21_comparison.h"

/*
@brief Сравнивает два числа s21_decimal

@param one s21_decimal
@param two s21_decimal
@return int 1 - числа равны, 0 - числа неравны
*/
int s21_is_equal(s21_decimal one, s21_decimal two) {
  bool res = false;

  // убрать последние нули, эту функцию нужно реализовать
  // s21_remove_zeroes();
  // s21_decimal one_no_zeroes = s21_remove_zeroes(one);
  // s21_decimal two_no_zeroes = s21_remove_zeroes(two);

  // // сравнить на ноль
  // if (TRUE == s21_compare_to_zero(one_no_zeroes) &&
  //     TRUE == s21_compare_to_zero(two_no_zeroes)) {
  //   res = TRUE;
  // }
  // сравнить если не ноль
  // сравнить знаки
  // if (FALSE == res && TRUE == s21_compare_sign(one_no_zeroes, two_no_zeroes))
  // {
  if (false == res && true == s21_compare_sign(one, two)) {
    res = true;
  }

  return (int)res;
}

/*
@brief Сравнивает два числа на неравенство друг другу

@param s21_decimal one
@param s21_decimal two
@return int 1 - числа равны друг другу, 0 - числа не равны друг другу
*/
// int s21_is_not_equal(s21_decimal one, s21_decimal two) {
//   return !s21_is_equal(one, two);
// }

// int s21_is_greater(s21_decimal one, s21_decimal two) {}

// int s21_is_greater_or_equal(s21_decimal one, s21_decimal two) {
//   return s21_is_greater(one, two) || s21_is_equal(one, two);
// }

// int s21_is_less(s21_decimal one, s21_decimal two) {
//   return !s21_is_greater(one, two);
// }
