#include "s21_help_func.h"
#include "math.h"
#include <string.h>
#include <inttypes.h>
#include <stdio.h>

int sum_mantis(s21_decimal a, s21_decimal b, s21_decimal* res) {
    s21_decimal temp = *res;
    int carry = 0;
    for(int i = 0; i < 3; i++) {
        __uint64_t sum = (__uint64_t)a.bits[i] + (__uint64_t)b.bits[i] + (__uint64_t)carry;
        carry = sum >> 32;
        temp.bits[i] = (__uint32_t)sum;
    }
    if(!carry)
        *res = temp;

    return carry == 0 ? 0 : 1;
}

int scale_down(s21_decimal* value) {
    s21_decimal res = *value;

    uint64_t temp;
    uint64_t remainder = 0;

    // Умножаем каждый блок на 10 + перенос
    for (int i = 2; i >= 0; i--) {
        temp = res.bits[i] + (remainder << 32);
        res.bits[i] = (uint32_t)(temp / 10);
        remainder = temp % 10;
    }

    *value = res;
    return 0;
}

int scale_up(s21_decimal* value) {
    // s21_decimal temp = *value;
    s21_decimal res = *value;

    uint64_t temp;
    uint32_t carry = 0;

    // Умножаем каждый блок на 10 + перенос
    for (int i = 0; i < 3; i++) {
        temp = (uint64_t)res.bits[i] * 10 + carry;
        res.bits[i] = (uint32_t)temp;
        carry = (uint32_t)(temp >> 32);
    }

    // //Умножаем на 8
    // for (int i = 0; i < 3; i++) {
    //     __uint64_t part = (__uint64_t)temp.bits[i] << 3;
    //     res.bits[i] = (__uint32_t)part + carry;
    //     carry = part >> 32;
    // }

    // //Переполнение
    // if(carry != 0)
    //     return 1;

    // //Умножение на 2
    // carry = 0;
    // for (int i = 0; i < 3; i++) {
    //     __uint64_t part = (__uint64_t)temp.bits[i] << 1;
    //     __uint64_t sum = part + (__uint64_t)res.bits[i] + carry;
    //     res.bits[i] = (__uint32_t)sum;
    //     carry = sum >> 32;
    // }

    if(carry != 0)
        return 1;

    *value = res;
    return 0;

}

int get_sign(int settings_bits) {
    return (settings_bits >> 31) & 1;
}
int set_sign(int* settings_bits, int sign) {
    if(sign)
        set_bit(settings_bits, 31);
    else
        unset_bit(settings_bits, 31);
}

int get_scale(int settings_bits) {
    return (settings_bits >> 16) & 0xFF;
}
int set_scale(int* settings_bits, int scale) {
    int sign = get_sign(*settings_bits);
    *settings_bits = scale << 16;
    set_sign(settings_bits, sign);
}

void set_bit(int *num, int index) {
    *num = *num | (1 << index);
}

void unset_bit(int *num, int index) {
    *num = *num & (~(1 << index));
}

int get_128_bit(__uint128_t num, int index) {
    return (num >> index) & 1;
}

int get_64_bit(__uint64_t num, int index) {
    return (num >> index) & 1;
}

int get_bit(int num, int index) {
    return (num >> index) & 1;
}

int get_float_bit(float num, int index) {
    uint32_t bits;
    memcpy(&bits, &num, sizeof(float));
    return (bits >> index) & 1;
}

void print_128_bits(__uint128_t num) {
    for(int i = 127; i >= 0; i--) {
        printf("%d", get_128_bit(num, i));
    }
    printf("\n");
}

void print_64_bits(__uint64_t num) {
    for(int i = 63; i >= 0; i--) {
        printf("%d", get_64_bit(num, i));
    }
    printf("\n");
}

void print_bits(int num) {
    for(int i = 31; i >= 0; i--) {
        printf("%d", get_bit(num, i));
    }
    printf("\n");
}

void print_bits_float(float num) {
    for(int i = 31; i >= 0; i--) {
        printf("%d", get_float_bit(num, i));
    }
    printf("\n");
}

void print_decimal(s21_decimal dec) {
    for(int i = 0; i < 4; i++) {
        print_bits(dec.bits[i]);
    }
}

void print_float(s21_decimal dec) {
    __uint128_t num = 0;
    for (int i = 2; i >= 0; i--) {
        num = (num << 32) | dec.bits[i];
    }

    char buffer[40] = {0};
    int index = 39;
    buffer[index] = '\0';

    if (num == 0) {
        printf("0\n");
        return;
    }

    int scale = get_scale(dec.bits[3]);
    while (num > 0) {
        buffer[--index] = '0' + (num % 10);
        num /= 10;
        if(scale == 39 - index)
            buffer[--index] = '.';
    }

    if(get_sign(dec.bits[3]))
        buffer[--index] = '-';

    printf("%s\n", &buffer[index]);
}

void print_big_int(s21_decimal dec) {
    // Собираем 128-битное число из первых трех элементов (96 бит)
    __uint128_t num = 0;
    for (int i = 2; i >= 0; i--) {
        num = (num << 32) | dec.bits[i];
    }

    // Преобразуем 128-битное число в десятичную строку
    char buffer[40] = {0}; // Максимум 39 символов для 128-битного числа
    int index = sizeof(buffer) - 1;
    buffer[index] = '\0';
    
    int scale = get_scale(dec.bits[3]);

    while(scale--)
        num /= 10;
    if (num == 0) {
        printf("0\n");
        return;
    }


    // Обрабатываем цифры, начиная с конца
    while (num > 0) {
        index--;
        buffer[index] = '0' + (num % 10);
        num /= 10;
    }

    if(get_sign(dec.bits[3]))
        buffer[--index] = '-';

    printf("%s\n", &buffer[index]);
}


void clear_decimal(s21_decimal *dec) {
    s21_decimal clear_dec = {0};
    *dec = clear_dec;
}

int is_decimal_zero(s21_decimal dec) {
    return dec.bits[0] == 0 && dec.bits[1] == 0 && dec.bits[2] == 0;
}

int compare_mantissas(s21_decimal dec1, s21_decimal dec2) {
    int res = 0;
    for(int i = 2; i >= 0 && res == 0; i--) {
        if(dec1.bits[i] > dec2.bits[i]) res = 1;
        else if(dec1.bits[i] < dec2.bits[i]) res = -1; 
    }

    return res;
}

int normalize_scale(s21_decimal *dec1, s21_decimal *dec2) {
    int scale1 = get_scale(dec1->bits[3]);
    int scale2 = get_scale(dec2->bits[3]);
    int diff = scale1 - scale2;
    if(diff > 0) {
        while(diff != 0 && scale_up(dec2) == 0) {
            diff--;
            scale1--;
        }

        while(diff != 0 && scale_down(dec1) == 0) {
            diff--;
            scale2++;
        }

        if(diff != 0) {
            printf("OVERFLOW\n");
            return 1;
        }
    } else if (diff < 0) {
        while(diff != 0 && scale_up(dec1) == 0) {
            diff++;
            scale2--;
        }
        while(diff != 0 && scale_down(dec2) == 0) {
            diff++;
            scale1++;
        }


        if(diff != 0) {
            printf("OVERFLOW\n");
            return 1;
        }
    }

    set_scale(&dec1->bits[3], scale1);
    set_scale(&dec2->bits[3], scale2);
}