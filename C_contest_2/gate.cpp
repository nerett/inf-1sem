#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int x = 0, y = 0;
    char word[50] = { };
    int value = 0;

    while (1) {
        scanf("%s", word);
        if (!strcmp(word, "Treasure!"))
            break;

        scanf("%d", &value);

        if (!strcmp(word, "North"))
            y += value;
        else if (!strcmp(word, "South"))
            y -= value;
        else if (!strcmp(word, "East"))
            x += value;
        else if (!strcmp(word, "West"))
            x -= value;
    }

    printf("%d %d\n", x, y);
    return 0;
}
