#include <check.h>

#include "bit_operations.h"

// s21_check_bit
// нужные биты включены
START_TEST(check_bit_1) {
  // 0000 0001
  int num = 1;
  int index = 0;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_2) {
  // 0000 0010
  int num = 2;
  int index = 1;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_3) {
  // 0000 0100
  int num = 4;
  int index = 2;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_4) {
  // 0000 1000
  int num = 8;
  int index = 3;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_5) {
  // 0001 0000
  int num = 16;
  int index = 4;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_6) {
  // 0010 0000
  int num = 32;
  int index = 5;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_7) {
  // 0100 0000
  int num = 64;
  int index = 6;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_8) {
  // 1000 0000
  int num = 128;
  int index = 7;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

// все биты выключены
START_TEST(check_bit_9) {
  // 0000 0000
  int num = 0;
  int index = 0;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_10) {
  // 0000 0000
  int num = 0;
  int index = 1;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_11) {
  // 0000 0000
  int num = 0;
  int index = 2;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_12) {
  // 0000 0000
  int num = 0;
  int index = 3;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_13) {
  // 0000 0000
  int num = 0;
  int index = 4;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_14) {
  // 0000 0000
  int num = 0;
  int index = 5;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_15) {
  // 0000 0000
  int num = 0;
  int index = 6;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_16) {
  // 0000 0000
  int num = 0;
  int index = 7;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

// все биты включены
START_TEST(check_bit_17) {
  // 1111 1111
  int num = 255;
  int index = 0;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_18) {
  // 1111 1111
  int num = 255;
  int index = 1;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_19) {
  // 1111 1111
  int num = 255;
  int index = 2;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_20) {
  // 1111 1111
  int num = 255;
  int index = 3;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_21) {
  // 1111 1111
  int num = 255;
  int index = 4;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_22) {
  // 1111 1111
  int num = 255;
  int index = 5;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_23) {
  // 1111 1111
  int num = 255;
  int index = 6;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(check_bit_24) {
  // 1111 1111
  int num = 255;
  int index = 7;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 1);
}
END_TEST

// нужные биты выключены
START_TEST(check_bit_25) {
  // 1111 1110
  int num = 1;
  int index = 0;
  num = ~num;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_26) {
  // 1111 1101
  int num = 2;
  int index = 1;
  num = ~num;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_27) {
  // 1111 1011
  int num = 4;
  int index = 2;
  num = ~num;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_28) {
  // 1111 0111
  int num = 8;
  int index = 3;
  num = ~num;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_29) {
  // 1110 1111
  int num = 16;
  int index = 4;
  num = ~num;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_30) {
  // 1101 1111
  int num = 32;
  int index = 5;
  num = ~num;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_31) {
  // 1011 1111
  int num = 64;
  int index = 6;
  num = ~num;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_32) {
  // 0111 1111
  int num = 128;
  int index = 7;
  num = ~num;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

// граничные значения
START_TEST(check_bit_33) {
  // 1111 1111
  int num = 255;
  int index = 8;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(check_bit_34) {
  // 1111 1111
  int num = 255;
  int index = -1;
  int res = s21_check_bit(num, index);

  ck_assert_int_eq(res, 0);
}
END_TEST

// s21_set_bit
START_TEST(set_bit_1) {
  int num = 0;
  num = s21_set_bit(num, 0);

  ck_assert_int_eq(num, 1);
}
END_TEST

START_TEST(set_bit_2) {
  int res = 2;
  for (size_t i = 1; i < 8; i++) {
    int num = 0;
    num = s21_set_bit(num, i);
    ck_assert_int_eq(res, num);
    res *= 2;
  }
}
END_TEST

// граничные значения
// тут всё оч сложно, эти тесты не нужны, но ты оставил их, чтобы не афигеть,
// когда увидишь, что граничные значения не протестированы
//  смотри, что пихаешь в функцию
START_TEST(set_bit_3) {
  int num = 0;
  num = s21_set_bit(num, 1);

  ck_assert_int_eq(num, 2);
}
END_TEST

START_TEST(set_bit_4) {
  int num = 0;
  num = s21_set_bit(num, -1);

  ck_assert_int_eq(num, -2147483648);
}
END_TEST

// s21_unset_bit
// нужный бит включён
START_TEST(unset_bit_1) {
  int num = 1;
  num = s21_unset_bit(num, 0);

  ck_assert_int_eq(num, 0);
}
END_TEST

START_TEST(unset_bit_2) {
  int num = 2;
  num = s21_unset_bit(num, 1);

  ck_assert_int_eq(num, 0);
}
END_TEST

START_TEST(unset_bit_3) {
  int num = 4;
  num = s21_unset_bit(num, 2);

  ck_assert_int_eq(num, 0);
}
END_TEST

START_TEST(unset_bit_4) {
  int num = 8;
  num = s21_unset_bit(num, 3);

  ck_assert_int_eq(num, 0);
}
END_TEST

START_TEST(unset_bit_5) {
  int num = 16;
  num = s21_unset_bit(num, 4);

  ck_assert_int_eq(num, 0);
}
END_TEST

START_TEST(unset_bit_6) {
  int num = 32;
  num = s21_unset_bit(num, 5);

  ck_assert_int_eq(num, 0);
}
END_TEST

START_TEST(unset_bit_7) {
  int num = 64;
  num = s21_unset_bit(num, 6);

  ck_assert_int_eq(num, 0);
}
END_TEST

START_TEST(unset_bit_8) {
  int num = 128;
  num = s21_unset_bit(num, 7);

  ck_assert_int_eq(num, 0);
}
END_TEST

// бит выключен
START_TEST(unset_bit_9) {
  for (size_t i = 0; i < 8; i++) {
    int num = 0;
    num = s21_unset_bit(num, i);
    ck_assert_int_eq(num, 0);
  }
}
END_TEST

// s21_decimal_set_bit
// бит выключен
// первый байт
START_TEST(s21_decimal_set_bit_1) {
  s21_decimal num = {{0, 0, 0, 0}};
  num = s21_decimal_set_bit(num, 0);

  ck_assert_int_eq(num.bits[0], 1);
}
END_TEST

START_TEST(s21_decimal_set_bit_2) {
  int res = 2;
  int bit = 1;

  for (size_t i = 1; i < 8; i++) {
    s21_decimal num = {{0, 0, 0, 0}};
    num = s21_decimal_set_bit(num, bit);
    ck_assert_int_eq(num.bits[0], res);

    bit++;
    res *= 2;
  }
}
END_TEST

// второй байт
START_TEST(s21_decimal_set_bit_3) {
  s21_decimal num = {{0, 0, 0, 0}};
  int diff = 32;
  num = s21_decimal_set_bit(num, diff + 0);

  ck_assert_int_eq(num.bits[1], 1);
}
END_TEST

START_TEST(s21_decimal_set_bit_4) {
  int res = 2;
  int bit = 1;
  int diff = 32;

  for (size_t i = 1; i < 8; i++) {
    s21_decimal num = {{0, 0, 0, 0}};
    num = s21_decimal_set_bit(num, diff + bit);
    ck_assert_int_eq(num.bits[1], res);

    bit++;
    res *= 2;
  }
}
END_TEST

// третий байт
START_TEST(s21_decimal_set_bit_5) {
  s21_decimal num = {{0, 0, 0, 0}};
  int diff = 64;
  num = s21_decimal_set_bit(num, diff + 0);

  ck_assert_int_eq(num.bits[2], 1);
}
END_TEST

START_TEST(s21_decimal_set_bit_6) {
  int res = 2;
  int bit = 1;
  int diff = 64;

  for (size_t i = 1; i < 8; i++) {
    s21_decimal num = {{0, 0, 0, 0}};
    num = s21_decimal_set_bit(num, diff + bit);
    ck_assert_int_eq(num.bits[2], res);

    bit++;
    res *= 2;
  }
}
END_TEST

// s21_decimal_unset_bit
// бит включён

// первый байт
START_TEST(s21_decimal_unset_bit_1) {
  s21_decimal num = {{1, 0, 0, 0}};
  num = s21_decimal_unset_bit(num, 0);

  ck_assert_int_eq(num.bits[0], 0);
}
END_TEST

START_TEST(s21_decimal_unset_bit_2) {
  int res = 128;
  int bit = 7;

  for (size_t i = 7; i > 1; i--) {
    s21_decimal num = {{0, 0, 0, 0}};
    num = s21_decimal_set_bit(num, bit);
    ck_assert_int_eq(num.bits[0], res);

    num = s21_decimal_unset_bit(num, bit);
    ck_assert_int_eq(num.bits[0], 0);

    bit--;
    res /= 2;
  }
}
END_TEST

// второй байт
START_TEST(s21_decimal_unset_bit_3) {
  s21_decimal num = {{0, 1, 0, 0}};
  int diff = 32;
  num = s21_decimal_unset_bit(num, diff + 0);

  ck_assert_int_eq(num.bits[1], 0);
}
END_TEST

START_TEST(s21_decimal_unset_bit_4) {
  int res = 128;
  int bit = 7;
  int diff = 32;

  for (size_t i = 7; i > 1; i--) {
    s21_decimal num = {{0, 0, 0, 0}};
    num = s21_decimal_set_bit(num, diff + bit);
    ck_assert_int_eq(num.bits[1], res);

    num = s21_decimal_unset_bit(num, diff + bit);
    ck_assert_int_eq(num.bits[1], 0);

    bit--;
    res /= 2;
  }
}
END_TEST

// третий байт
START_TEST(s21_decimal_unset_bit_5) {
  s21_decimal num = {{0, 0, 1, 0}};
  int diff = 64;
  num = s21_decimal_unset_bit(num, diff + 0);

  ck_assert_int_eq(num.bits[2], 0);
}
END_TEST

START_TEST(s21_decimal_unset_bit_6) {
  int res = 128;
  int bit = 7;
  int diff = 64;

  for (size_t i = 7; i > 1; i--) {
    s21_decimal num = {{0, 0, 0, 0}};
    num = s21_decimal_set_bit(num, diff + bit);
    ck_assert_int_eq(num.bits[2], res);

    num = s21_decimal_unset_bit(num, diff + bit);
    ck_assert_int_eq(num.bits[2], 0);

    bit--;
    res /= 2;
  }
}
END_TEST

// s21_decimal_check_bit
// все биты выключены
// первый байт
START_TEST(s21_decimal_check_bit_1) {
  s21_decimal num = {{0, 0, 0, 0}};
  int res = s21_decimal_check_bit(num, 0);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_decimal_check_bit_2) {
  for (size_t i = 1; i < 8; i++) {
    s21_decimal num = {{0, 0, 0, 0}};
    int res = s21_decimal_check_bit(num, i);
    ck_assert_int_eq(res, 0);
  }
}
END_TEST

// второй байт
START_TEST(s21_decimal_check_bit_3) {
  s21_decimal num = {{0, 0, 0, 0}};
  int diff = 32;
  int res = s21_decimal_check_bit(num, diff + 0);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_decimal_check_bit_4) {
  int diff = 32;

  for (size_t i = 1; i < 8; i++) {
    s21_decimal num = {{0, 0, 0, 0}};
    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 0);
  }
}
END_TEST

// третий байт
START_TEST(s21_decimal_check_bit_5) {
  s21_decimal num = {{0, 0, 0, 0}};
  int diff = 64;
  int res = s21_decimal_check_bit(num, diff + 0);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_decimal_check_bit_6) {
  int diff = 64;

  for (size_t i = 1; i < 8; i++) {
    s21_decimal num = {{0, 0, 0, 0}};
    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 0);
  }
}
END_TEST

// бит включён
// первый байт
START_TEST(s21_decimal_check_bit_7) {
  s21_decimal num = {{1, 0, 0, 0}};
  int res = s21_decimal_check_bit(num, 0);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_decimal_check_bit_8) {
  int bit = 2;

  for (size_t i = 1; i < 8; i++) {
    s21_decimal num = {{0, 0, 0, 0}};
    num = s21_decimal_set_bit(num, i);
    ck_assert_int_eq(num.bits[0], bit);

    int res = s21_decimal_check_bit(num, i);
    ck_assert_int_eq(res, 1);

    bit *= 2;
  }
}
END_TEST

// второй байт
START_TEST(s21_decimal_check_bit_9) {
  s21_decimal num = {{0, 1, 0, 0}};
  int diff = 32;
  int res = s21_decimal_check_bit(num, diff + 0);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_decimal_check_bit_10) {
  int bit = 2;
  int diff = 32;

  for (size_t i = 1; i < 8; i++) {
    s21_decimal num = {{0, 0, 0, 0}};
    num = s21_decimal_set_bit(num, diff + i);
    ck_assert_int_eq(num.bits[1], bit);

    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 1);

    bit *= 2;
  }
}
END_TEST

// третий байт
START_TEST(s21_decimal_check_bit_11) {
  s21_decimal num = {{0, 0, 1, 0}};
  int diff = 64;
  int res = s21_decimal_check_bit(num, diff + 0);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_decimal_check_bit_12) {
  int bit = 2;
  int diff = 64;

  for (size_t i = 1; i < 8; i++) {
    s21_decimal num = {{0, 0, 0, 0}};
    num = s21_decimal_set_bit(num, diff + i);
    ck_assert_int_eq(num.bits[2], bit);

    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 1);

    bit *= 2;
  }
}
END_TEST

// s21_set_zero_15
// биты выключены
START_TEST(s21_set_zero_15_1) {
  int diff = 96;
  s21_decimal num = {{0, 0, 0, 0}};

  // включаем остальные биты
  for (size_t i = 16; i < 32; i++) {
    num = s21_decimal_set_bit(num, diff + i);
    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 1);
  }

  // проверяем, что нужные биты выключены
  for (size_t i = 0; i < 16; i++) {
    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 0);
  }

  // выключаем биты и проверяем, выключены ли они
  num = s21_set_zero_15(num);
  for (size_t i = 0; i < 16; i++) {
    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 0);
  }

  // проверяем, что остальные биты остались включены
  for (size_t i = 16; i < 32; i++) {
    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 1);
  }
}
END_TEST

// биты включены
START_TEST(s21_set_zero_15_2) {
  int diff = 96;
  s21_decimal num = {{0, 0, 0, 0}};

  // включаем все биты, кроме последнего, потому что последний бит это знак
  int counter = 0;
  for (size_t i = 0; i < 31; i++) {
    counter++;
    num = s21_decimal_set_bit(num, diff + i);
    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 1);
  }

  // выключаем биты и проверяем, выключены ли они
  num = s21_set_zero_15(num);
  for (size_t i = 0; i < 16; i++) {
    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 0);
  }

  // // // проверяем, что остальные биты остались включены
  for (size_t i = 16; i < 31; i++) {
    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 1);
  }
}
END_TEST

// s21_set_zero_30
// биты включены
START_TEST(s21_set_zero_30_1) {
  int diff = 96;
  s21_decimal num = {{0, 0, 0, 0}};

  // включаем все биты, кроме последнего, потому что последний бит это знак
  int counter = 0;
  for (size_t i = 0; i < 31; i++) {
    counter++;
    num = s21_decimal_set_bit(num, diff + i);
    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 1);
  }

  // выключаем биты и проверяем, выключены ли они
  num = s21_set_zero_30(num);
  for (size_t i = 24; i < 31; i++) {
    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 0);
  }

  //  проверяем, что остальные биты остались включены
  for (size_t i = 0; i < 24; i++) {
    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 1);
  }
}
END_TEST

// биты выключены
START_TEST(s21_set_zero_30_2) {
  int diff = 96;
  s21_decimal num = {{0, 0, 0, 0}};

  // включаем остальные биты
  for (size_t i = 24; i < 31; i++) {
    num = s21_decimal_set_bit(num, diff + i);
    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 1);
  }

  // проверяем, что нужные биты выключены
  for (size_t i = 0; i < 24; i++) {
    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 0);
  }

  // выключаем биты и проверяем, выключены ли они
  num = s21_set_zero_30(num);
  for (size_t i = 24; i < 31; i++) {
    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 0);
  }

  // проверяем, что остальные биты остались выключены
  for (size_t i = 0; i < 24; i++) {
    int res = s21_decimal_check_bit(num, diff + i);
    ck_assert_int_eq(res, 0);
  }
}
END_TEST

START_TEST(s21_get_sign_1) {
  s21_decimal num = {{0, 0, 0, 2147483648}};
  int res = s21_get_sign(num);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_get_sign_2) {
  s21_decimal num = {{0, 0, 0, 0}};
  int res = s21_get_sign(num);

  ck_assert_int_eq(res, 0);
}
END_TEST

// включаем самый первый бит
// 1
// 0000 0000 0000 0000 1000 0000 0000 0000
// 96 + 16 + 1
START_TEST(s21_get_scale_1) {
  s21_decimal num = {{0, 0, 0, 0}};
  num = s21_decimal_set_bit(num, 112);
  unsigned int res = s21_get_scale(num);

  ck_assert_int_eq((int)res, 1);
}
END_TEST

// 0
START_TEST(s21_get_scale_2) {
  s21_decimal num = {{0, 0, 0, 0}};
  unsigned int res = s21_get_scale(num);

  ck_assert_int_eq((int)res, 0);
}
END_TEST

// 0000 0000 0000 0000 | 0011 1000 0000 0000
// 28
START_TEST(s21_get_scale_3) {
  s21_decimal num = {{0, 0, 0, 0}};
  num = s21_decimal_set_bit(num, 114);
  num = s21_decimal_set_bit(num, 115);
  num = s21_decimal_set_bit(num, 116);

  unsigned int res = s21_get_scale(num);

  ck_assert_int_eq((int)res, 28);
}
END_TEST

// 2
START_TEST(s21_get_scale_4) {
  s21_decimal num = {{0, 0, 0, 0}};
  num = s21_decimal_set_bit(num, 113);
  unsigned int res = s21_get_scale(num);

  ck_assert_int_eq((int)res, 2);
}
END_TEST

// 3
START_TEST(s21_get_scale_5) {
  s21_decimal num = {{0, 0, 0, 0}};
  num = s21_decimal_set_bit(num, 113);
  num = s21_decimal_set_bit(num, 112);

  unsigned int res = s21_get_scale(num);

  ck_assert_int_eq((int)res, 3);
}
END_TEST

// 4
START_TEST(s21_get_scale_6) {
  s21_decimal num = {{0, 0, 0, 0}};
  num = s21_decimal_set_bit(num, 114);
  unsigned int res = s21_get_scale(num);

  ck_assert_int_eq((int)res, 4);
}
END_TEST

// 5
START_TEST(s21_get_scale_7) {
  s21_decimal num = {{0, 0, 0, 0}};
  num = s21_decimal_set_bit(num, 114);
  num = s21_decimal_set_bit(num, 112);

  unsigned int res = s21_get_scale(num);

  ck_assert_int_eq((int)res, 5);
}
END_TEST

// 6
START_TEST(s21_get_scale_8) {
  s21_decimal num = {{0, 0, 0, 0}};
  num = s21_decimal_set_bit(num, 114);
  num = s21_decimal_set_bit(num, 113);

  unsigned int res = s21_get_scale(num);

  ck_assert_int_eq((int)res, 6);
}
END_TEST

// 7
START_TEST(s21_get_scale_9) {
  s21_decimal num = {{0, 0, 0, 0}};
  num = s21_decimal_set_bit(num, 114);
  num = s21_decimal_set_bit(num, 113);
  num = s21_decimal_set_bit(num, 112);

  unsigned int res = s21_get_scale(num);

  ck_assert_int_eq((int)res, 7);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, tc1_1);

  //   s21_check_bit
  // нужные биты включены
  tcase_add_test(tc1_1, check_bit_1);
  tcase_add_test(tc1_1, check_bit_2);
  tcase_add_test(tc1_1, check_bit_3);
  tcase_add_test(tc1_1, check_bit_4);
  tcase_add_test(tc1_1, check_bit_5);
  tcase_add_test(tc1_1, check_bit_6);
  tcase_add_test(tc1_1, check_bit_7);
  tcase_add_test(tc1_1, check_bit_8);
  // все биты выключены
  tcase_add_test(tc1_1, check_bit_9);
  tcase_add_test(tc1_1, check_bit_10);
  tcase_add_test(tc1_1, check_bit_11);
  tcase_add_test(tc1_1, check_bit_12);
  tcase_add_test(tc1_1, check_bit_13);
  tcase_add_test(tc1_1, check_bit_14);
  tcase_add_test(tc1_1, check_bit_15);
  tcase_add_test(tc1_1, check_bit_16);
  // все биты выключены
  tcase_add_test(tc1_1, check_bit_17);
  tcase_add_test(tc1_1, check_bit_18);
  tcase_add_test(tc1_1, check_bit_19);
  tcase_add_test(tc1_1, check_bit_20);
  tcase_add_test(tc1_1, check_bit_21);
  tcase_add_test(tc1_1, check_bit_22);
  tcase_add_test(tc1_1, check_bit_23);
  tcase_add_test(tc1_1, check_bit_24);
  // нужные биты выключены
  tcase_add_test(tc1_1, check_bit_25);
  tcase_add_test(tc1_1, check_bit_26);
  tcase_add_test(tc1_1, check_bit_27);
  tcase_add_test(tc1_1, check_bit_28);
  tcase_add_test(tc1_1, check_bit_29);
  tcase_add_test(tc1_1, check_bit_30);
  tcase_add_test(tc1_1, check_bit_31);
  tcase_add_test(tc1_1, check_bit_32);
  // граничные значения
  tcase_add_test(tc1_1, check_bit_33);
  tcase_add_test(tc1_1, check_bit_34);

  // s21_set_bit
  tcase_add_test(tc1_1, set_bit_1);
  tcase_add_test(tc1_1, set_bit_2);
  // граничные значения
  tcase_add_test(tc1_1, set_bit_3);
  tcase_add_test(tc1_1, set_bit_4);

  // s21_unset_bit
  tcase_add_test(tc1_1, unset_bit_1);
  tcase_add_test(tc1_1, unset_bit_2);
  tcase_add_test(tc1_1, unset_bit_3);
  tcase_add_test(tc1_1, unset_bit_4);
  tcase_add_test(tc1_1, unset_bit_5);
  tcase_add_test(tc1_1, unset_bit_6);
  tcase_add_test(tc1_1, unset_bit_7);
  tcase_add_test(tc1_1, unset_bit_8);
  // нужный бит выключен
  tcase_add_test(tc1_1, unset_bit_9);

  // s21_decimal_set_bit
  // бит выключен
  tcase_add_test(tc1_1, s21_decimal_set_bit_1);
  tcase_add_test(tc1_1, s21_decimal_set_bit_2);
  tcase_add_test(tc1_1, s21_decimal_set_bit_3);
  tcase_add_test(tc1_1, s21_decimal_set_bit_4);
  tcase_add_test(tc1_1, s21_decimal_set_bit_5);
  tcase_add_test(tc1_1, s21_decimal_set_bit_6);

  // s21_decimal_unset_bit
  // бит включён
  tcase_add_test(tc1_1, s21_decimal_unset_bit_1);
  tcase_add_test(tc1_1, s21_decimal_unset_bit_2);
  tcase_add_test(tc1_1, s21_decimal_unset_bit_3);
  tcase_add_test(tc1_1, s21_decimal_unset_bit_4);
  tcase_add_test(tc1_1, s21_decimal_unset_bit_5);
  tcase_add_test(tc1_1, s21_decimal_unset_bit_6);

  // s21_decimal_check_bit
  // бит выключен
  tcase_add_test(tc1_1, s21_decimal_check_bit_1);
  tcase_add_test(tc1_1, s21_decimal_check_bit_2);
  tcase_add_test(tc1_1, s21_decimal_check_bit_3);
  tcase_add_test(tc1_1, s21_decimal_check_bit_4);
  tcase_add_test(tc1_1, s21_decimal_check_bit_5);
  tcase_add_test(tc1_1, s21_decimal_check_bit_6);

  // бит включён
  tcase_add_test(tc1_1, s21_decimal_check_bit_7);
  tcase_add_test(tc1_1, s21_decimal_check_bit_8);
  tcase_add_test(tc1_1, s21_decimal_check_bit_9);
  tcase_add_test(tc1_1, s21_decimal_check_bit_10);
  tcase_add_test(tc1_1, s21_decimal_check_bit_11);
  tcase_add_test(tc1_1, s21_decimal_check_bit_12);

  // s21_set_zero_15
  // биты выключены
  tcase_add_test(tc1_1, s21_set_zero_15_1);
  // биты включены
  tcase_add_test(tc1_1, s21_set_zero_15_2);

  // s21_set_zero_30
  // биты включены
  tcase_add_test(tc1_1, s21_set_zero_30_1);
  // биты выключены
  tcase_add_test(tc1_1, s21_set_zero_30_2);

  // s21_get_sign
  tcase_add_test(tc1_1, s21_get_sign_1);
  tcase_add_test(tc1_1, s21_get_sign_2);

  // s21_get_scale
  tcase_add_test(tc1_1, s21_get_scale_1);
  tcase_add_test(tc1_1, s21_get_scale_2);
  tcase_add_test(tc1_1, s21_get_scale_3);
  tcase_add_test(tc1_1, s21_get_scale_4);
  tcase_add_test(tc1_1, s21_get_scale_5);
  tcase_add_test(tc1_1, s21_get_scale_6);
  tcase_add_test(tc1_1, s21_get_scale_7);
  tcase_add_test(tc1_1, s21_get_scale_8);
  tcase_add_test(tc1_1, s21_get_scale_9);
  // здесь тесты доходят до 7 скейла, но границы протестированы, поэтому не вижу
  // большого смысла тестировать отсальное

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  srunner_ntests_failed(sr);

  srunner_free(sr);

  return 0;
}