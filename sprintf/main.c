#include "../s21_string.h"
#include <stdio.h>

#define BUFF_SIZE 400

int main() {
    char format[] = "all and testing %.5d %.34f %c %.0s status";

    char buff[BUFF_SIZE];
    char buffOrig[BUFF_SIZE];
    sprintf(buffOrig, format, 444, 1000000.0 / 3.0, 'h', "lool");
    s21_sprintf(buff, format, 444, 1000000.0 / 3.0, 'h', "lool");

    printf("original: %s*\n", buffOrig);
    printf("custom  : %s*\n", buff);

    return 0;
}