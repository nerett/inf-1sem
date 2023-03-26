#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long a = 0, b = 0;
    int count = 0;

    scanf("%llu %llu", &a, &b);

    for (int i = 0; i < 64; i++) {
        int temp1 = a & 1;
        int temp2 = b & 1;

        if (temp1 == temp2) {
            count++;
        }

        a = a >> 1;
        b = b >> 1;
    }

    printf("%d\n", count);

    return 0;
}
