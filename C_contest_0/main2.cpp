#include <stdlib.h>
#include <stdio.h>

int main()
{
	int a[3], b[3], c[3];
	for( int i = 0; i < 3; i++ )
	{
		scanf("%d", &a[i] );
	}
	for( int i = 0; i < 3; i++ )
	{
		scanf("%d", &b[i] );
	}
	for( int i = 0; i < 3; i++ )
	{
		scanf("%d", &c[i] );
	}

	for( int i = 0; i < 3; i++ )
	{
		printf( "%d ", a[i] );
	}
	printf( "\n" );
	for( int i = 0; i < 3; i++ )
	{
		printf("%d ", b[i] );
	}
	printf( "\n" );
	for( int i = 0; i < 3; i++ )
	{
		printf("%d ", c[i] );
	}
	return 0;
}
