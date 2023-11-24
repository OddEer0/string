#include <stdio.h>
#include <stdlib.h>

int main() {
    char buff[] = "leagueoflegend";
    char format[] = "%[leagueof]";
    char value[200];
    int result = sscanf(buff, format, &value);

    printf("result: %d %s", result, value);
    printf("\n");

    return 0;
}
