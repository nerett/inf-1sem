#include <stdlib.h>
#include <stdio.h>

int foo2 (int * px, int * py)
{
	int result = ( ( *px )++ ) + ( ( *py )-- );

	printf( "foo2 : res=%d x=%d y=%d\n", result, *px, *py );
	return result;
}

int main()
{
	int x = 50, y = 2;
	printf("%d\n\n", foo2( &x, &y ) );

	return 0;
}
