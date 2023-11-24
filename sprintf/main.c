#include "../s21_string.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>


#define BUFF_SIZE 500

void swapp(char *x, char *y) {
    char t = *x; *x = *y; *y = t;
}

long long llabss(long long int x) {
    return x < 0 ? -x : x;
}
 
char* reversee(char *buffer, int i, int j) {
    while (i < j) {
        swapp(&buffer[i++], &buffer[j--]);
    }
 
    return buffer;
}

int mantisToStr(long long int x, char str[], int afterpoint, int* $isRound) { 
    int i = 0;
    int isNegative = x < 0;

    long long $value = llabss(x);
    long long int j = $value;
    int isRound = 0;

    for (long long int j = $value; j; j /= 10, i++) {
        if (!i) {
            int tmp = j % 10;
            if (tmp >= 5)
                isRound = 1;
        } else {
            str[i - 1] = (j % 10) + '0';
        }
    }


    for (int j = 0; j < i - 1 && isRound; j++) {
        str[j] += 1;
        if (str[j] > '9') {
            str[j] = '0';
        } else {
            isRound = 0;
        }
    }
    
    *$isRound = isRound;
 
    for (; i < afterpoint; i++) 
        str[i] = '0';

    if (isNegative)
        str[i++] = '-'; 
 
    reversee(str, 0, i - 2);
    str[i] = '\0';
    return i; 
}

int intToStrr(long long int x, char str[], int afterpoint) { 
    int i = 0;
    int isNegative = x < 0;

    long long $value = llabss(x);

    for (long long int j = $value; j; j /= 10, i++)
        str[i] = (j % 10) + '0';
 
    for (; i < afterpoint; i++) 
        str[i] = '0';

    if (isNegative)
        str[i++] = '-'; 
 
    reversee(str, 0, i - 1);
    str[i] = '\0';
    return i; 
} 

void s21_fftoa(long double n, char* res, int afterpoint) {
    long long ipart = (long long)n;
    int aftercopy = afterpoint;
    long double fpart = n - (long double)ipart;
 
    // int length = intToStr(ipart, res, 0);
    char temp[afterpoint + 1];
    int isRound = 0, tempEnd = 0;
 
    if (afterpoint != 0) { 

        long double tmp = 0.0;
        int tmpAfterpoint = afterpoint;
        int length = 0;
        for (int j = 0; j < tmpAfterpoint; j++) {
            if (tmp == 0.0) tmp = 10.0;
            else tmp *= 10.0;

            if (tmp >= 1000000.0) {
                fpart *= tmp;
                tempEnd = mantisToStr((long long)(fpart * 10), temp + length, 6, &isRound);
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

            tempEnd = mantisToStr((long long)(fpart * 10), temp + length, afterpoint, &isRound); 
        }

        if (isRound) {
            for (int end = aftercopy - tempEnd; end >= 0 && isRound; end--) {
                temp[end] += 1;
                if (temp[end] > '9') {
                    temp[end] = '0';
                } else {
                    isRound = 0;
                }
                printf("%c %d\n", temp[end], end);
            }
        }

        if (isRound)
            ipart++;
    }
    int resLength = intToStrr(ipart, res, 0);
    if (aftercopy != 0) {
        res[resLength] = '.';
        res[resLength + 1] = '\0';
        resLength++;

        strncat(res, temp, aftercopy);
    }
        
}

int main() {
    long double value = 3.9999;
    char tmp[100] = "";
    s21_fftoa(value, tmp, 7);

    printf("%s, %.7f\n", tmp, 3.9999);

    return 0;
}