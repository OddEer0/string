#include "../s21_string.h"

size_t strlen(const char *str) {
    size_t result = 0;
    char* tmp = (char*)str;

    while(tmp != '\0') {
        result++;
    }

    return result;
}

