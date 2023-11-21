char* s21_itoa(long int value, char* buffer, int base);
void s21_ftoa(long double n, char* res, int afterpoint);
char* s21_uitoa(unsigned long int value, char* buffer, int base);
char* repeat(char sym, int count);
char* append(char* dest, char* append);
char* prepend(char* dest, char* append);
char* strWidth(char* str, int width, char sym, int isRight);