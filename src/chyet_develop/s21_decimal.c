#include "s21_decimal.h"
#include "s21_help_func.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    if(is_decimal_zero(value_1)) {
        *result = value_2;
        return 0;
    }
    else if(is_decimal_zero(value_2)) {
        *result = value_1;
        return 0;
    }

    clear_decimal(result);

    int scale1 = get_scale(value_1.bits[3]);
    int scale2 = get_scale(value_2.bits[3]);
    int scale_diff = scale1 - scale2;

    if(scale_diff > 0) {
        if(!scale_up(&value_2)) {
            scale_diff--;
            scale1--;
        }
    }
}

int s21_is_equal(s21_decimal a, s21_decimal b) {
    normalize_scale(&a, &b);
    int sign1 = get_sign(a.bits[3]);
    int sign2 = get_sign(b.bits[3]);
    int rez = sign1 == sign2;
    for(int i = 2; i >= 0 && rez == 1; i--) {
        rez = a.bits[i] == b.bits[i];
    }

    return rez;
}

int s21_is_not_equal(s21_decimal a, s21_decimal b) {
    return !s21_is_equal(a, b);
}

int s21_is_less_or_equal(s21_decimal a, s21_decimal b) {
    return !s21_is_greater(a, b);
}

int s21_is_less(s21_decimal a, s21_decimal b) {
    normalize_scale(&a, &b);
    print_big_int(a);
    print_big_int(b);
    int sign1 = get_sign(a.bits[3]);
    int sign2 = get_sign(b.bits[3]);
    int rez = sign1 > sign2;
    for(int i = 2; i >= 0 && rez == 0; i--) {
        rez = a.bits[i] < b.bits[i];
    }

    return rez;
}

int s21_is_greater_or_equal(s21_decimal a, s21_decimal b) {
    return !s21_is_less(a, b);
}

int s21_is_greater(s21_decimal a, s21_decimal b) {
    normalize_scale(&a, &b);
    print_big_int(a);
    print_big_int(b);
    int sign1 = get_sign(a.bits[3]);
    int sign2 = get_sign(b.bits[3]);
    int rez = sign1 < sign2;
    for(int i = 2; i >= 0 && rez == 0; i--) {
        rez = a.bits[i] > b.bits[i];
    }

    return rez;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    clear_decimal(dst);

    if(src == 0) {
        return 0;
    }

    if(src < 0 ) {
        set_sign(dst, 1);
        src = -src;
    }

    int int_len = 0;
    float temp = src;
    while(temp > 1) {
        int_len++;
        temp /= 10;
    }

    __int64_t num = 0;
    int float_len = 0;
    temp = src;
    while(temp - (int)temp != 0) {
        temp *= 10;
        float_len++;
        printf("float: %f\n", temp - (int)temp);
    }
    num = temp;
    printf("int_len %d\n", int_len);
    printf("float_len %d\n", float_len);

    return 0;
}


int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    clear_decimal(dst);

    if (src == 0) {
        return 0;
    }

    if (src < 0) {
        set_sign(dst, 1);
        src = -src;
    }

    dst->bits[0] = (__uint32_t)src;

    return 0;
}
