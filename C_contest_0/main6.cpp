#include <stdlib.h>
#include <stdio.h>
//#include <algorithm.h>

int cmp_int(const void* p1, const void* p2);

int main()
{
	int N = 0;
	scanf("%d", &N );
	int* int_array = ( int* )calloc( N, sizeof( int ) );

	for( int i = 0; i < N; i++ )
	{
		scanf("%d", &int_array[i] );
	}

	qsort( int_array, N, sizeof( int ), cmp_int );

	for( int i = 0; i < N; i++ )
	{
		printf("%d ", int_array[i] );
	}

	free( int_array );
	return 0;
}

int cmp_int(const void * p1, const void * p2)
{
	int first = *( const int* )( p1 );
	int second = *( const int* )( p2 );
	return -1 * ( first - second );
}
