#ifndef S21_SOMETHING_H
#define S21_SOMETHING_H

// сюда включаем всякую фигню, чтобы не было круговых дефайнов(потом придумаем,
// как это всё красиво обустроить)

#define MAX_BITS 32
#define ALL_BITS 128
#define BIG_BITS 256

#include <stdio.h>

/*
в инте 4 байта, 1 байт - 8 бит, всего 8 бит x 4 байта = 32 бита
в 4 интах 32 бита x 4 = 128 бит
*/
typedef struct s21_decimal {
  unsigned int bits[4];
} s21_decimal;

typedef struct s21_big_decimal {
  int bits[8];
} s21_big_decimal;

#endif
