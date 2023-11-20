#include "../s21_string.h"
#include <stdio.h>

#define BUFF_SIZE 400

int main() {
    char format[] = "all and testing %.5d %.17f %c %.5s %u status";

    char buff[BUFF_SIZE];
    char buffOrig[BUFF_SIZE];
    int result = sprintf(buffOrig, format, 444, 1000000.0 / 3.0, 'h', NULL, 444);
    int resultC = s21_sprintf(buff, format, 444, 1000000.0 / 3.0, 'h', NULL, 444);

    printf("original: %s*\n", buffOrig);
    printf("custom  : %s*\n", buff);
    printf("orifinal return: %d\n", result);
    printf("custom return  : %d\n", resultC);

    return 0;
}