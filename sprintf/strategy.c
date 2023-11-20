#include "./strategy.h"
#include "../s21_string.h"
#include <stdlib.h>
#include "../shared/utils.h"

// TODO - Сделать обработку длины
TGetValueFromArg DecimalStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {S21_NULL, 0};
    char buff[30];
    s21_itoa(va_arg(*args, int), buff, 10);
    s21_size_t length = s21_strlen(buff);
    result.value = calloc(length + 1, sizeof(char));
    result.value[0] = '\0';
    s21_strncpy(result.value, buff, length);
    result.length = length;
    return result;
}


// TODO - Сделать обработку длины
TGetValueFromArg UnsignedDecimalStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {S21_NULL, 0};
    char buff[30];
    s21_uitoa(va_arg(*args, unsigned long int), buff, 10);
    s21_size_t length = s21_strlen(buff);
    result.value = calloc(length + 1, sizeof(char));
    result.value[0] = '\0';
    s21_strncpy(result.value, buff, length);
    result.length = length;
    return result;
}

// TODO - Сделать обработку длины
TGetValueFromArg CharStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {S21_NULL, 0};
    char arg = va_arg(*args, int);
    result.value = calloc(2, sizeof(char));
    result.value[0] = arg; result.value[1] = '\0';
    result.length = 1;
    return result;
}

// TODO - Сделать обработку длины
TGetValueFromArg StringStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {S21_NULL, 0};
    char *arg = va_arg(*args, char*);

    if (arg != S21_NULL) {
        s21_size_t length = PFormat->precision < 0 ? s21_strlen(arg) : PFormat->precision;
        result.value = calloc(length + 1, sizeof(char));
        s21_strncat(result.value, arg, length);
        result.length = length;
    } else if (arg == S21_NULL && (PFormat->precision >= 6 || PFormat->precision < 0)) {
        result.value = calloc(6 + 1, sizeof(char));
        s21_strncat(result.value, "(null)", 6);
        result.length = 6;
    } else {
        result.value = calloc(1, sizeof(char));
        result.value[0] = '\0';
        result.length = 0;
    }
    
    return result;
}

TGetValueFromArg PercentStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {S21_NULL, 1};
    result.value = calloc(2, sizeof(char));
    result.value[0] = '%'; result.value[1] = '\0';
    return result;
}

// TODO - Сделать обработку длины
// TODO - Сделать точность мантисы как в оригинальном до 34 цифр в мантисе. 
// На данном этапе последнее число мантисы не округляется. Происходит переполнение при определений точности
TGetValueFromArg FloatStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {S21_NULL, 0};
    char buff[50];
    s21_ftoa(va_arg(*args, double), buff, PFormat->precision);
    s21_size_t length = s21_strlen(buff);
    result.value = calloc(length + 1, sizeof(char));
    result.value[0] = '\0';
    s21_strncpy(result.value, buff, length);
    result.length = length;
    return result;
}

// TODO - Сделать обработку длины
TGetValueFromArg UnsignedHexadecimalStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {S21_NULL, 0};
    return result;
}

// TODO - Сделать обработку длины
TGetValueFromArg UnsignedUpperHexadecimalStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {S21_NULL, 0};
    return result;
}

// TODO - Сделать обработку длины
TGetValueFromArg UnsignedOctalStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {S21_NULL, 0};
    return result;
}

// TODO - Сделать обработку длины
TGetValueFromArg PointerStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {S21_NULL, 0};
    return result;
}

TGetValueFromArgStrategy getValueFromArgStrategyBySpecifier(char specifier) {
    TGetValueFromArgStrategy result = S21_NULL;

    switch(specifier) {
        case 'd':
            result = DecimalStrategy;
            break;
        case 'u':
            result = UnsignedDecimalStrategy;
            break;
        case 'c':
            result = CharStrategy;
            break;
        case 'f':
            result = FloatStrategy;
            break;
        case 's':
            result = StringStrategy;
            break;
        case '%':
            result = PercentStrategy;
            break;
        case 'p':
            result = PointerStrategy;
            break;
        case 'o':
            result = UnsignedOctalStrategy;
            break;
        case 'x':
            result = UnsignedHexadecimalStrategy;
            break;
        case 'X':
            result = UnsignedUpperHexadecimalStrategy;
            break;
        case 'e':
            result = S21_NULL;
            break;
        case 'E':
            result = S21_NULL;
            break;
        case 'g':
            result = S21_NULL;
            break;
        case 'G':
            result = S21_NULL;
            break;
    }

    return result;
}

void freeGetValueFromArg(TGetValueFromArg *arg) {
    if (arg->value) {
        free(arg->value);
    }
}