#include "s21_help_func.h"

int main() {
    s21_decimal dec1 = {0};
    s21_decimal dec2 = {0};
    // dec1.bits[0] = __UINT32_MAX__;
    // dec1.bits[1] = __UINT32_MAX__;
    // dec1.bits[2] = __UINT32_MAX__;
    // dec1.bits[3] = __UINT32_MAX__;
    dec1.bits[0] = 10000;
    dec2.bits[0] = 100;
    // s21_from_float_to_decimal(b, &dec1);

    // set_scale(&dec1.bits[3], 2);
    // print_float(dec1);
    // print_float(dec2);
    // printf("IS_EQUAL = %d\n", s21_is_less(dec1, dec2));
    
    // while(scale_up(&dec1) == 0) {
    //     print_big_int(dec1);
    // }
    // while(!is_decimal_zero(dec1)) {
    //     scale_down(&dec1);
    //     print_big_int(dec1);
    // }
}