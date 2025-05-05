CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11

GCOV = -fprofile-arcs -ftest-coverage

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
    CLIBS=-lcheck -lm -lsubunit
endif

ifeq ($(UNAME_S), Darwin)
    CLIBS=-lcheck -lm
endif

all: s21_decimal.a

clean:
	@rm -rf *.o *.gcno *.gcda *.gcov *.a test logs

# s21_decimal.a: clean s21_arithmetic.o s21_comparison.o s21_converters.o s21_other.o
# 	$(CC) $(CFLAGS) -c 

# test:
# 	rm -rf test
	

# bit_operations
bit_operations.a:
	$(CC) $(CFLAGS) -c bit_operations/bit_operations.c
	ar rcs bit_operations.a

test_bit_operations:
	rm -rf test
	@$(CC) $(CFLAGS) $(GCOV) bit_operations/test.c bit_operations/bit_operations.c $(CLIBS) -o test
	@./test