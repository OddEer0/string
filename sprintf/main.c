#include "../s21_string.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <wchar.h>


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

int intToStrr(long long int x, char str[], int afterpoint) { 
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

    printf("round: %d\n", isRound);

    for (int j = 0; j < i - 1 && isRound; j++) {
        str[j] += 1;
        if (str[j] > '9') {
            str[j] = '0';
        } else {
            isRound = 0;
        }
    }
 
    for (; i < afterpoint; i++) 
        str[i] = '0';

    if (isNegative)
        str[i++] = '-'; 
 
    reversee(str, 0, i - 2);
    str[i] = '\0';
    return i; 
} 

int main() {
    long double value = 3.0;
    long long ipart = (long long)value;
    long double fpart = value - ipart;
    for (int i = 0; i < 4; i++) {
        fpart *= 10.0;
    }
    char tmp[100] = "";

    intToStrr((long long)(fpart * 10.0), tmp, 1);

    printf("%s\n", tmp);

    return 0;
}