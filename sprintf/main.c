#include "../s21_string.h"
#include <stdio.h>

#define BUFF_SIZE 400

int main() {
    char format[] = "all and testing %.5d %.17f %c %.0s %u status";

    char buff[BUFF_SIZE];
    char buffOrig[BUFF_SIZE];
    sprintf(buffOrig, format, 444, 1000000.0 / 3.0, 'h', "lool", 444);
    s21_sprintf(buff, format, 444, 1000000.0 / 3.0, 'h', "lool", 444);

    printf("original: %s*\n", buffOrig);
    printf("custom  : %s*\n", buff);

    return 0;
}