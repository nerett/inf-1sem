#include <stdlib.h>
#include <stdio.h>
//#include <algorithm.h>

int cmp_double(const void* p1, const void* p2);

int main()
{
	int N = 0;
	scanf("%d", &N );
	double* double_array = ( double* )calloc( N, sizeof( double ) );

	for( int i = 0; i < N; i++ )
	{
		scanf("%lg", &double_array[i] );
	}

	qsort( double_array, N, sizeof( double ), cmp_double );

	for( int i = 0; i < N; i++ )
	{
		printf("%.2lf ", double_array[i] );
	}

	free( double_array );
	return 0;
}

int cmp_double(const void * p1, const void * p2)
{
	double first = *( const double* )( p1 );
	double second = *( const double* )( p2 );
	if( first < second )
	{
		return -1;
	}
	else if( first > second )
	{
		return 1;
	}

	return 0;
}
