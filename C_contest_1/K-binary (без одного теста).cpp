#include <stdlib.h>
#include <stdio.h>

int abracadabra( int dec )
{
    int v;
    int answer = 0;
    v = 4096;

    for (int i = 1; i <= 13; i++)
    {
        if (dec >= v)
        {
            answer ++;
            dec -= v;
        }

        v /= 2;
    }

    return answer;
}

int main()
{
    int tested, answer;
    scanf("%d", &tested);

    answer = abracadabra(tested);

    printf("%d", answer);
    return 0;
}
 
