#include "./index.h"
#include "../shared/utils.h"
#include <stdlib.h>

#include <stdio.h>

void append(TGetValueFromArg* arg, char* append) {
    s21_size_t appendLength = s21_strlen(append);
    s21_size_t resLength = arg->length + appendLength;
    char *result = calloc(resLength + 1, sizeof(char));
    result[0] = '\0';
    s21_strncat(result, arg->value, arg->length);
    s21_strncat(result, append, appendLength);
    free(arg->value);
    arg->value = result;
    arg->length = resLength;
}

void prepend(TGetValueFromArg* arg, char* append) {
    s21_size_t appendLength = s21_strlen(append);
    s21_size_t resLength = arg->length + appendLength;
    char *result = calloc(resLength + 1, sizeof(char));
    result[0] = '\0';
    s21_strncat(result, append, appendLength);
    s21_strncat(result, arg->value, arg->length);
    free(arg->value);
    arg->value = result;
    arg->length = resLength;
}

void sprintfPrecision(TGetValueFromArg* arg, TStrFormatParse *PFormat) {
    int isNegative = arg->value[0] == '-';
    int isNum = !!s21_strchr("douxX", PFormat->type);
    int isFloat = !!s21_strchr("eEfgG", PFormat->type);
    
    if (isNum) {
        int length = arg->length - isNegative;
        int zeroCount = PFormat->precision - length;
        char *buff = repeat('0', zeroCount);
        if (buff) {
            prepend(arg, buff);
            free(buff);
        }
    }
}

void sprintfFlagHandle(TGetValueFromArg* arg, TStrFormatParse *PFormat) {
    int isCorrectFlags = !!s21_strchr("d", PFormat->type) && (PFormat->flags->plus || PFormat->flags->space);
    int isNegative = arg->value[0] == '-';
    int hasDot = !!s21_strchr(arg->value, '.');
    int isCorrectFlagDot = !!s21_strchr("aAeEfFgG", PFormat->type);
    
    if (!isNegative && isCorrectFlags)
        prepend(arg, PFormat->flags->plus ? "+" : " ");
    else if (!hasDot && isCorrectFlagDot)
        append(arg, ".");
    else if (PFormat->type == 'o')
        prepend(arg, "0");
    else if (PFormat->type == 'x')
        prepend(arg, "0x");
    else if (PFormat->type == 'X')
        prepend(arg, "0X");
}

void sprintfWidth(char* str, TGetValueFromArg* arg, TStrFormatParse *PFormat) {
    int width = PFormat->width - arg->length;
    width = width < 0 ? 0 : width;
    char widthSym = !PFormat->flags->minus && PFormat->flags->zero ? '0' : ' ';
    char* buff = repeat(widthSym, width);
    if (!PFormat->flags->minus)
        s21_strncat(str, buff, width);
    s21_strncat(str, arg->value, arg->length);
    if (PFormat->flags->minus)
        s21_strncat(str, buff, width);
    if (buff)
        free(buff);
}

int printProccess(char *str, TStrFormatParse *PFormat, va_list *args, TGetValueFromArgStrategy getValueFromArg) {
    PFormat->width = PFormat->widthStar ? va_arg(*args, int) : PFormat->width;
    PFormat->precision = PFormat->precisionStar ? va_arg(*args, int) : PFormat->precision < 0 ? 6 : PFormat->precision;
    TGetValueFromArg arg = getValueFromArg(PFormat, args);

    sprintfPrecision(&arg, PFormat);
    sprintfFlagHandle(&arg, PFormat);
    sprintfWidth(str,  &arg, PFormat);

    freeGetValueFromArg(&arg);
    return 1;
}

int s21_sprintf(char *str, const char *format, ...) {
    int result = 0;
    va_list args;
    va_start(args, format);
    str[0] = '\0';

    for (int i = 0; format[i] != '\0'; i++) {
        // TODO - вынести в переменную условие isFormat
        if (format[i] == '%') {
            TStrFormatParse *PFormat = createFormatParse();
            strFormatParser((char*)&format[i], PFormat);

            printProccess(str, PFormat, &args, getValueFromArgStrategyBySpecifier(PFormat->type));

            i += PFormat->formatLength;
            freeFormatParse(PFormat);
        } else {
            char buff[] = {format[i]};
            s21_strncat(str, buff, 1);
        }
    }

    va_end(args);
    return result;
}