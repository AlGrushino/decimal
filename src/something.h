#ifndef S21_SOMETHING_H
#define S21_SOMETHING_H

// сюда включаем всякую фигню, чтобы не было круговых дефайнов(потом придумаем,
// как это всё красиво обустроить)
// если используется только в одном файле, то убрать в его хедер
#define MAX_BITS 32
#define ALL_BITS 128
#define BIG_BITS 256

#include <inttypes.h>
#include <stdio.h>

/*
в инте 4 байта, 1 байт - 8 бит, всего 8 бит x 4 байта = 32 бита
в 4 интах 32 бита x 4 = 128 бит
*/
typedef struct s21_decimal {
  unsigned int bits[4];
} s21_decimal;

/*
тип юнион с битовыми полями для получения степени
поскольку это юнион, все его значения хранятся с одного адреса, поэтому
обращаться к ним очень удобно
*/
typedef union s21_fields {
  int num;
  struct {
    unsigned int useless : 16;
    unsigned int scale : 8;
    unsigned int useless_again : 7;
    unsigned int sign : 1;
  } bits;
} fields;

#endif
