#include "./index.h"
#include "../shared/utils.h"
#include <stdlib.h>

#include <stdio.h>

void sprintfPlusSpaceFlag(TGetValueFromArg* arg, TStrFormatParse *PFormat) {
    int isCorrectFlags = !!s21_strchr("d", PFormat->type) && (PFormat->flags->plus || PFormat->flags->space);
    int isNegative = arg->value[0] == '-';
    
    if (!isNegative && isCorrectFlags) {
        char signedChar = PFormat->flags->plus ? '+' : ' ';
        arg->length++;
        char *modifyValue = calloc(arg->length + 2, sizeof(char));
        modifyValue[0] = signedChar; modifyValue[1] = '\0';
        s21_strncat(modifyValue, arg->value, arg->length);
        free(arg->value);
        arg->value = modifyValue;
    }
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
    TGetValueFromArg arg = getValueFromArg(PFormat, args);

    sprintfPlusSpaceFlag(&arg, PFormat);
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