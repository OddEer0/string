#include "main.h"
#include "../s21_string.h"
#include "string.h"

#include <stdio.h>

START_TEST(d_specifier_testing) {
    char result[400];
    char result2[400];
    char result3[400];
    char result4[400];
    char format[] = "print: %d %hd %ld, %+d %+d % d %05d %0-5d %-5d %5d %.6d %1d";
    int printCount = sprintf(result, format, __INT_MAX__, __SHRT_MAX__, __LONG_MAX__, 2, 2, 2, 23, 23, 23, 23, 20, 1);
    int printCount2 = s21_sprintf(result2, format, __INT_MAX__, __SHRT_MAX__, __LONG_MAX__, 2, 2, 2, 23, 23, 23, 23, 20, 1);
    int printCount3 = sprintf(result3, format, -__INT_MAX__, -__SHRT_MAX__, -__LONG_MAX__, -2, -2, -2, -23, -23, -23, -23, -20, -1);
    int printCount4 = s21_sprintf(result4, format, -__INT_MAX__, -__SHRT_MAX__, -__LONG_MAX__, -2, -2, -2, -23, -23, -23, -23, -20, -1);
    ck_assert_str_eq(result, result2);
    ck_assert_str_eq(result3, result4);
    ck_assert_int_eq(printCount, printCount2);
    ck_assert_int_eq(printCount3, printCount4);
}
END_TEST

START_TEST(u_specifier_testing) {
    char result[400];
    char result2[400];
    char format[] = "print: %u %hu %lu, %+u %+u % u %05u %0-5u %-5u %5u %.6u";
    int printCount = sprintf(result, format, __INT16_MAX__, __INT32_MAX__, __INT64_MAX__, 2, 2, 2, 23, 23, 23, 23, 20);
    int printCount2 = s21_sprintf(result2, format, __INT16_MAX__, __INT32_MAX__, __INT64_MAX__, 2, 2, 2, 23, 23, 23, 23, 20);
    ck_assert_str_eq(result, result2);
    ck_assert_int_eq(printCount, printCount2);
}
END_TEST

START_TEST(x_specifier_testing) {
    char result[400];
    char result2[400];
    char format[] = "print: %x %hx %lx, %+x %+x % x %05x %0-5x %-5x %5x %.6x %#x";
    int printCount = sprintf(result, format, __INT16_MAX__, __INT32_MAX__, __INT64_MAX__, 2, 2, 2, 23, 23, 23, 23, 20, 222);
    int printCount2 = s21_sprintf(result2, format, __INT16_MAX__, __INT32_MAX__, __INT64_MAX__, 2, 2, 2, 23, 23, 23, 23, 20, 222);
    ck_assert_str_eq(result, result2);
    ck_assert_int_eq(printCount, printCount2);
}
END_TEST

START_TEST(X_specifier_testing) {
    char result[400];
    char result2[400];
    char format[] = "print: %X %hX %lX, %+X %+X % X %05X %0-5X %-5X %5X %.6X %#X";
    int printCount = sprintf(result, format, __INT16_MAX__, __INT32_MAX__, __INT64_MAX__, 2, 2, 2, 23, 23, 23, 23, 20, 2222);
    int printCount2 = s21_sprintf(result2, format, __INT16_MAX__, __INT32_MAX__, __INT64_MAX__, 2, 2, 2, 23, 23, 23, 23, 20, 2222);
    ck_assert_str_eq(result, result2);
    ck_assert_int_eq(printCount, printCount2);
}
END_TEST

START_TEST(o_specifier_testing) {
    char result[400];
    char result2[400];
    char format[] = "print: %o %ho %lo, %+o %+o % o %05o %0-5o %-5o %5o %.6o %#o";
    int printCount = sprintf(result, format, __INT16_MAX__, __INT32_MAX__, __INT64_MAX__, 2, 2, 2, 23, 23, 23, 23, 20, 222);
    int printCount2 = s21_sprintf(result2, format, __INT16_MAX__, __INT32_MAX__, __INT64_MAX__, 2, 2, 2, 23, 23, 23, 23, 20, 222);
    ck_assert_str_eq(result, result2);
    ck_assert_int_eq(printCount, printCount2);
}
END_TEST

Suite *sprintf_suite() {
    TCase *d_specifier, *u_specifier, *x_specifier, *X_specifier, *o_specifier;
    Suite *s = suite_create("sprintf");

    d_specifier = tcase_create("d specifier testing");
    tcase_add_test(d_specifier, d_specifier_testing);
    suite_add_tcase(s, d_specifier);

    u_specifier = tcase_create("u specifier testing");
    tcase_add_test(u_specifier, u_specifier_testing);
    suite_add_tcase(s, u_specifier);

    X_specifier = tcase_create("X specifier testing");
    tcase_add_test(X_specifier, X_specifier_testing);
    suite_add_tcase(s, X_specifier);

    x_specifier = tcase_create("x specifier testing");
    tcase_add_test(x_specifier, x_specifier_testing);
    suite_add_tcase(s, x_specifier);

    o_specifier = tcase_create("o specifier testing");
    tcase_add_test(o_specifier, o_specifier_testing);
    suite_add_tcase(s, o_specifier);

    return s;
}