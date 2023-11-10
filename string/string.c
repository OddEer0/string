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

    for (char *tmp = (char*) str; *tmp != '\0' && !result; tmp++)
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

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    if (!dest) 
        return S21_NULL;

    char* tmp = dest;
    for (; *src != '\0' && n; n--, tmp++, src++)
        *tmp = *src;
    if (!*tmp || n) *tmp = '\0';
 
    return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t result = 0;

    for (char* tmp = (char*)str1, k = 0; *tmp != '\0' && !k; tmp++)
        if (!s21_strchr(str2, *tmp)) result++;
        else k = 1;

    return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
    char* result = S21_NULL;

    for (; *haystack != '\0' && !result; haystack++) {
        char *tmp1 = (char*)haystack, *tmp2 = (char*)needle;
        for (int isIdenty = 1; tmp1 && tmp2 && isIdenty && *haystack == *needle;) {
            if (*tmp1 != *tmp2 || *tmp1 == '\0') isIdenty = 0;
            if (isIdenty) tmp1++, tmp2++;
        }
        result = *tmp2 == '\0' ? (char*)haystack : S21_NULL;
    }
    
    return result;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    char* result = S21_NULL;

    for (char *tmp1 = (char*) str1; *tmp1 != '\0' && !result; tmp1++)
        for (char *tmp2 = (char*) str2; *tmp2 != '\0' && !result; tmp2++)
            if (*tmp1 == *tmp2) result = tmp1;

    return result;
}
