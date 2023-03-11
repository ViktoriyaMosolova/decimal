CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11
TEST_FLAGS = -lm -lpthread -lrt
S21_SUITE_C = tests/*.c
S21_SUITE_O = suite_*.o
GCOV_FLAGS = -ftest-coverage -fprofile-arcs


HEADER = s21_decimal.h 
SOURCES_ALL = $(wildcard *.c)

ifeq ($(shell uname -s), Linux)	
	TEST_FLAGS = -lsubunit -lm -lpthread -lrt
endif

OBJ_LIBRARY := $(patsubst %.c, %.o, $(SOURCES_ALL))

%.o: %.c $(HEADER)
	gcc $(CFLAGS) -c $< -o $@

all: s21_decimal.a
	gcc *.c *.a -o test
	./test

s21_decimal.a: $(OBJ_LIBRARY)  $(HEADER)
	ar rcs s21_decimal.a $(OBJ_LIBRARY)
	ranlib s21_decimal.a
	#rm -f *.o

test: s21_decimal.a
	gcc $(CFLAGS) -c $(S21_SUITE_C) main.c
	gcc $(CFLAGS) -o test $(S21_SUITE_O) main.o s21_decimal.a -lcheck -lm -lsubunit	
	rm -rf *.o *.a
	./test


gcov_report: s21_decimal.a
	gcc ${GCOV_FLAGS} -c ${S21_SUITE_C}
	gcc $(GCOV_FLAGS) *.o s21_decimal.a -lcheck ${TEST_FLAGS} -o test
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

check:
	clang-format -style=Google -n *.c
	clang-format -style=Google -n *.c

rebuild: clean all

clean:
	rm -f *.gcno *.gcda *.info *.gcov 
	rm -f *.o *.a
	rm -rf report
	rm -f *.out
	rm test
cflag = -Wall -Werror -Wextra -std=c11

