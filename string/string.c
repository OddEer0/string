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

    for (char *tmp = (char*) str; tmp != '\0' && result == NULL; tmp++)
        if (*tmp == c) result = tmp;

    return result;
}

char *strrchr(const char *str, int c) {
    char *result = NULL;

    for (char *tmp = (char*) str; tmp != '\0'; tmp++)
        if (*tmp == c) result = tmp;

    return result;
}

int strncmp(const char *str1, const char *str2, size_t n) {
    size_t length1 = strlen(str1), length2 = strlen(str2);
    int result = 0;

    for (int i = 0, k = 0; i < n && !result && !k; i++) {
        if (i + 1 == length1 && i + 1 == length2) {
            k = 1;
        } 
        
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
