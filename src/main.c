#include "s21_decimal.h"


int s21_check_bit1(int num, int index) {
    unsigned int res = 1;
  
    res = num & (res << index);
    res = res >> index;
  
    return res;
}

int s21_check_bit2(int num, int index) {
    int res = 0;
  
    num = num & (1 << index);
    if (num) {
      res = 1;
    }
  
    return res;
  }

  int s21_decimal_check_bit1(s21_decimal decimal, int index) {
    int byte = index / MAX_BITS;
    int bit = index % MAX_BITS;
    int res = s21_check_bit1(decimal.bits[byte], bit);
  
    return res;
  }

  int s21_set_bit1(int num, int index) { return num | (1 << index); }

  s21_decimal s21_decimal_set_bit1(s21_decimal decimal, int index) {
    int byte = index / MAX_BITS;
    int bit = index % MAX_BITS;
    printf("byte: %d bit: %d\n", byte, bit);
    decimal.bits[byte] = s21_set_bit1(decimal.bits[byte], bit);
    return decimal;
  }


  void print_binary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
      printf("%d", (num >> i) & 1);
    }
  }

int main ()
{
    int a = 123;
    int index = 100;
    int diff = 96;

    s21_decimal num = {{0, 0, 0, 0}};
  
    // включаем остальные биты
    // for (size_t i = 16; i < 35; i++) {
    //   num = s21_decimal_set_bit1(num, diff + i);
    //   //printf("num:%d %d %d %d\n", num.bits[0], num.bits[1], num.bits[2], num.bits[3]);
    //   print_binary(num.bits[0]);
    //   print_binary(num.bits[1]);
    //   print_binary(num.bits[2]);
    //   print_binary(num.bits[3]);
    //   printf("\n");
    //   printf("index: %d\n", diff + i);


    //   int res = s21_decimal_check_bit1(num, diff + i);
    //   printf("num:%d %d %d %d my: %d\n", num.bits[0], num.bits[1], num.bits[2], num.bits[3], res);
    // }
    int res = s21_check_bit1(-65536, 31);
    printf("my: %d", res);
}