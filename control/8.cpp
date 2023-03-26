#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cmp_strings(const void *string_1_ptr, const void *string_2_ptr)
{
    char *first_string = *(char **) string_1_ptr;
    char *second_string = *(char **) string_2_ptr;

    int result = strcmp(first_string, second_string);   // это быстрее за счёт strcmp!

    if (result > 0) {
        return 1;
    } else if (result < 0) {
        return -1;
    }

    return 0;
}

int main()
{
    int N_strings;
    scanf("%d\n", &N_strings);

    char **index_string = (char **) calloc(N_strings, sizeof(char *));
    char *trash;

    for (int i = 0; i < N_strings; i++) {
        scanf("%m[^0-9 ]", &trash);
        scanf("%m[0-9 ]", &index_string[i]);
        free(trash);
    }

    qsort(index_string, N_strings, sizeof(char *), cmp_strings);


    for (int i = 0; i < N_strings; i++) {
        printf("%s\n", index_string[i]);
    }


    for (int i = 0; i < N_strings; i++) {
        free(index_string[i]);
    }
    free(index_string);
    return 0;
}
