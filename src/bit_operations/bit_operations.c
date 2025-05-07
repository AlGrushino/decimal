#include "bit_operations.h"
/*
@breif проверяет, включён ли бит в num по index
Сдвиг работает таким образом, что зануляются все биты слева и справа от индекса

@param num int
@param index int индекс бита
@return результат проверки 1 - включён, 0 - выключен
Если пихать индекс вне диапазона, возвращает 0
*/
int s21_check_bit(int num, int index) {
  int res = 0;

  num = num & (1 << index);
  if (num) {
    res = 1;
  }

  return res;
}

/*
@brief включает бит в num по index

@param num int
@param index int индекс бита
@return число с включённым битом
*/
int s21_set_bit(int num, int index) { return num | (1 << index); }

/*
@brief выключает бит в num по index
~ инвертирует биты
bits = 0000 0001
~bits
bits = 1111 1110

@param num int
@param index int индекс бита
@return число с выключенным битом
*/
int s21_unset_bit(int num, int index) { return num & (~(1 << index)); }

/*
@brief Проверяет, включён ли бит по index в decimal

@param decimal число s21_decimal, которое проверяем
@param index идндекс бита, который провеярем
@return результат проверки, 1 - включён, 0 - выключен
*/
int s21_decimal_check_bit(s21_decimal decimal, int index) {
  int byte = index / MAX_BITS;
  int bit = index % MAX_BITS;
  int res = s21_check_bit(decimal.bits[byte], bit);

  return res;
}

/*
@brief Включает бит s21_decimal

@param decimal число s21_decimal, в котором включаем бит
@param index int - индекс бита, который включаем
@return s21_decimal число decimal с включённым битом
*/
s21_decimal s21_decimal_set_bit(s21_decimal decimal, int index) {
  int byte = index / MAX_BITS;
  int bit = index % MAX_BITS;

  decimal.bits[byte] = s21_set_bit(decimal.bits[byte], bit);
  return decimal;
}
// Надо подумать, что возвращать из сет/ансет

/*
@brief Выключает бит s21_decimal

@param decimal число s21_decimal, в котором выключаем бит
@param index int индекс бита, который выключаем
@return s21_decimal число decimal с выключенным битом
*/
s21_decimal s21_decimal_unset_bit(s21_decimal decimal, int index) {
  int byte = index / MAX_BITS;
  int bit = index % MAX_BITS;

  decimal.bits[byte] = s21_unset_bit(decimal.bits[byte], bit);
  return decimal;
}

/*
@brief Выключает нерабочие биты(0 - 15) в последнем байте decimal

@param decimal
@return s21_decimal
*/
s21_decimal s21_set_zero_15(s21_decimal decimal) {
  for (size_t i = 0; i < 16; i++) {
    decimal.bits[3] = s21_unset_bit(decimal.bits[3], (int)i);
  }

  return decimal;
}

// эти две функции стоит объединить в одну, и вообще большой вопрос, пригодятся
// ли они

/*
@brief Выключает нерабочие биты(24 - 30) в последнем байте decimal

@param decimal
@return s21_decimal
*/
s21_decimal s21_set_zero_30(s21_decimal decimal) {
  for (size_t i = 24; i < 31; i++) {
    decimal.bits[3] = s21_unset_bit(decimal.bits[3], (int)i);
  }

  return decimal;
}

/*
@breif

@return res 1 - отрицательный, 0 - положительный
*/
int s21_get_sign(s21_decimal decimal){
  // мб стотит проверить, что не ноль
  int res = s21_check_bit(decimal.bits[3], 31);
  return res;
}