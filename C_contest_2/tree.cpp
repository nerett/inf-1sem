#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calc_j(int j, char *string)
{
    while ((string[j] >= '0' && string[j] <= '9') || (string[j] == '-')) {
        j++;
    }

    j--;
    return j;
}

double del_2(double return_value, int N)
{
    for (int i = 0; i < N; i++) {
        return_value /= 2;
    }

    return return_value;
}

long long convert_char(char *string)
{
    long long value = 0;
    sscanf(string, "%lld", &value);
    return value;
}

int main()
{
    char *string = NULL;
    scanf("%m[^\n]", &string);
    int length = strlen(string);

    double ans = 0;
    int open = 0;
    for (int j = 0; j <= length; j++) {
        if (string[j] == ')') {
            open--;
        }
        if (string[j] == '(') {
            open++;
        }

        if ((string[j] >= '0' && string[j] <= '9') || string[j] == '-') {
            ans += del_2(convert_char(string + j), open);
            j = calc_j(j, string);
        }
    }

    printf("%.2lf\n", ans);

    free(string);
}
