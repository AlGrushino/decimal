#include "s21_arithmetic.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err_code = ARITHM_OK;
  // проверить, что оба числа положительные или отрицательные

  int sign_1 = s21_get_sign(value_1);
  int sign_2 = s21_get_sign(value_2);

  if ((sign_1 + sign_2) == 2 || (sign_1 + sign_2) == 0) {
  } else {
    // разные знаки, надо что-то придумать
  }

  // нужно проверить, что оба децимала норм
  // проверить знаки децималов

  return err_code;
}

// инвертировать вычитаемое, сложить с уменьшаемым(комменты из лекции)
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {}
