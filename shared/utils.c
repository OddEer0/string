#include "./utils.h"
#include <stdlib.h>
#include "../s21_string.h"

long int labs(long int x) {
    return x < 0 ? -x : x;
}

long long llabs(long long int x) {
    return x < 0 ? -x : x;
}

long long ldfloor(long double x) {
    return (long long)x;
}

long double getMantis(long double x) {
    return x - ldfloor(x);
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
    int isNegative = x < 0;

    long long $value = llabs(x);

    for (long long int j = $value; j; j /= 10, i++)
        str[i] = (j % 10) + '0';
 
    for (; i < afterpoint; i++) 
        str[i] = '0';

    if (isNegative)
        str[i++] = '-'; 
 
    reverse(str, 0, i - 1);
    str[i] = '\0';
    return i; 
} 
 
void s21_ftoa(long double value, char* buff, int afterpoint) {
    long long decimalPart = ldfloor(value);
    long double mantisPart = getMantis(value);
    int length = 0;
    char temp[40] = "";
    buff[0] = '\0';

    if (afterpoint > 0) {
        length++;
        temp[0] = '.';
        int beforeResetCount = 0, $afterpoint = afterpoint;
        for (int i = 0; i < afterpoint; i++, beforeResetCount++) {
            mantisPart *= 10.0;

            if (beforeResetCount >= 5) {
                beforeResetCount = -1;

                intToStr((long long)mantisPart, temp + length, 6);
                length += 6;
                $afterpoint -= 6;
                mantisPart = getMantis(mantisPart);
            }
        }
        int isRound = 0;
        if (ldfloor(mantisPart * 10) % 10 >= 5)
            isRound = 1;
        if (beforeResetCount) {
            intToStr((long long)mantisPart, temp + length, $afterpoint);
            length += beforeResetCount;
        }

        for (int i = length - 1; i && isRound; i--) {
            temp[i]++;
            if (temp[i] > '9')
                temp[i] = '0';
            else
                isRound = 0;
        }

        if (isRound)
            decimalPart++;
    }

    intToStr(decimalPart, buff, 0);

    s21_strncat(buff, temp, length);
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