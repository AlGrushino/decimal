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
bit_operations.o: bit_operations/bit_operations.c
	@$(CC) $(CFLAGS) -c bit_operations/bit_operations.c

test_bit_operations:
	@rm -rf test
	@$(CC) $(CFLAGS) $(GCOV) bit_operations/test.c bit_operations/bit_operations.c $(CLIBS) -o test
	@./test

gcov_bit_operations: test_bit_operations
	@rm -rf test-test.gcda test-test.gcno
	@mkdir logs
	@gcovr --html-self-contained --html-details -o logs/report.html
	@echo "Building report..."
	@open logs/report.html

# comparison
comparison.o: comparison/s21_comparison.c
	@$(CC) $(CFLAGS) -c comparison/s21_comparison.c

test_comparison: comparison.o bit_operations.o
	@rm -rf test
	@$(CC) $(CFLAGS) $(GCOV) comparison/test.c comparison/s21_comparison.c bit_operations.o $(CLIBS) -o test
	@./test

gcov_comparison: test_comparison
	@rm -rf test-test.gcda test-test.gcno
	@mkdir logs
	@gcovr --html-self-contained --html-details -o logs/report.html
	@echo "Building report..."
	@open logs/report.html

big_decimal.o: big_decimal/big_decimal.c
	@$(CC) $(CFLAGS) -c big_decimal/big_decimal.c

test_big_decimal: big_decimal.o bit_operations.o
	@rm -rf test
	@$(CC) $(CFLAGS) $(GCOV) big_decimal/test.c big_decimal/big_decimal.c bit_operations.o $(CLIBS) -o test
	@./test

gcov_big_decimal: test_big_decimal
	@rm -rf test-test.gcda test-test.gcno
	@mkdir logs
	@gcovr --html-self-contained --html-details -o logs/report.html
	@echo "Building report..."
	@open logs/report.html