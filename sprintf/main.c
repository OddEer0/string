#include "../s21_string.h"
#include <stdio.h>

#define BUFF_SIZE 400

int main() {
    char format[] = "all and testing %hd %d %ld %hu %u %lu status";

    char buff[BUFF_SIZE];
    char buffOrig[BUFF_SIZE];
    int result = sprintf(buffOrig, format, __SHRT_MAX__, __INT_MAX__, __LONG_MAX__, __UINT16_MAX__, __UINT32_MAX__, __UINT64_MAX__);
    int resultC = s21_sprintf(buff, format, __SHRT_MAX__, __INT_MAX__, __LONG_MAX__, __UINT16_MAX__, __UINT32_MAX__, __UINT64_MAX__);

    printf("original: %s*\n", buffOrig);
    printf("custom  : %s*\n", buff);
    printf("orifinal return: %d\n", result);
    printf("custom return  : %d\n", resultC);

    return 0;
}