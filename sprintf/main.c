#include "../s21_string.h"
#include <stdio.h>

#define BUFF_SIZE 500

int main() {
    // char format[] = "print: %% %#% %-020.10% %.10l% %10h% % #L% %d";
    char format[] = "print: %% %#% %-020.10% %.10l% %10h% % #L% %d";

    char buff[BUFF_SIZE];
    char buffOrig[BUFF_SIZE];
    int result = sprintf(buffOrig, format, 2323);
    int resultC = s21_sprintf(buff, format, 2323);

    printf("original: %s*\n", buffOrig);
    printf("custom  : %s*\n", buff);
    printf("original return: %d\n", result);
    printf("custom return  : %d\n", resultC);

    return 0;
}