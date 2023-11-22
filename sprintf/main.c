#include "../s21_string.h"
#include <stdio.h>

#define BUFF_SIZE 500

int main() {
    char format[] = "print: %o %ho %lo, %+o %+o % o %05o %0-5o %-5o %5o %.6o %#o";

    char buff[BUFF_SIZE];
    char buffOrig[BUFF_SIZE];
    int result = sprintf(buff, format, __INT16_MAX__, __INT32_MAX__, __INT64_MAX__, 2, 2, 2, 23, 23, 23, 23, 20, 222);
    int resultC = s21_sprintf(buffOrig, format, __INT16_MAX__, __INT32_MAX__, __INT64_MAX__, 2, 2, 2, 23, 23, 23, 23, 20, 222);

    printf("original: %s*\n", buffOrig);
    printf("custom  : %s*\n", buff);
    printf("orifinal return: %d\n", result);
    printf("custom return  : %d\n", resultC);

    return 0;
}