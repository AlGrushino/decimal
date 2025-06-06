#include "s21_decimal.h"
#include <stdio.h>

int s21_get_bit(int num, int index) {
    int res = 0;
  
    num = num & (1 << index);
    if (num) {
      res = 1;
    }
  
    return res;
  }

int s21_decimal_get_bit(s21_decimal decimal, int index) {
    int byte = index / MAX_BITS;
    int bit = index % MAX_BITS;
    int res = s21_get_bit(decimal.bits[byte], bit);
  
    return res;
  }

void print_decimal(s21_decimal decimal) {
    for(int i = 127; i > 0; i--) {
        printf("%d", s21_decimal_get_bit(decimal, i));
    }
    printf("\n");
}

int main() {
    s21_decimal decimal;
    s21_decimal_set_bit(decimal, 0);
    print_decimal(decimal);
}