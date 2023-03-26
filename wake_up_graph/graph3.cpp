#include <stdlib.h>
#include <stdio.h>

int main()
{
	int N = 0, M = 0;
	scanf( "%d %d", &N, &M );

	int graph[100][100] = {};

	int value1 = 0, value2 = 0;
	for( int i = 0; i < M; i++ )
	{
		scanf("%d %d", &value1, &value2 );

		graph[value1][value2] = 1;
		graph[value2][value1] = 1;
	}

/*
	for( int i = 0; i < N; i++ )
	{
		for( int j = 0; j < N; j++ )
		{
			scanf( "%d", &graph[i][j] );
		}
	}
*/

	//printf( " \n " );
	for( int i = 0; i < N; i++ )
	{
		for( int j = 0; j < N; j++ )
		{
			printf( "%d ", graph[i][j] );
		}
		printf( "\n" );
	}

/*
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
*/

	return 0;
}
