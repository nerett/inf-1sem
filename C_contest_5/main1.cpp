#include <stdlib.h>
#include <stdio.h>


int main()
{
	int M1 = 0, N1 = 0, M2 = 0, N2 = 0; //M строк, N столбцы
	scanf("%d %d %d %d", &M1, &N1, &M2, &N2 );

	if( N1 != M2 )
	{
		printf( "-1" );
		return 0;
	}

	int* matrix_1 = ( int* )calloc( M1*N1, sizeof( int ) );
	int* matrix_2 = ( int* )calloc( M2*N2, sizeof( int ) );
	int* matrix_3 = ( int* )calloc( M1*N2, sizeof( int ) );

	int M3 = M1, N3 = N2;

	for( int i = 0; i < M1*N1; i++ )
	{
		scanf("%d", &matrix_1[i] );
	}
	for( int i = 0; i < M2*N2; i++ )
	{
		scanf("%d", &matrix_2[i] );
	}

	//printf( "===========================\n" );

	for( int i = 0; i < M1; i ++ ) //перемещаемся между строками 1-й матрицы
	{
		for( int j = 0; j < N2; j++ ) //перемещаемся между столбцами второй матрицы
		{
			for( int k = 0; k < N1; k++ ) //N1 = M2
			{
				matrix_3[i * N3 + j] += matrix_1[i * N1 + k] * matrix_2[k * N3 + j];
			}
		}
	}



	for( int i = 0; i < M3*N3; i++ )
	{
		if( i%N3 == 0 && i > 0 )
		{
			printf( "\n" );
		}
		printf("%d ", matrix_3[i] );
	}

	free( matrix_1 );
	free( matrix_2 );
	free( matrix_3 );
	return 0;
}
