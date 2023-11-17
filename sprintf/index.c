#include "./index.h"

int s21_sprintf(char *str, const char *format, ...) {
    int result = 0;
    va_list args;
    va_start(args, format);
    str[0] = '\0';

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            TStrFormatParse *PFormat = createFormatParse();
            strFormatParser((char*)&format[i], PFormat);

            // Code

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