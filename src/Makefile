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

s21_decimal.a: other/s21_other.o
	ar rcs s21_decimal.a other/s21_other.o

other/s21_other.o: 
	$(CC) $(CFLAGS) -c other/s21_other.c -o other/s21_other.o

# s21_arithmetic.o: s21_arithmetic.c s21_arithmetic.h
# 	$(CC) $(CFLAGS) -c s21_arithmetic.c -o s21_arithmetic.o

# test:
# 	rm -rf test


# bit_operations
# bit_operations.a:
# 	$(CC) $(CFLAGS) -c bit_operations/bit_operations.c -o bit_operations.o
# 	ar rcs bit_operations.a bit_operations.o

bit_operations.a:
	$(CC) $(CFLAGS) -c bit_operations/bit_operations.c -o bit_operations.o
	ar rcs bit_operations.a bit_operations.o


#test_bit_operations:
#	@rm -rf test
#	@$(CC) $(CFLAGS) $(GCOV) bit_operations/test.c bit_operations/bit_operations.c $(CLIBS) -o test
#	@./test

#test_other:
#	@rm -rf test
#	@$(CC) $(CFLAGS) $(GCOV) other/test.c other/s21_other.c $(CLIBS) -o test
#	@./test

test_mul: s21_decimal.a 
	@rm -rf test
	@$(CC) $(CFLAGS) $(GCOV) test_mul.c s21_decimal.a -o test $(CLIBS)
	@./test

gcov_bit_operations: test_bit_operations
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
