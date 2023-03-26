#include <stdlib.h>
#include <stdio.h>

int main()
{

	float a[5] = { 0, 1, 2, 3, 4 };
	float * p;

	p = ( float* )malloc( sizeof( a ) );
	for( int i = 0; i < 5; i++ )
	{
	    p[i] = a[i];
	}

	for( int i = 0; i < 5; i++ )
	{
		printf("%g\n", a[i] );
	}

	return 0;
}
