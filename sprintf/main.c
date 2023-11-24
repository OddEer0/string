#include "../s21_string.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <wchar.h>


#define BUFF_SIZE 500

int main() {
    setlocale(LC_ALL, "");
    // char format[] = "print: %% %#% %-020.10% %.10l% %10h% % #L% %d";
    char format[] = "print: %020p lol";

    char buff[BUFF_SIZE];
    char buffOrig[BUFF_SIZE];
    int result = sprintf(buffOrig, format, buff);
    int resultC = s21_sprintf(buff, format, buff);

    printf("original: %s*\n", buffOrig);
    printf("custom  : %s*\n", buff);
    printf("original return: %d\n", result);
    printf("custom return  : %d\n", resultC);

    // setlocale(LC_ALL, "C.UTF-8"); // this also works

    wchar_t hello_eng[] = L"Hello World!";
    wchar_t hello_china[] = L"世界, 你好!";
    wchar_t *hello_japan = L"こんにちは日本!";
    printf("%ls\n", hello_eng);
    printf("%ls\n", hello_china);
    printf("%ls\n", hello_japan);

    return 0;
}