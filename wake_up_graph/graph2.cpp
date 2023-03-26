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

	for( int i =0; i < N; i++ )
	{
		for( int j = i; j < N; j++ )
		{
			if( graph[i][j] )
			{
				printf( "%d %d\n", j, i );
			}
		}
	}
	return 0;
}
