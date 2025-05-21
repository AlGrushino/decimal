#include "s21_decimal.h"

void print_binary(unsigned int num) {
  for (int i = 31; i >= 0; i--) {
    printf("%d", (num >> i) & 1);
  }
  printf(" ");
}

void mult_by_ten(s21_decimal *res) { // <<1 умножение на два: (<<1 + <<3) == умножение на 10
  unsigned int temp_mantissa[3] = {res->bits[0], res->bits[1], res->bits[2]}; //92 бита
  unsigned long long temp = 0; //64 бита (больше 32 на случай, если будет overflow)
  unsigned long long overflow = 0;
  for (int i = 0; i<3; i++) {
      temp = ((unsigned long long)res->bits[i] << 1) + overflow;
      temp_mantissa[i] = (unsigned int)(temp & 0xFFFFFFFF); //0xFFFFFFFF = 32 бита
      overflow = temp >> 32;
  }
  unsigned int doubled_mantissa[3] = {temp_mantissa[0], temp_mantissa[1], temp_mantissa[2]};
  overflow = 0; // нужно ли занулять temp_mantissa?
  for (int i = 0; i<3; i++) {
      temp = ((unsigned long long)res->bits[i] << 3) + overflow;
      temp_mantissa[i] = (unsigned int)(temp & 0xFFFFFFFF);
      overflow = temp >> 32;
  }
  unsigned int eight_mantissa[3] = {temp_mantissa[0], temp_mantissa[1], temp_mantissa[2]};
  overflow = 0; 
  for (int i = 0; i < 3; i++) {
      temp = (unsigned long long)doubled_mantissa[i] + eight_mantissa[i] + overflow;
      res->bits[i] = (unsigned int)(temp & 0xFFFFFFFF);
      overflow = temp >> 32;
  }
}

void mult_by_ten_times(s21_decimal *res, int times) {
  for (int i = 0; i<times; i++) {
      mult_by_ten(res);
  }
}

void normal_rounding(unsigned int mantissa[3]) {
  unsigned long long temp = 0;
  unsigned long long rest = 0;
  unsigned int temp_mantissa[3] = {mantissa[0], mantissa[1], mantissa[2]};

  for (int i = 2; i >= 0; i--) {
      temp = (rest << 32) | temp_mantissa[i];
      temp_mantissa[i] = (unsigned int)(temp / 10);
      rest = temp % 10;
  }
  if (rest >= 5) {
      int carry = 1;
      for (int i = 0; i < 3 && carry; i++) {
          unsigned long long sum = (unsigned long long)mantissa[i] + carry;
          mantissa[i] = (unsigned int)sum;
          carry = (sum >> 32) & 1;
      }
  }
}

void div_by_ten(s21_decimal *res) { 
  unsigned int temp_mantissa[3] = {res->bits[0], res->bits[1], res->bits[2]}; //92 бита
  unsigned long long temp = 0; //64 бита (больше 32 на случай, если будет overflow) 
  unsigned long long rest = 0;
  for (int i = 2; i>=0; i--) {
      temp = (rest << 32) | temp_mantissa[i];
      temp_mantissa[i] = (unsigned int)(temp / 10);
      rest = temp % 10;
  }
  normal_rounding(temp_mantissa);
  for (int i = 0; i<3;i++) {
      res->bits[i] = temp_mantissa[i];
  }
}

void div_by_ten_times(s21_decimal *res, int times) {
  for (int i = 0; i<times; i++) {
      div_by_ten(res);
  }
}

void set_scale(s21_decimal *res, unsigned char scale) { //unsigned пч нет отриц, char потому что он как раз 8 бит 
  res->bits[3] &= ~(0xFF << 16);
  res->bits[3] |= ((int)scale << 16); // приводим к int так как работаем со структурой интов 
}

int get_scale(s21_decimal *res) {
  return (res->bits[3] >> 16) & 0xFF;
}

void get_mantissa(const s21_decimal *dec, unsigned int mantissa[3]) {
  mantissa[0] = dec->bits[0];
  mantissa[1] = dec->bits[1];
  mantissa[2] = dec->bits[2];
}

int is_divisible_by_10(s21_decimal *dec) {
  unsigned int temp_mantissa[3] = {dec->bits[0], dec->bits[1], dec->bits[2]};
  unsigned long long temp = 0;
  unsigned long long rest = 0;

  for (int i = 2; i >= 0; i--) {
      temp = (rest << 32) | temp_mantissa[i];
      temp_mantissa[i] = (unsigned int)(temp / 10);
      rest = temp % 10;
  }
  printf("rest: %lld\n", rest);
  int new_scale = get_scale(dec);
  printf("new_scale_from_round:%d\n", new_scale);
  return rest == 0;
}


void normalization(s21_decimal *value1, s21_decimal *value2) { // do: round?
  int value1_scale = get_scale(value1);
  int value2_scale = get_scale(value2);
  if (value1_scale <= 28 && value2_scale <= 28) {
      if (value1_scale > value2_scale) {
          int diff = value1_scale - value2_scale;
          set_scale(value2, value1_scale);
          mult_by_ten_times(value2, diff);
      }
      else {
          int diff = value2_scale - value1_scale;
          set_scale(value1, value2_scale);
          mult_by_ten_times(value1, diff);
      }
  } else if (value1_scale > 28 || value2_scale > 28) {
      int diff_val1 = 28 - value1_scale;
      int diff_val2 = 28 - value2_scale;
      if (diff_val1 > 0) {
          mult_by_ten_times(value1, diff_val1);
      }
      else if (diff_val1 < 0) {
          div_by_ten_times(value1, -diff_val1);
      }
      set_scale(value1, 28);
      if (diff_val2 > 0) {
          mult_by_ten_times(value2, diff_val2);
      }
      else if (diff_val2 < 0) {
          div_by_ten_times(value2, -diff_val2);
      }
      set_scale(value2, 28);
  }
  int new_scale = get_scale(value1);
  printf("\nPISKA\n");
  printf("new_scale:%d\n", new_scale);
  while (new_scale > 0 && is_divisible_by_10(value1) && is_divisible_by_10(value2)) { //сокрщаем 
      div_by_ten(value1);
      div_by_ten(value2);
      new_scale--;
      set_scale(value1, new_scale);
      set_scale(value2, new_scale);
  }

}


int main ()
{
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal num2 = {{15, 0, 0, 0}};
  set_scale(&num1, 28);
  set_scale(&num2, 28);

  //div_by_ten(&num);
  normalization(&num1, &num2);
  print_binary(num1.bits[3]);
  print_binary(num1.bits[2]);
  print_binary(num1.bits[1]);
  print_binary(num1.bits[0]);
  printf("\n");
  print_binary(num2.bits[3]);
  print_binary(num2.bits[2]);
  print_binary(num2.bits[1]);
  print_binary(num2.bits[0]);
  printf("\n");

}