#include "s21_decimal.h"

// вынести в хедер

typedef enum s21_arithmetic_res {
    ARITHM_OK = 0,
    GR_EQ_ETERN = 1,
    LE_EQ_ETERN = 2,
    DIV_BY_ZERO = 4

} arithmetic_res;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
    int err_code = ARITHM_OK;

    // нужно проверить, что оба децимала норм
    // проверить знаки децималов
    
    





    return err_code;
}
