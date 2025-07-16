#ifndef S21_HELP_FUNC_H
#define S21_HELP_FUNC_H

#include "s21_decimal.h"
#include <stdio.h>

//TODO del
int sum_mantis(s21_decimal a, s21_decimal b, s21_decimal* res);
int scale_up(s21_decimal* value);
int scale_down(s21_decimal* value);

int get_sign(int settings_bits);
int set_sign(int* settings_bits, int sign);

int get_scale(int settings_bits);
int set_scale(int* settings_bits, int scale);

void set_bit(int *num, int index);
void unset_bit(int *num, int index);
int get_bit(int num, int index);

void print_bits(int num);
void print_bits_float(float num);
void print_128_bits(__uint128_t num);
void print_64_bits(__uint64_t num);
void print_decimal(s21_decimal dec);
void print_big_int(s21_decimal dec);
void print_float(s21_decimal dec);


void clear_decimal(s21_decimal *dec);
int is_decimal_zero(s21_decimal dec);

int compare_mantissas(s21_decimal dec1, s21_decimal dec2);
int normalize_scale(s21_decimal *dec1, s21_decimal *dec2);

#endif