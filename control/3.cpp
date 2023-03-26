#include <stdlib.h>
#include <stdio.h>

struct Point
{
    float x;
    float y;
};

int in_region(struct Point p)
{
	double calculated_y_red = -1 * ( p.x ) * ( p.x ) + 5;
	double calculated_y_blue = 1 / ( p.x + 4 ) - 4;

	//printf("%f\n", calculated_y_red );
	//printf("%f\n", calculated_y_blue );

	if( ( calculated_y_red > p.y ) && ( calculated_y_blue < p.y ) && ( p.y > -4 ) && ( p.x > -4 ) )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	Point p;
	p.x = -2.5;
	p.y = -3.5;
	printf("%d\n", in_region( p ) );
	return 0;
}
