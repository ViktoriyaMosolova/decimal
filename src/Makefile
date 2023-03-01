CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11
GCOVFLAGS = --coverage 
TEST_FLAGS = -lm -lcheck

HEADER = s21_decimal.h 
SOURCES_ALL = $(wildcard *.c)

ifeq ($(shell uname -s), Linux)	
	FLAGS += -lpthread -lrt -lm -lsubunit
endif

OBJ_LIBRARY := $(patsubst %.c, %.o, $(SOURCES_ALL))

%.o: %.c $(HEADER)
	gcc $(CFLAGS) -c $< -o $@

all: s21_decimal.a
	gcc *.c *.a -o test
	./test

test: 
	make s21_decimal.a
	gcc -g *.c *.a -o test
	#gdb ./test
	lldb ./test

s21_decimal.a: $(OBJ_LIBRARY)  $(HEADER)
	ar rcs s21_decimal.a $(OBJ_LIBRARY)
	ranlib s21_decimal.a
	rm -f *.o

#test: clean s21_decimal.a
#	gcc $(CFLAGS) s21_decimal.c s21_decimal.a -o test -lm -lcheck $(FLAGS)
#	./test
#	rm test


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

