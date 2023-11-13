CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
CHECK_FLAGS = $(shell pkg-config --cflags --libs check)
GCOV_FLAGS = -fprofile-arcs -ftest-coverage -lgcov --coverage

ez:
	$(CC)  string/string.c

all: clean s21_string.a test

test: string/string.c __test__/main.c
	$(CC) $(CFLAGS) $^ -o $@ $(GCOV_FLAGS) $(CHECK_FLAGS)

watch: clean s21_string.a test
	./test

sprintf:
	$(CC) string/string.c string/str_format_parser.c string/sprintf.c -o a

s21_string.a:
	$(CC) $(CFLAGS) -c string/string.c -o string.o
	ar rcs $@ string.o

gcov_report:

clean:
	rm -fr *.o *.a s21_math.a test test.dSYM/ *.gcda *.gcno report/ test.info