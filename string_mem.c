#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *w = (const unsigned char *)str;
  void *result = (void *)0;
  while (n && !result) {
    if ((unsigned char)c == *w) {
      result = (void *)w;
    }
    --n;
    ++w;
  }
  return result;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  if (n != 0) {
    const unsigned char *s1 = str1, *s2 = str2;
    while (n-- != 0)
      if (*s1++ != *s2++) {
        result = *--s1 - *--s2;
        break;
      }
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *d = (char *)dest;
  const char *s = (const char *)src;
  for (; n != 0; d++, s++, n--) {
    (*d) = (*s);
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *tmp = str;
  while (n--) {
    *tmp++ = (char)c;
  }
  return str;
}