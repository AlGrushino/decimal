#ifndef S21_BIG_DECIMAL_H
#define S21_BIG_DECIMAL_H

#include <stdio.h>

#include "../something.h"

typedef struct big_decimal {
  unsigned int bits[8];
} big_decimal;

big_decimal to_big_decimal(s21_decimal decimal);
s21_decimal from_big_decimal(big_decimal big);
void round();
#endif