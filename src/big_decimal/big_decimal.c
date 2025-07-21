#include "big_decimal.h"

int s21_normalize_scale_big(s21_big* a, s21_big* b) {
  int scale_a = s21_get_scale_big(a);
  int scale_b = s21_get_scale_big(b);
  int diff = scale_a - scale_b;
  int res = 1;

  if (diff) {
    if (diff > 0) {
      while (diff != 0 && s21_mul_10_big(b) == 0) {
        diff--;
        scale_a--;
      }
      while (diff != 0 && s21_div_10_big(a) == 0) {
        diff--;
        scale_b--;
      }
      if (diff != 0) {
        printf("OVERFLOW\n");
        return 1;
      }
    } else {
      while (diff != 0 && s21_mul_10_big(a) == 0) {
        diff++;
        scale_b--;
      }
      while (diff != 0 && s21_div_10_big(b) == 0) {
        diff++;
        scale_a++;
      }
      if (diff != 0) {
        printf("OVERFLOW\n");
        return 1;
      }
    }
    s21_set_scale_big(a, scale_a);
    s21_set_scale_big(b, scale_b);
  }
  if (!diff) {
    res = 0;
  }

  return res;
}

void s21_set_scale_big(s21_big* big, unsigned int scale) {
  fields field;
  field.num = big->bits[7];
  field.bits.scale = scale;
  big->bits[7] = field.num;
}

unsigned int s21_get_scale_big(s21_big* big) {
  fields field;
  field.num = big->bits[7];
  unsigned int scale = field.bits.scale;

  return scale;
}

int s21_mul_10_big(s21_big* big) {
  int error = 1;

  s21_big res = *big;
  uint64_t temp;
  uint32_t remainder = 0;

  // Умножаем каждый блок на 10 + перенос
  for (int i = 0; i < 7; i++) {
    temp = (uint64_t)res.bits[i] * 10 + remainder;
    res.bits[i] = (uint32_t)temp;
    remainder = (uint32_t)(temp >> 32);
  }

  if (!remainder) {
    error = 0;
    *big = res;
  }

  return error;
}

int s21_div_10_big(s21_big* big) {
  s21_big res = *big;
  uint64_t temp;
  uint64_t remainder = 0;

  for (int i = 6; i >= 0; i--) {
    temp = res.bits[i] + (remainder << 32);
    res.bits[i] = (uint32_t)(temp / 10);
    remainder = temp % 10;
  }

  *big = res;

  return remainder != 0 ? 1 : 0;
}

void s21_to_big(s21_big* big, s21_decimal* decimal) {
  big->bits[0] = decimal->bits[0];
  big->bits[1] = decimal->bits[1];
  big->bits[2] = decimal->bits[2];
  big->bits[7] = decimal->bits[3];
}
