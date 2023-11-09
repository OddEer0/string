#include "../s21_string.h"

size_t strlen(const char *str) {
    size_t result = 0;
    char* tmp = (char*)str;

    while(tmp != '\0') {
        result++;
    }

    return result;
}

char *strncat(char *dest, const char *src, size_t n) {
    size_t destLength = strlen((const char*)dest);
    char* tmp = (char*) src;

    for (int i = 0; tmp != '\0' || i < n; i++, tmp++, destLength++)
        dest[destLength] = tmp;
    dest[destLength] = '\0';

    return dest;
}

char *strchr(const char *str, int c) {
    char *result = NULL;
    char *tmp = (char*)str;

    while(tmp != '\0' && result == NULL) {
        if (*tmp == c) {
            result = tmp;
        tmp++;
    }

    return result;
}
