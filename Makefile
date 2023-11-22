CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
CHECK_FLAGS = $(shell pkg-config --cflags --libs check)
GCOV_FLAGS = -fprofile-arcs -ftest-coverage -lgcov --coverage

all: clean s21_string.a test

test: string/string.c __test__/*.c sprintf/strategy.c sprintf/index.c shared/*.c
	$(CC) $(CFLAGS) $^ -o $@ $(GCOV_FLAGS) $(CHECK_FLAGS)

eztest: string/string.c __test__/*.c sprintf/strategy.c sprintf/index.c shared/*.c
	$(CC) $^ -o $@ $(GCOV_FLAGS) $(CHECK_FLAGS)
	./eztest

watch: clean s21_string.a test
	./test

sprint:
	$(CC) $(CFLAGS) string/string.c shared/str_format_parser.c shared/utils.c sprintf/index.c sprintf/strategy.c sprintf/main.c -o sprint
	./sprint

ezsprint:
	$(CC) string/string.c shared/str_format_parser.c shared/utils.c sprintf/index.c sprintf/strategy.c sprintf/main.c -o sprint
	./sprint

s21_string.a:
	$(CC) $(CFLAGS) -c string/string.c -o string.o
	$(CC) $(CFLAGS) -c shared/utils.c -o utils.o
	$(CC) $(CFLAGS) -c shared/str_format_parser.c -o str_format_parser.o
	$(CC) $(CFLAGS) -c sprintf/index.c -o sprintf.o
	# $(CC) $(CFLAGS) -c sprintf/strategy.c -o sprintf_strategy.o
	ar rcs $@ *.o

gcov_report:

clean:
	rm -fr *.o *.a s21_math.a test test.dSYM/ *.gcda *.gcno report/ test.info
	rm -rf eztest