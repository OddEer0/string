#include "./strategy.h"
#include "../s21_string.h"

TGetValueFromArg IntStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {0, S21_NULL};
    return result;
}

TGetValueFromArg UnsignedIntStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {0, S21_NULL};
    return result;
}

TGetValueFromArg CharStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {0, S21_NULL};
    return result;
}

TGetValueFromArg StringStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {0, S21_NULL};
    return result;
}

TGetValueFromArg PercentStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {0, S21_NULL};
    return result;
}

TGetValueFromArg FloatStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {0, S21_NULL};
    return result;
}

TGetValueFromArg UnsignedHexadecimalStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {0, S21_NULL};
    return result;
}

TGetValueFromArg UnsignedUpperHexadecimalStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {0, S21_NULL};
    return result;
}

TGetValueFromArg UnsignedOctalStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {0, S21_NULL};
    return result;
}

TGetValueFromArg PointerStrategy(TStrFormatParse* PFormat, va_list *args) {
    TGetValueFromArg result = {0, S21_NULL};
    return result;
}

TGetValueFromArgStrategy getValueFromArgStrategyBySpecifier(char specifier) {
    TGetValueFromArgStrategy result = S21_NULL;

    switch(specifier) {
        case 'd':
            result = IntStrategy;
            break;
        case 'u':
            result = UnsignedIntStrategy;
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