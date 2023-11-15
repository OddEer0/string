#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "./str_format_parser.h"
#include "../s21_string.h"
#include "./helper.h"

int isNumberType(char type) {
    return !!s21_strchr("df", type);
}

s21_size_t addHelper(char *str, TStrFormatParse *PFormat, va_list *args, char* value, int width) {
    s21_size_t length = s21_strlen(value);
    int isNum = isNumberType(PFormat->type);
    int isCorrectPlusFlag = isNum && value[0] != '-' && PFormat->flags->plus;
    int isCorrectSpaceFlag = isNum && value[0] != '-' && PFormat->flags->space && !PFormat->flags->plus;
    if (isCorrectPlusFlag || isCorrectSpaceFlag) length++;
    width = width - length;
    if (width < 0) width = 0;

    char buff[width + 1];
    buff[width + 1] = '\0';
    for (int i = 0; i < width; i++)
        buff[i] = PFormat->flags->zero && !PFormat->flags->minus ? '0' : ' ';
        
    if (!PFormat->flags->minus) 
        s21_strncat(str, buff, width);
    if (isCorrectPlusFlag)
        s21_strncat(str, "+", 1);
    else if (isCorrectSpaceFlag)
        s21_strncat(str, " ", 1);
    s21_strncat(str, value, length);
    if (PFormat->flags->minus) 
        s21_strncat(str, buff, width);

    return width + length;
}

s21_size_t printd(char *str, TStrFormatParse *PFormat, va_list *args) {
    int width = PFormat->widthStar ? va_arg(*args, int) : PFormat->width;
    int value = va_arg(*args, int);
    char buff[30];
    s21_itoa(value, buff, 10);
    return addHelper(str, PFormat, args, buff, width);
}

s21_size_t printPercent(char *str, TStrFormatParse *PFormat, va_list *args) {
    int width = PFormat->widthStar ? va_arg(*args, int) : PFormat->width;
    return addHelper(str, PFormat, args, "%", width);
}

s21_size_t PrintStrategy(char* str, TStrFormatParse *PFormat, va_list *args) {
    s21_size_t result = 0;
    if (PFormat->type == 'd') {
        result = printd(str, PFormat, args);
    } else if (PFormat->type == '%') {
        result = printPercent(str, PFormat, args);
    }
    return result;
}

int s21_sprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);

    str[0] = '\0';

    char *tmp = (char*)format, *strTmp = str;
    s21_size_t formatLength = s21_strlen(format);
    
    for (int length = 0; formatLength; formatLength--, strTmp++, tmp++, length++) {
        if (isFormat(*tmp)) {
            TStrFormatParse *PFormat = createFormatParse();
            strFormatParser(tmp, PFormat);
            str[length] = '\0';
            s21_size_t len = PrintStrategy(str, PFormat, &args);
            tmp += PFormat->formatLength;
            strTmp += len - 1;
            length += len - 1;

            freeFormatParse(PFormat);
        } else {
            *strTmp = *tmp;
        }
    }
    *(strTmp + 1) = '\0';

    va_end(args);
    return 0;
}

int main() {
    char buff[400];
    char format[] = "%*d %+20d %*% %#f lol all\n";
    s21_sprintf(buff, format, 4, 14, 20, 3, 5);
    printf(format, 4, 14, 20, 3, 5.0);
    printf("%s\n", buff);

    return 0;
}