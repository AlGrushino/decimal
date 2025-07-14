#include "bit_operations.h"
/*
@breif проверяет, включён ли бит в num по index
Сдвиг работает таким образом, что зануляются все биты слева и справа от индекса

@param num int
@param index int индекс бита
@return bool true - включён, false - выключен
Если пихать индекс вне диапазона, возвращает 0
*/
bool s21_check_bit(int num, int index) {
  bool res = false;

  num = num & (1 << index);
  if (num) {
    res = true;
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
@return bool, true - включён, false - выключен
*/
bool s21_decimal_check_bit(s21_decimal decimal, int index) {
  int byte = index / MAX_BITS;
  int bit = index % MAX_BITS;
  bool res = s21_check_bit(decimal.bits[byte], bit);

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

@param decimal s21_decimal
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

@param decimal s21_decimal
@return s21_decimal
*/
s21_decimal s21_set_zero_30(s21_decimal decimal) {
  for (size_t i = 24; i < 31; i++) {
    decimal.bits[3] = s21_unset_bit(decimal.bits[3], (int)i);
  }

  return decimal;
}

/*
@brief Сравнивает два числа s21_decimal без учёта последнего инта

@param one s21_decimal
@param two s21_decimal
@return bool true - числа равны, false - числа не равны
*/
bool s21_compare_nums(s21_decimal * a, s21_decimal * b) {
  bool res = false;

  if (a->bits[0] == b->bits[0] && a->bits[1] == b->bits[1] && a->bits[2] == b->bits[2])
  {
    res = true;
  }

  return res;
}

/*
@brief Сравнивает знаки двух числе s21_decimal

@param one s21_decimal
@param two s21_decimal
@return bool true - знаки равны, flase - знаки не равны
*/
bool s21_compare_sign(s21_decimal* a, s21_decimal* b) {
  bool res = false;

  if (s21_get_sign(a) == s21_get_sign(b)) {
    res = true;
  }

  return res;
}

/*
@brief Сравнивает, равно ли число нулю

@param one s21_decimal
@param two s21_decimal
@return bool true - число равно нулю, false - не оба числа равны нулю
*/
bool s21_compare_to_zero(s21_decimal* decimal) {
  bool res = false;

  if (0 == decimal->bits[0] && 0 == decimal->bits[1] && 0 == decimal->bits[2]) {
    res = true;
  }

  return res;
}

/*
@brief Возвращает знак числа

@param decimal s21_decimal
@return res 1 - отрицательный, 0 - положительный
*/
int s21_get_sign(s21_decimal* decimal) {
  int res = s21_check_bit(decimal->bits[3], 31);
  return res;
}

// void s21_decimal_set_sign(s21_decimal * decimal) {
//   s21_decimal_set_bit()
// }

// оставить функцию воид или возвращать ошибку?
// bool s21_remove_zeroes(s21_decimal* decimal) {
//   bool res = true;
  
//   if (s21_validate_decimal(decimal))
//   {
//     int scale = s21_get_scale(decimal);
//   }
  

//   return res;
// }

/*
@brief Возвращает скейл от 0 до 28 включительно

@param decimal s21_decimal *
@return unsigned int scale
*/
unsigned int s21_get_scale(s21_decimal* decimal) {
  fields field;
  field.num = decimal->bits[3];
  unsigned int scale = field.bits.scale;

  return scale;
}

bool s21_validate_decimal(s21_decimal* decimal) {
  bool res = false;
  unsigned int scale = s21_get_scale(decimal);

  if (0 < scale && scale < 29)
  {
    res = true;
  }
  if (res && s21_compare_to_zero(decimal)) {
    res = false;
  }

  return res;
}