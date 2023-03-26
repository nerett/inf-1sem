#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0;


    scanf( "%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3 );


    double a = sqrt( ( x3 - x2 )*( x3 - x2 ) + ( y3 - y2 )*( y3 - y2 ) );
    double b = sqrt( ( x3 - x1 )*( x3 - x1 ) + ( y3 - y1 )*( y3 - y1 ) );
    double c = sqrt( ( x1 - x2 )*( x1 - x2 ) + ( y1 - y2 )*( y1 - y2 ) );

	double sum = a + b + c;


    printf( "%lf %lf\n", ( a*x1 + b*x2 + c*x3 ) / sum, ( a*y1 + b*y2 + c*y3 ) / sum );

    return 0;
}
