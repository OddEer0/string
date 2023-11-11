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
    int n = 27;
    ck_assert_int_eq(strncmp(value, value2, n), s21_strncmp(value, value2, n));
    ck_assert_int_eq(strncmp(value, value2, 6), s21_strncmp(value, value2, 6));
    ck_assert_int_eq(strncmp(value, value3, 6), s21_strncmp(value, value3, 6));
    ck_assert_int_eq(strncmp(value, value3, n), s21_strncmp(value, value3, n));
    ck_assert_int_eq(strncmp(value3, value, n), s21_strncmp(value3, value, n));
    ck_assert_int_eq(strncmp(value3, value4, n - 10), s21_strncmp(value3, value4, n - 10));
    ck_assert_int_eq(strncmp(value4, value3, n - 10), s21_strncmp(value4, value3, n - 10));
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
    ck_assert_str_eq(strncat(value3, valueSrc, valueN + 3), s21_strncat(value4, valueSrc, valueN + 3));
    ck_assert_str_eq(strncat(value3, valueSrc, valueN - 3), s21_strncat(value4, valueSrc, valueN - 3));
}
END_TEST

START_TEST(strncpy_testing) {
    char value[100] = "";
    char value2[100] = "";
    char valueSrc[] = "all stars";
    int valueN = 9;
    ck_assert_str_eq(strncpy(value, valueSrc, valueN), s21_strncpy(value2, valueSrc, valueN));
    char value3[100] = "lolxdlolxd ";
    char value4[100] = "lolxdlolxd ";
    ck_assert_str_eq(strncpy(value3, valueSrc, valueN), s21_strncpy(value4, valueSrc, valueN));
    ck_assert_str_eq(strncpy(value3, valueSrc, valueN + 3), s21_strncpy(value4, valueSrc, valueN + 3));
    ck_assert_str_eq(strncpy(value3, valueSrc, valueN - 3), s21_strncpy(value4, valueSrc, valueN - 3));
    char value5[36] = "league of legend wild rift";
    char value6[36] = "league of legend wild rift";
    ck_assert_str_eq(strncpy(value5, valueSrc, valueN), s21_strncpy(value6, valueSrc, valueN));
}
END_TEST

START_TEST(strcspn_testing) {
    char value[] = "league of legend wild rift";
    char exceptions[] = "eu";
    ck_assert_uint_eq(strcspn(value, exceptions), s21_strcspn(value, exceptions));
    ck_assert_uint_eq(strcspn(value, "v"), s21_strcspn(value, "v"));
    ck_assert_uint_eq(strcspn(value, " "), s21_strcspn(value, " "));
}
END_TEST

START_TEST(strstr_testing) {
    char value[] = "league of legend wild rift";
    char search[] = "of";
    ck_assert_str_eq(strstr(value, search), s21_strstr(value, search));
    ck_assert_ptr_null(strstr(value, "not"));
    ck_assert_ptr_null(s21_strstr(value, "not"));
    ck_assert_str_eq(strstr(value, "t"), s21_strstr(value, "t"));
    ck_assert_str_eq(strstr(value, "e"), s21_strstr(value, "e"));
    ck_assert_str_eq(strstr(value, " "), s21_strstr(value, " "));
    ck_assert_str_eq(strstr(value, " of"), s21_strstr(value, " of"));
}
END_TEST

START_TEST(strpbrk_testing) {
    char value[] = "league of legend wild rift";
    char searchs[] = "eu";
    ck_assert_str_eq(strpbrk(value, searchs), s21_strpbrk(value, searchs));
    ck_assert_str_eq(strpbrk(value, "t"), s21_strpbrk(value, "t"));
    ck_assert_str_eq(strpbrk(value, "fo"), s21_strpbrk(value, "fo"));
    ck_assert_ptr_null(strpbrk(value, "k"));
    ck_assert_ptr_null(s21_strpbrk(value, "k"));
}
END_TEST

Suite *string_suite() {
    TCase *strlen, *strchr, *strrchr, *strncmp, *strncat, *strncpy, *strcspn, *strstr, *strpbrk;
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

    strncpy = tcase_create("strncpy");
    tcase_add_test(strncpy, strncpy_testing);
    suite_add_tcase(s, strncpy);

    strcspn = tcase_create("strcspn");
    tcase_add_test(strcspn, strcspn_testing);
    suite_add_tcase(s, strcspn);

    strstr = tcase_create("strstr");
    tcase_add_test(strstr, strstr_testing);
    suite_add_tcase(s, strstr);

    strpbrk = tcase_create("strstr");
    tcase_add_test(strpbrk, strpbrk_testing);
    suite_add_tcase(s, strpbrk);

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
