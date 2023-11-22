#include "main.h"

int main() {
    Suite *str, *sprintf;
    SRunner *strsr, *sprintfsr;
    int nfailed;

    str = string_suite();
    sprintf = sprintf_suite();
    strsr = srunner_create(str);
    sprintfsr = srunner_create(sprintf);
    srunner_run_all(strsr, CK_NORMAL);
    srunner_run_all(sprintfsr, CK_NORMAL);
    nfailed = srunner_ntests_failed(strsr);
    nfailed += srunner_ntests_failed(sprintfsr);
    srunner_free(strsr);
    srunner_free(sprintfsr);
    return nfailed != 0;
}
