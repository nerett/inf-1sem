#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int change_pos(char *some_string);

int main()
{
    char *input_string = NULL;

    scanf("%m[^\n]", &input_string);
    int length = strlen(input_string);

    //input_string[length + 1] = '\0';

    for (int i = 0; i <= length; i++) {
        char s = input_string[i];
        if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z')) {
            i += change_pos(input_string + i);
        }
    }


    printf("%s", input_string);
    free(input_string);

    return 0;
}

int change_pos(char *some_string)
{
    int j = 0;
    while ((some_string[j] >= 'A' && some_string[j] <= 'Z')
           || (some_string[j] >= 'a' && some_string[j] <= 'z')) {
        j++;
    }
    int size = j - 1;

    for (int k = 0; k <= size / 2; k++) {
        char buffer = some_string[size - k];
        some_string[size - k] = some_string[k];
        some_string[k] = buffer;
    }

    return size;
}
