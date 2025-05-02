CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11

GCOV = -fprofile-arcs -ftest-coverage

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CLIBS=-lcheck -lm -lsubunit
endif

ifeq ($(UNAME_S),Darwin)
    CLIBS=-lcheck -lm
endif

all: s21_decimal.a

clean:
	@rm -rf *.o *.gcno *.gcda *.gcov *.a test logs

# s21_decimal.a: 


s21_arithmetic.o: s21_arithmetic.c
	$(CC) $(CFLAGS) -c s21_arithmetic.c

s21_comparison.o: s21_comparison.c
	$(CC) $(CFLAGS) -c s21_comparison.c

s21_converters.o: s21_converters.c
	$(CC) $(CFLAGS) -c s21_converters.c

s21_other.o: s21_other.c
	$(CC) $(CFLAGS) -c s21_other.c

test s21_decimal.a:
	rm -rf test
	@$(CC) $(CFLAGS) $(GCOV) 