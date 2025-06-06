#include "s21_other.h"


//что с округлением тут??
void s21_mult_by_ten(s21_decimal *res) { // <<1 умножение на два: (<<1 + <<3) == умножение на 10
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

void s21_mult_by_ten_times(s21_decimal *res, int times) {
    for (int i = 0; i<times; i++) {
        s21_mult_by_ten(res);
    }
}

void s21_normal_rounding(unsigned int mantissa[3], unsigned long long rest) {
    if (rest >= 5) {
        int carry = 1;
        for (int i = 0; i < 3 && carry; i++) {
            unsigned long long sum = (unsigned long long)mantissa[i] + carry;
            mantissa[i] = (unsigned int)sum;
            carry = (sum >> 32) & 1;
        }
    }
}

void s21_div_by_ten(s21_decimal *res) { 
    unsigned int temp_mantissa[3] = {res->bits[0], res->bits[1], res->bits[2]}; //92 бита
    unsigned long long temp = 0; //64 бита (больше 32 на случай, если будет overflow) 
    unsigned long long rest = 0;
    for (int i = 2; i>=0; i--) {
        temp = (rest << 32) | temp_mantissa[i];
        temp_mantissa[i] = (unsigned int)(temp / 10);
        rest = temp % 10;
    }
    s21_normal_rounding(temp_mantissa, rest);
    for (int i = 0; i<3;i++) {
        res->bits[i] = temp_mantissa[i];
    }
}

void s21_div_by_ten_without_rounding(s21_decimal *res) { //??????
    unsigned int temp_mantissa[3] = {res->bits[0], res->bits[1], res->bits[2]}; //92 бита
    unsigned long long temp = 0; //64 бита (больше 32 на случай, если будет overflow) 
    unsigned long long rest = 0;
    for (int i = 2; i>=0; i--) {
        temp = (rest << 32) | temp_mantissa[i];
        temp_mantissa[i] = (unsigned int)(temp / 10);
        rest = temp % 10;
    }
  }

void s21_div_by_ten_times(s21_decimal *res, int times) {
    for (int i = 0; i<times; i++) {
        s21_div_by_ten(res);
    }
}

void s21_set_scale(s21_decimal *res, unsigned char scale) { //unsigned пч нет отриц, char потому что он как раз 8 бит 
    res->bits[3] &= ~(0xFF << 16);
    res->bits[3] |= ((int)scale << 16); // приводим к int так как работаем со структурой интов 
}

int s21_get_scale(s21_decimal *res) {
    return (res->bits[3] >> 16) & 0xFF;
}



int s21_is_divisible_by_10(s21_decimal *dec) {
    unsigned int temp_mantissa[3] = {dec->bits[0], dec->bits[1], dec->bits[2]};
    unsigned long long temp = 0;
    unsigned long long rest = 0;

    for (int i = 2; i >= 0; i--) {
        temp = (rest << 32) | temp_mantissa[i];
        temp_mantissa[i] = (unsigned int)(temp / 10);
        rest = temp % 10;
    }

    return rest == 0;
}


void s21_normalization(s21_decimal *value1, s21_decimal *value2) { // do: переполнение мантиссы в случае > 28(сокращаем скейл и домнажаем) 
    int value1_scale = s21_get_scale(value1);
    int value2_scale = s21_get_scale(value2);
    if (value1_scale <= 28 && value2_scale <= 28) {
        if (value1_scale > value2_scale) {
            int diff = value1_scale - value2_scale;
            s21_set_scale(value2, value1_scale);
            s21_mult_by_ten_times(value2, diff);
        }
        else {
            int diff = value2_scale - value1_scale;
            s21_set_scale(value1, value2_scale);
            s21_mult_by_ten_times(value1, diff);
        }
    } else if (value1_scale > 28 || value2_scale > 28) {
        int diff_val1 = 28 - value1_scale;
        int diff_val2 = 28 - value2_scale;
        if (diff_val1 > 0) {
            s21_mult_by_ten_times(value1, diff_val1);
        }
        else if (diff_val1 < 0) {
            s21_div_by_ten_times(value1, -diff_val1);
        }
        s21_set_scale(value1, 28);
        if (diff_val2 > 0) {
            s21_mult_by_ten_times(value2, diff_val2);
        }
        else if (diff_val2 < 0) {
            s21_div_by_ten_times(value2, -diff_val2);
        }
        s21_set_scale(value2, 28);
    }
    int new_scale = s21_get_scale(value1); 
    while (new_scale > 0 && s21_is_divisible_by_10(value1) && s21_is_divisible_by_10(value2)) { //сокрщаем 
        s21_div_by_ten_without_rounding(value1);
        s21_div_by_ten_without_rounding(value2);
        new_scale--;
        s21_set_scale(value1, new_scale);
        s21_set_scale(value2, new_scale);
    }

}

int s21_get_sign(s21_decimal *res) {
    return (res->bits[3] >> 31) & 1;
}

void s21_set_sign(s21_decimal *res, int sign) { //а где проверять, чтобы знак был норм? 
    unsigned int mask_for_last_bit = 1<<31;
    if (sign) {
        res->bits[3] |= mask_for_last_bit;
    } else {
        res->bits[3] &= ~mask_for_last_bit;
    }
}


int s21_is_equal(s21_decimal value1, s21_decimal value2) {
    int flag = 1;
    s21_normalization(&value1, &value2);
    for (int i = 0; i<4 && flag; i++) {
        if (value1.bits[i] != value2.bits[i]) {
            flag = 0;
        }
    }
    return flag;
}

int s21_is_not_equal(s21_decimal value1, s21_decimal value2) {
    int flag = 0;
    if (!s21_is_equal(value1, value2)) {
        flag = 1;
    }
    return flag;
}

int s21_is_less_bits(s21_decimal value1, s21_decimal value2) {
    int flag = 0;
    for (int i = 2; i>=0; i--) {
        if (value1.bits[i] < value2.bits[i]){
            flag = 1;
        }
    }
    return flag;
}

int s21_is_less(s21_decimal value1, s21_decimal value2) { //если оба нули?
    int flag = 0;
    int sign1 = s21_get_sign(&value1);  
    int sign2 = s21_get_sign(&value2);
    s21_normalization(&value1, &value2);
  
    if (sign1 > sign2) {
        flag = 1;
    } else if (sign1 == sign2) {
        if (sign1 == 1) {
            flag = s21_is_less_bits(value2, value1);
        }
        else {
            flag = s21_is_less_bits(value1, value2);
        }
    }
    return flag;
  }

int s21_is_less_or_equal(s21_decimal value1, s21_decimal value2) {
    int flag = 0;
    if (s21_is_equal(value1, value2) || s21_is_less(value1, value2)) {
        flag = 1;
    }
    return flag;
}

int s21_is_greater(s21_decimal value1, s21_decimal value2) {
    int flag = 0;
    if (!s21_is_less_or_equal(value1, value2)) {
        flag = 1;
    }
    return flag; 
}

int s21_is_greater_or_equal(s21_decimal value1, s21_decimal value2) {
    int flag = 0;
    if (s21_is_equal(value1, value2) || s21_is_greater(value1, value2)) {
        flag = 1;
    }
    return flag; 
}

void s21_init_decimal(s21_decimal *value) {
    value->bits[0] = 0;
    value->bits[1] = 0;
    value->bits[2] = 0;
    value->bits[3] = 0;
  }

typedef struct {
    unsigned int bits[6];  // 192-битная мантисса (96*2)
    int scale;             // масштаб 
    int sign;              // знак 
} s21_big_decimal;

void s21_from_decimal_to_big(s21_decimal dec, s21_big_decimal *big) {
    big->bits[0] = dec.bits[0];
    big->bits[1] = dec.bits[1];
    big->bits[2] = dec.bits[2];
    big->bits[3] = 0;
    big->bits[4] = 0;
    big->bits[5] = 0;
    big->scale = s21_get_scale(&dec);
    big->sign = s21_get_sign(&dec);
}


