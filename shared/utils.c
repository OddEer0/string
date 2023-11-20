#include "./utils.h"
#include <stdlib.h>
#include "../s21_string.h"

#include <stdio.h>

void swap(char *x, char *y) {
    char t = *x; *x = *y; *y = t;
}
 
char* reverse(char *buffer, int i, int j) {
    while (i < j) {
        swap(&buffer[i++], &buffer[j--]);
    }
 
    return buffer;
}

char* s21_itoa(long int value, char* buffer, int base) {
    if (base < 2 || base > 32) {
        return buffer;
    }
 
    int n = abs((int)value);
 
    int i = 0;
    while (n) {
        int r = n % base;
 
        if (r >= 10) {
            buffer[i++] = 65 + (r - 10);
        }
        else {
            buffer[i++] = 48 + r;
        }
 
        n = n / base;
    }
 
    if (i == 0) {
        buffer[i++] = '0';
    }
 
    if (value < 0 && base == 10) {
        buffer[i++] = '-';
    }
 
    buffer[i] = '\0';
 
    return reverse(buffer, 0, i - 1);
}

char *repeat(char sym, int count) {
    if (count <= 0)
        return S21_NULL;
    char* result = calloc(count + 1, sizeof(char));

    for (int i = 0; i < count; i++)
        result[i] = sym;
    result[count] = '\0';

    return result;
}

int intToStr(long long x, char str[], int d) { 
    int i = 0; 
    while (x) { 
        str[i++] = (x % 10) + '0'; 
        x /= 10; 
    } 
 
    while (i < d) 
        str[i++] = '0'; 
 
    reverse(str, 0, i - 1);
    str[i] = '\0';
    return i; 
} 
 
void s21_ftoa(double n, char* res, int afterpoint) { 
    long long ipart = (int)n; 
 
    long double fpart = (long double)n - (long double)ipart; 
 
    long long i = intToStr(ipart, res, 0); 
 
    if (afterpoint != 0) { 
        res[i] = '.';
 
        long double tmp = 10.0;
        for (int j = 0; j < afterpoint - 1; j++)
            tmp *= 10.0;

        fpart *= tmp; 
 
        intToStr((long long)fpart, res + i + 1, afterpoint); 
    } 
}

char* s21_uitoa(unsigned long int value, char* buffer, int base) {
    if (base < 2 || base > 32) {
        return buffer;
    }
 
    unsigned long int n = value;
 
    int i = 0;
    while (n) {
        unsigned long int r = n % base;
 
        if (r >= 10) {
            buffer[i++] = 65 + (r - 10);
        }
        else {
            buffer[i++] = 48 + r;
        }
 
        n = n / base;
    }
 
    if (i == 0) {
        buffer[i++] = '0';
    }
 
    buffer[i] = '\0';
 
    return reverse(buffer, 0, i - 1);
}

char* append(char* dest, char* append) {
    s21_size_t appendLength = s21_strlen(append);
    s21_size_t destLength = s21_strlen(dest);
    s21_size_t resLength = destLength + appendLength;
    char *result = calloc(resLength + 1, sizeof(char));
    result[0] = '\0';
    s21_strncat(result, dest, destLength);
    s21_strncat(result, append, appendLength);
    free(dest);
    return result;
}

char* prepend(char* dest, char* append) {
    s21_size_t appendLength = s21_strlen(append);
    s21_size_t destLength = s21_strlen(dest);
    s21_size_t resLength = destLength + appendLength;
    char *result = calloc(resLength + 1, sizeof(char));
    result[0] = '\0';
    s21_strncat(result, append, appendLength);
    s21_strncat(result, dest, destLength);
    free(dest);
    return result;
}

char* strWidth(char* str, int width, char sym, int isRight) {
    s21_size_t length = s21_strlen(str);
    width = width - length;
    width = width < 0 ? 0 : width;

    char* buff = repeat(sym, width);
    char* result = calloc(length + width + 1, sizeof(char));
    result[0] = '\0';

    if (!isRight)
        s21_strncat(result, buff, width);
    s21_strncat(result, str, length);
    if (isRight)
        s21_strncat(result, buff, width);

    if (buff)
        free(buff);

    free(str);

    return result;
}