#include "./str_format_parser.h"
#include "../s21_string.h"
#include <stdlib.h>

int isFlags(char sym) {
    return !!s21_strchr("-+#0 ", sym);
}

int isType(char sym) {
    return !!s21_strchr("cdfsugGeExXop%", sym);
}

int isPrecision(char sym) {
    return sym == '.';
}

int isFormat(char sym) {
    return sym == '%';
}

int isNumber(char sym) {
    return !!s21_strchr("1234567890", sym);
}

int isLength(char sym) {
    return !!s21_strchr("lhL", sym);
}

int convertCharToInt(char sym) {
    return sym - '0';
}

int getIntFromCharsSize(char* str) {
    int result = 0;

    for (char* tmp = str; *tmp != '\0' && isNumber(*tmp); tmp++, result++);

    return result;
}

int convertCharsToInt(char* sym) {
    int result = 0;
    int size = getIntFromCharsSize(sym);

    for (char *tmp = sym; size; size--, tmp++) {
        result += convertCharToInt(*tmp);
        if (size - 1) 
            result *= 10;
    }

    return result;
}

void parseFlag(TStrFormatFlagsInfo *flags, char sym) {
    switch(sym) {
        case '+':
            flags->plus = 1;
            break;
        case '-':
            flags->minus = 1;
            break;
        case '#':
            flags->jail = 1;
            break;
        case ' ':
            flags->space = 1;
            break;
        case '0':
            flags->zero = 1;
            break;
    }
}

// TODO - Пока нет обработок на знак окончание строки, надо будет сделать
int strFormatParser(char* format, TStrFormatParse* strFormatParse) {
    char *tmp = format + 1;
    int length = 0;

    if (isFormat(*tmp) || *tmp == '\0') {
        strFormatParse->isIgnore = 1;
        return 0;
    }

    for (; isFlags(*tmp); tmp++, length++)
        parseFlag(strFormatParse->flags, *tmp);


    if (isNumber(*tmp)) {
        strFormatParse->width = convertCharsToInt(tmp);
        int size = getIntFromCharsSize(tmp);
        length += size;
        tmp += size;
    } else if (*tmp == '*') {
        strFormatParse->widthStar = 1;
        length++; tmp++;
    }

    if (isPrecision(*tmp)) {
        tmp++; length++;
        if (*tmp == '*') {
            strFormatParse->precisionStar = 1;    
            length++; tmp++;
        } else {
            strFormatParse->precision = convertCharsToInt(tmp);
            int size = getIntFromCharsSize(tmp);
            length += size;
            tmp += size;
        }
    }

    if (isLength(*tmp)) {
        strFormatParse->length = *tmp;
        length++; tmp++;
    }

    if (isType(*tmp)) {
        strFormatParse->type = *tmp;
        strFormatParse->formatLength = length + 1;
    }

    return 0;
}

TStrFormatParse *createFormatParse() {
    TStrFormatFlagsInfo *flags = malloc(sizeof(TStrFormatFlagsInfo));
    flags->jail = 0;
    flags->zero = 0;
    flags->space = 0;
    flags->minus = 0;
    flags->plus = 0;
    TStrFormatParse *result = malloc(sizeof(TStrFormatParse));
    result->flags = flags;
    result->width = 0;
    result->precision = -1;
    result->length = 0;
    result->widthStar = 0;
    result->precisionStar = 0;
    result->type = 0;
    result->isIgnore = 0;
    result->formatLength = 0;

    return result;
}

void freeFormatParse(TStrFormatParse* formatParse) {
    free(formatParse->flags);
    free(formatParse);
}