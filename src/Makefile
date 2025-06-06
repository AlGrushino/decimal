CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=gnu11
GCOV = -fprofile-arcs -ftest-coverage

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
    CLIBS=-lcheck -lm 
endif

ifeq ($(UNAME_S), Darwin)
    CLIBS=-lcheck -lm
endif

all: s21_decimal.a

clean:
	@rm -rf *.o *.gcno *.gcda *.gcov *.a test logs

s21_decimal.a: clean s21_arithmetic.o s21_comparison.o s21_converters.o s21_other.o
	$(CC) $(CFLAGS) -c 

# test:
# 	rm -rf test


# bit_operations
# bit_operations.a:
# 	$(CC) $(CFLAGS) -c bit_operations/bit_operations.c
# 	ar rcs bit_operations.a

bit_operations.a:
	$(CC) $(CFLAGS) -c bit_operations/bit_operations.c -o bit_operations.o
	ar rcs bit_operations.a bit_operations.o


test_bit_operations:
	@rm -rf test
	@$(CC) $(CFLAGS) $(GCOV) bit_operations/test.c bit_operations/bit_operations.c $(CLIBS) -o test
	@./test

test_arithmetics:
	@rm -rf test
	@$(CC) $(CFLAGS) $(GCOV) arithmetic/test.c arithmetic/s21_arithmetic.c bit_operations/bit_operations.c $(CLIBS) -o test
	@./test

# test_bit_operations:
# 	@rm -rf test
# 	@$(CC) $(CFLAGS) $(GCOV) bit_operations/test.c bit_operations/bit_operations.c $(CLIBS) -o test
# 	@./test

test_other:
	@rm -rf test
	@$(CC) $(CFLAGS) $(GCOV) other/test.c other/s21_other.c $(CLIBS) -o test
	@./test

gcov_bit_operations: test_bit_operations
	@rm -rf test-test.gcda test-test.gcno
	@mkdir logs
	@gcovr --html-self-contained --html-details -o logs/report.html
	@echo "Building report..."
	@open logs/report.html

# comparison
comparison.a:
	$(CC) $(CFLAGS) -c comparison/s21_comparison.c
	ar rcs comparison.a

test_comparison:
	@rm -rf test
	@$(CC) $(CFLAGS) $(GCOV) comparison/test.c comparison/s21_comparison.c $(CLIBS) -o test
	@./test

gcov_comparison: test_comparison
	@rm -rf test-test.gcda test-test.gcno
	@mkdir logs
	@gcovr --html-self-contained --html-details -o logs/report.html
	@echo "Building report..."
	@open logs/report.html

gcov_other: test_other
	@rm -rf test-test.gcda test-test.gcno
	@mkdir logs
	@gcovr --html-self-contained --html-details -o logs/report.html
	@echo "Building report..."
	@open logs/report.html
