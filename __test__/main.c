#include "check.h"
#include "../s21_string.h"
#include "string.h"

START_TEST(strlen_testing) {
    char value[] = "text";
    ck_assert_uint_eq(strlen(value), s21_strlen(value));
}
END_TEST

START_TEST(strchr_testing) {
    char value[] = "league of legend wild rift";
    ck_assert_int_eq(*strchr(value, 'w'), *s21_strchr(value, 'w'));
}
END_TEST

START_TEST(strrchr_testing) {
    char value[] = "league of legend wild rift";
    ck_assert_int_eq(*strrchr(value, 'e'), *s21_strrchr(value, 'e'));
}
END_TEST

START_TEST(strncmp_testing) {
    char value[] = "league of legend wild rift";
    char value2[] = "league of legend wild rift";
    int n = 30;
    ck_assert_int_eq(strncmp(value, value2, n), s21_strncmp(value, value2, n));
}
END_TEST

START_TEST(strncat_testing) {
    char value[50] = "league of legend wild rift";
    char value2[50] = "league of legend wild rift";
    char valueSrc[] = "all line";
    int valueN = 8;
    ck_assert_str_eq(strncat(value, valueSrc, valueN), s21_strncat(value2, valueSrc, valueN));
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
