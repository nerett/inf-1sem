#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <algorithm.h>

int cmp_char(const void* p1, const void* p2);

int main()
{
	int N = 0;
	//scanf("%d", &N );
	//char* the_array = NULL;
	//= ( char* )calloc( N, sizeof( char ) );
	char the_array[1000];
	char buffer = 0;
	//scanf( "%s", the_array );
	//int N = strlen( the_array );

	for( int i = 0; i < 1000; i++ )
	{
		scanf("%c", &buffer );
		if( buffer == '.' )
		{
			N = i;
			break;
		}
		the_array[i] = buffer;
	}

	qsort( the_array, N, sizeof( char ), cmp_char );


	for( int i = 0; i < N; i++ )
	{
		printf("%c", the_array[i] );
	}
	printf( "." );
	//free( the_array );
	return 0;
}

int cmp_char(const void * p1, const void * p2)
{
	char first = *( const char* )( p1 );
	char second = *( const char* )( p2 );
	return first - second;
}
