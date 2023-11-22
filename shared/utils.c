#include "./utils.h"
#include <stdlib.h>
#include "../s21_string.h"

#include <stdio.h>

long int labs(long int x) {
    return x < 0 ? -x : x;
}

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
 
    long $value = labs(value);
 
    int i = 0;
    for (;$value; i++) {
        int remainder = $value % base;
 
        if (remainder >= 10)
            buffer[i] = 65 + (remainder - 10);
        else
            buffer[i] = 48 + remainder;
 
        $value /= base;
    }
 
    if (i == 0)
        buffer[i++] = '0';
 
    if (value < 0 && base == 10)
        buffer[i++] = '-';
 
    buffer[i] = '\0';
 
    return reverse(buffer, 0, i - 1);
}

char* s21_uitoa(unsigned long int value, char* buffer, int base) {
    if (base < 2 || base > 32) {
        return buffer;
    }
 
    unsigned long $value = value;
 
    int i = 0;
    for (;$value; i++) {
        int remainder = $value % base;
 
        if (remainder >= 10)
            buffer[i] = 65 + (remainder - 10);
        else
            buffer[i] = 48 + remainder;
 
        $value /= base;
    }
 
    if (i == 0)
        buffer[i++] = '0';
 
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

int intToStr(long long int x, char str[], int afterpoint) { 
    int i = 0; 
    for (long long int j = x; j; j /= 10, i++)
        str[i] = (j % 10) + '0';
 
    for (; i < afterpoint; i++) 
        str[i] = '0'; 
 
    reverse(str, 0, i - 1);
    str[i] = '\0';
    return i; 
} 
 
void s21_ftoa(long double n, char* res, int afterpoint) {
    long long ipart = (long long)n;

    printf("%lld\n", ipart);
 
    long double fpart = n - (long double)ipart;
 
    int length = intToStr(ipart, res, 0); 
 
    if (afterpoint != 0) { 
        res[length] = '.';
        length++;

        long double tmp = 0.0;
        int tmpAfterpoint = afterpoint;
        for (int j = 0; j < tmpAfterpoint; j++) {
            if (tmp == 0.0) tmp = 10.0;
            else tmp *= 10.0;

            if (tmp >= 1000000.0) {
                fpart *= tmp;
                intToStr((int)fpart, res + length, 6);
                length += 6;
                fpart -= (int)fpart;
                afterpoint -= 6;
                tmp = 0.0;
            }
        }

        if (tmp != 0.0) {
            tmp = 10.0;
            for (int i = 0; i < afterpoint - 1; i++)
                tmp *= 10.0;
            fpart *= tmp;

            printf("%Lf\n", fpart);
    
            intToStr((long int)fpart, res + length, afterpoint); 
        }
    } 
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