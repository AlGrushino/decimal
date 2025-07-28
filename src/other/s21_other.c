#include "s21_other.h"

/**
 * @brief Возвращает результат умножения указанного Decimal на -1.
 */
int s21_negate(s21_decimal value, s21_decimal *result) {
  if (!result) {
    return CALC_ERR;
  }

  // если будет повторяться, вынести в bit_opeartions/s21_copy_decimal
  result->bits[0] = value.bits[0];
  result->bits[1] = value.bits[1];
  result->bits[2] = value.bits[2];
  result->bits[3] = value.bits[3];

  if (s21_get_sign(result)) {
    s21_decimal_unset_sign(result);
  } else {
    s21_decimal_set_sign(result);
  }
  return OK;
}
