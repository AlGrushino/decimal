#include "s21_arithmetic.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err_code = ARITHM_OK;
  // проверить, что оба числа положительные или отрицательные

  int sign_1 = s21_get_sign(value_1);
  int sign_2 = s21_get_sign(value_2);

  if (sign_1 == sign_2) {
    int add = 0;
    for(int i = 0; i < 95; i++) {
      int val1 = s21_decimal_check_bit(value_1, i);
      int val2 = s21_decimal_check_bit(value_2, i);
      if ((val1 + val2 + add) >= 2) {
        if(add)
          *result = s21_decimal_set_bit(*result, i);
        else
          *result = s21_decimal_unset_bit(*result, i);
        add = 1;
      } else {
        add = 0;
        *result = s21_decimal_set_bit(*result, val1 + val2);
      }
    }
  } else {
    // разные знаки, надо что-то придумать
  }

  // нужно проверить, что оба децимала норм
  // проверить знаки децималов

  return err_code;
}

// инвертировать вычитаемое, сложить с уменьшаемым(комменты из лекции)
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {}
