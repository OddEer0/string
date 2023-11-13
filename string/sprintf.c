#include <stdarg.h>
#include <stdio.h>
#include "./str_format_parser.h"

int s21_sprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);

    char *tmp = (char*)format;
    for (; *tmp != '\0'; tmp++) {
        if (isFormat(*tmp)) {
            TStrFormatParse *PFormat = createFormatParse();
            strFormatParser(tmp, PFormat);

            printf("flags - jail: %d minus: %d plus: %d zero: %d space: %d\n", PFormat->flags->jail, PFormat->flags->minus, PFormat->flags->plus, PFormat->flags->zero, PFormat->flags->space);
            printf("width: %d isStar: %d\n", PFormat->width, PFormat->widthStar);
            printf("precision: %d isStar: %d\n", PFormat->precision, PFormat-> precisionStar);
            printf("length: %c\n", PFormat->length);
            printf("type: %c\n", PFormat->type);

            freeFormatParse(PFormat);
        }
    }

    va_end(args);
    return 0;
}

int main() {
    char buff[400];
    s21_sprintf(buff, "%d %#20.20f", 20, 14);

    return 0;
}