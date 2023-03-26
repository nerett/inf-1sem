#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

//#define MAXIMUM_DEBUG

const int INFINITY = INT32_MAX;

int main()
{
	int N = 0;
	scanf("%d", &N );

	int* A_time = ( int* )calloc( N, sizeof( int ) );
	int* B_time = ( int* )calloc( N, sizeof( int ) );
	int* C_time = ( int* )calloc( N, sizeof( int ) );

	for( int i = 0; i < N; i++ )
	{
		scanf("%d %d %d",  &A_time[i], &B_time[i], &C_time[i] );
	}

	int* queue = ( int* )calloc( N+2, sizeof( int ) ); //костыль
	for( int i = 0; i < N; i++ )
	{
		queue[i] = INFINITY;
	}


	if( true )
	{
		queue[0] = A_time[0];
	}
	if( queue[1] > B_time[0] )
	{
		queue[1] = B_time[0];
	}
	if( queue[2] > C_time[0] )
	{
		queue[2] = C_time[0];
	}

	for( int i = 1; i < N; i++ )
	{
		if( queue[i+0] > ( A_time[i] + queue[i-1] ) )
		{
			queue[i+0] = A_time[i] + queue[i-1];
		}

		if( ( N - i ) < 1 )
		{
			break;
		}

		if( queue[i+1] > ( B_time[i] + queue[i-1] ) )
		{
			queue[i+1] = B_time[i] + queue[i-1];
		}

		if( ( N - i ) < 2 )
		{
			break;
		}

		if( queue[i+2] > ( C_time[i] + queue[i-1] ) )
		{
			queue[i+2] = C_time[i] + queue[i-1];
		}
	}

	printf("%d\n", queue[N-1] );
	free( queue );
	free( A_time );
	free( B_time );
	free( C_time );
	return 0;
}
