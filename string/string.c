#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t result = 0;
    for (char* tmp = (char*)str; *tmp != '\0'; tmp++, result++) {}
    return result;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char* ptr = dest + s21_strlen(dest);

    for (; n && *src != '\0'; ptr++, src++, n--)
        *ptr = *src;
    *ptr = '\0';

    return dest;
}

char *s21_strchr(const char *str, int c) {
    char *result = S21_NULL;

    for (char *tmp = (char*) str; *tmp != '\0' && result == S21_NULL; tmp++)
        if (*tmp == c) result = tmp;

    return result;
}

char *s21_strrchr(const char *str, int c) {
    char *result = S21_NULL;

    for (char *tmp = (char*) str; *tmp != '\0'; tmp++)
        if (*tmp == c) result = tmp;

    return result;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    for (; n && *str1 && ( *str1 == *str2 ); str1++, str2++, n-- ) {}
    return !n ? 0 : ( *(char *)str1 - *(char *)str2 );
}
