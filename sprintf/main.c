#include "../s21_string.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <wchar.h>

int main() {
    char buff[400];
    char buff2[400];
    char format[] = "print: %.4g lol";
    sprintf(buff, format, 23455.3256);
    s21_sprintf(buff2, format, 23455.3256);

    printf("original: %s\n", buff);
    printf("custom  : %s\n", buff2);

    return 0;
}