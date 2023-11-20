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
 
    buffer[i] = '\0';
 
    return reverse(buffer, 0, i - 1);
}