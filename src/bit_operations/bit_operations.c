
/*
Сдвиг работает таким образом, что зануляются все биты слева и справа от индекса
*/
int s21_check_bit_set(int num, int index){
    return num & (1 << index);
}

int s21_set_bit(int num, int index){
    return num | (1 << index);
}

/*
~ инвертирует биты
bits = 0000 0001
~bits
bits = 1111 1110
*/
int s21_unset_bit(int num, int index){
    return num & (~(1 << index));
}