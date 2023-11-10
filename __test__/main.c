#include "check.h"
#include "../s21_string.h"
#include "string.h"

START_TEST(strlen_testing) {
    char value[] = "text text";
    ck_assert_uint_eq(strlen(value), s21_strlen(value));
}
END_TEST

START_TEST(strchr_testing) {
    char value[] = "league of legend wild rift";
    ck_assert_int_eq(*strchr(value, 'w'), *s21_strchr(value, 'w'));
    ck_assert_ptr_eq(strchr(value, 'k'), s21_strchr(value, 'k'));
    ck_assert_ptr_null(s21_strchr(value, 'k'));
}
END_TEST

START_TEST(strrchr_testing) {
    char value[] = "league of legend wild rift";
    ck_assert_int_eq(*strrchr(value, 'e'), *s21_strrchr(value, 'e'));
    ck_assert_ptr_eq(strrchr(value, 'k'), s21_strrchr(value, 'k'));
    ck_assert_ptr_null(s21_strrchr(value, 'k'));
}
END_TEST

START_TEST(strncmp_testing) {
    char value[] = "league of legend wild rift";
    char value2[] = "league of legend wild rift";
    char value3[] = "league of legend";
    char value4[] = "league legend";
    int n = 30;
    ck_assert_int_eq(strncmp(value, value2, n), s21_strncmp(value, value2, n));
    ck_assert_int_eq(strncmp(value, value2, 6), s21_strncmp(value, value2, 6));
    ck_assert_int_eq(strncmp(value, value3, 6), s21_strncmp(value, value3, 6));
    ck_assert_int_eq(strncmp(value, value3, n), s21_strncmp(value, value3, n));
    ck_assert_int_eq(strncmp(value3, value, n), s21_strncmp(value3, value, n));
    ck_assert_int_eq(strncmp(value3, value4, n), s21_strncmp(value3, value4, n));
    ck_assert_int_eq(strncmp(value4, value3, n), s21_strncmp(value4, value3, n));
}
END_TEST

START_TEST(strncat_testing) {
    char value[36] = "league of legend wild rift";
    char value2[36] = "league of legend wild rift";
    char valueSrc[] = "all stars";
    int valueN = 9;
    ck_assert_str_eq(strncat(value, valueSrc, valueN), s21_strncat(value2, valueSrc, valueN));
    char value3[100] = "lolxdlolxd";
    char value4[100] = "lolxdlolxd";
    ck_assert_str_eq(strncat(value3, valueSrc, valueN), s21_strncat(value4, valueSrc, valueN));
    ck_assert_str_eq(strncat(value3, valueSrc, valueN + 1), s21_strncat(value4, valueSrc, valueN + 1));
    char value5[100] = "lolxdlolxd";
    char value6[100] = "lolxdlolxd";
    ck_assert_str_eq(strncat(value5, valueSrc, valueN - 3), s21_strncat(value6, valueSrc, valueN - 3));
}
END_TEST

Suite *string_suite() {
    TCase *strlen, *strchr, *strrchr, *strncmp, *strncat;
    Suite *s = suite_create("String");

    strlen = tcase_create("strlen");
    tcase_add_test(strlen, strlen_testing);
    suite_add_tcase(s, strlen);

    strchr = tcase_create("strchr");
    tcase_add_test(strchr, strchr_testing);
    suite_add_tcase(s, strchr);

    strrchr = tcase_create("strrchr");
    tcase_add_test(strrchr, strrchr_testing);
    suite_add_tcase(s, strrchr);

    strncmp = tcase_create("strncmp");
    tcase_add_test(strncmp, strncmp_testing);
    suite_add_tcase(s, strncmp);

    strncat = tcase_create("strncat");
    tcase_add_test(strncat, strncat_testing);
    suite_add_tcase(s, strncat);

    return s;
}

int main() {
    Suite *s;
    SRunner *sr;
    int nfailed;

    s = string_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    nfailed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return nfailed != 0;
}
