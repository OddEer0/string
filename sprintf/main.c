#include "../s21_string.h"
#include <stdio.h>

#define BUFF_SIZE 400

int main() {
    char format[] = "all and testing %d status";

    char buff[BUFF_SIZE];
    char buffOrig[BUFF_SIZE];
    sprintf(buffOrig, format, 444);
    s21_sprintf(buff, format, 444);

    printf("original: %s*\n", buffOrig);
    printf("custom  : %s*\n", buff);

    return 0;
}