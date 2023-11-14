#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "./str_format_parser.h"
#include "../s21_string.h"
#include "./helper.h"

s21_size_t printd(char *str, TStrFormatParse *PFormat, va_list *args) {
    int value = va_arg(*args, int);
    char buff[30];
    s21_itoa(value, buff, 10);
    s21_size_t length = s21_strlen(buff);
    s21_strncat(str, buff, length);
    return length;
}

s21_size_t PrintStrategy(char* str, TStrFormatParse *PFormat, va_list *args) {
    s21_size_t result = 0;
    if (PFormat->type == 'd') {
        result = printd(str, PFormat, args);
    }
    return result;
}

int s21_sprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);

    char *tmp = (char*)format, *strTmp = str;
    s21_size_t formatLength = s21_strlen(format);
    
    for (; formatLength; formatLength--, strTmp++, tmp++) {
        if (isFormat(*tmp)) {
            TStrFormatParse *PFormat = createFormatParse();
            strFormatParser(tmp, PFormat);
            s21_size_t len = PrintStrategy(str, PFormat, &args);
            tmp += PFormat->formatLength;
            strTmp += len - 1;

            freeFormatParse(PFormat);
        } else {
            *strTmp = *tmp;
        }
    }

    va_end(args);
    return 0;
}

int main() {
    char buff[400];
    char format[] = "%d %#20.20d lol all\n";
    s21_sprintf(buff, format, 20, 14);
    printf(format, 20, 14);
    printf("%s", buff);

    return 0;
}