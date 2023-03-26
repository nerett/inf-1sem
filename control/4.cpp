#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    unsigned long long int s = 0, k = 1, t = 0;

    scanf("%d", &n);

    for (int i = 0; i < (2 * n - 1); i++) {
        if (i % 4 != 0 && i != 0) {
            t = (i / 4) + 1;
        } else {
            t = i / 4;
        }

        k += t * 2;
        s += k;
    }

    printf("%llu", s);

    return 0;
}
