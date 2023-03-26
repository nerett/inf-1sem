#include <stdlib.h>
#include <stdio.h>

int main()
{
    double x1 = 0, x2 = 0 ,x3 = 0, y1 = 0, y2 = 0, y3 = 0;
    scanf( "%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3 );
    printf( "%lf %lf", (x1+x2+x3)/3, (y1+y2+y3)/3 );
    return 0;
}
