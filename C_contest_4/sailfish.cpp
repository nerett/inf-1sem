#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define MAXIMUM_DEBUG

const int INFINITY = INT32_MAX;

int main()
{
	int N = 0;
	scanf("%d", &N );
	int* data_array = ( int* )calloc( (N+2)*3, sizeof( int ) );//костыль

	for( int i = 0; i < N*3; i += 3 )
	{
		scanf("%d %d %d",  &data_array[i+0], &data_array[i+1], &data_array[i+2] );
	}


#ifdef MAXIMUM_DEBUG

	printf( "input:\n" );
	for( int i = 0; i < N*3; i += 3 )
	{
		printf("%d %d %d\n",  data_array[i+0], data_array[i+1], data_array[i+2] );
	}

	printf("dataline: ");
	for( int i = 0; i < N*3; i ++ )
	{
		printf("%d ",  data_array[i] );
	}
	printf("\n");

#endif


	int* queue = ( int* )calloc( N+2, sizeof( int ) ); //костыль

	for( int i = 0; i < N; i++ )
	{
		queue[i] = INFINITY;
	}


#ifdef MAXIMUM_DEBUG

	for( int i = 0; i < N; i++ )
	{
		printf("%d ", queue[i] );
	}
	printf( "\n" );

#endif


	if( true )
	{
		queue[0] = data_array[0*3+0];
	}
	if( queue[1] > data_array[1*3+1] )
	{
		queue[1] = data_array[0*3+1];
	}
	if( queue[2] > data_array[2*3+2] )
	{
		queue[2] = data_array[0*3+2];
	}

	for( int i = 1; i < N; i++ )
	{
		#ifdef MAXIMUM_DEBUG

			printf("iteration=%d: ", i);
			for( int i = 0; i < N; i++ )
			{
				printf("%d ", queue[i] );
			}
			printf("\n");

		#endif


		if( queue[i+0] > data_array[i*3+0] )
		{
			queue[i+0] = data_array[i*3+0] + queue[i-1];
		}

		if( ( N - i ) < 1 )
		{
			break;
		}

		if( queue[i+1] > data_array[i*3+1] )
		{
			queue[i+1] = data_array[i*3+1] + queue[i-1];
		}

		if( ( N - i ) < 2 )
		{
			break;
		}

		if( queue[i+2] > data_array[i*3+2] )
		{
			queue[i+2] = data_array[i*3+2] + queue[i-1];
		}
	}


#ifdef	MAXIMUM_DEBUG

	for( int i = 0; i < N; i++ )
	{
		printf("%d ", queue[i] );
	}
	printf( "\n" );

#endif


	printf("%d\n", queue[N-1] );
	free( data_array );
	free( queue );
	return 0;
}
