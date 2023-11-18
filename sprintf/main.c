#include "../s21_string.h"
#include <stdio.h>

#define BUFF_SIZE 400

int main() {
    char format[] = "%d";

    char buff[BUFF_SIZE];
    char buffOrig[BUFF_SIZE];
    sprintf(buffOrig, format, 4);
    s21_sprintf(buff, format, 4);

    printf("original: %s\n", buffOrig);
    printf("custom: %s\n", buff);

    return 0;
}