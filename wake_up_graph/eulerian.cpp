#include <stdlib.h>
#include <stdio.h>

int main()
{
	int N = 0;
	scanf( "%d", &N );

	int graph[100][100] = {};


	for( int i = 0; i < N; i++ )
	{
		for( int j = 0; j < N; j++ )
		{
			scanf( "%d", &graph[i][j] );
		}
	}

/*
	printf( " \n " );
	for( int i = 0; i < N; i++ )
	{
		for( int j = 0; j < N; j++ )
		{
			printf( "%d ", graph[i][j] );
		}
		printf( "\n" );
	}
*/

	int pow[100] = {};

	for( int i =0; i < N; i++ )
	{
		for( int j = i; j < N; j++ )
		{
			if( i == j )
			{
				continue;
			}

			pow[i] += graph[i][j];
			pow[j] += graph[i][j];
		}
	}

/*
	printf( "\n" );
	for( int i = 0; i < N; i++ )
	{
		printf( "%d ", pow[i] );
	}
	printf( "\n" );
*/


/*
	for( int i =0; i < N; i++ )
	{
		pow[i] /= 4;
	}
*/
	//int P = 0;
	for( int i = 0; i < N; i++ )
	{
		if( pow[i] )
		{
			//printf("i = %d, pow = %d\n", i, pow[i] );
			if( ( pow[i] % 2 ) != 0 )
			{
				printf( "NO\n" );
				return 0;
			}
			//P++;
		}
	}

	if( true ) //P >= 2
	{
		printf( "YES\n" );
	}
	/*
	printf( " \n " );
	for( int i = 0; i < N; i++ )
	{
		for( int j = 0; j < N; j++ )
		{
			printf( "%d ", graph[i][j] );
		}
		printf( "\n" );
	}
	*/
	return 0;
}
