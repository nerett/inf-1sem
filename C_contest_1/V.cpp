#include <stdlib.h>
#include <stdio.h>

int func_hyper(float x, float y)
{
	float red_y = 1 / ( x + 4 ) - 3;
	float green_y = -2;

	if( ( x > -4 ) && ( y >= green_y ) && ( y>= red_y ) ) //! у гиперв=болы две ветви
	{
		return 1;
	}

	return 0;
}

int main()
{
	float x = 0, y = 0;
	scanf( "%f %f", &x, &y );
	printf("%d\n", func_hyper( x, y ) );

	return 0;
}
