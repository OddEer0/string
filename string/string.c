#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t result = 0;
    char* tmp = (char*)str;

    while(*tmp != '\0') {
        result++;
        tmp++;
    }

    return result;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    s21_size_t destLength = s21_strlen((const char*)dest);
    char* tmp = (char*) src;

    for (unsigned int i = 0; *tmp != '\0' || i < n; i++, tmp++, destLength++)
        dest[destLength] = *tmp;
    dest[destLength] = '\0';

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
    s21_size_t length1 = s21_strlen(str1), length2 = s21_strlen(str2);
    int result = 0;

    for (unsigned int i = 0, k = 0; i < n && !result && !k; i++) {
        if (i + 1 == length1 && i + 1 == length2)
            k = 1;
        
        if (i >= length2) {
            result = str1[i];
        } else if (i >= length1) {
            result = -str2[i];
        } else if (str1[i] > str2[i]) {
            result = str1[i];
        } else if (str1[i] < str2[i]) {
            result = -str2[i];
        }
    }

    return result;
}
