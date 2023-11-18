#include "../shared/str_format_parser.h"
#include <stdarg.h>

typedef struct {
    int isSuccessReadArg;
    char* value;
} TGetValueFromArg;

typedef TGetValueFromArg(*TGetValueFromArgStrategy)(TStrFormatParse* PFormat, va_list *args);

TGetValueFromArgStrategy getValueFromArgStrategyBySpecifier(char specifier);