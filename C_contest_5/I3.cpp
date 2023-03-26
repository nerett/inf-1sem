#include <stdlib.h>
#include <stdio.h>


struct Vector
{
	//x1*y2-x2*y1
	long long x;
	long long y;
};


int pseudoscalar( const struct Vector* vector1, const struct Vector* vector2 )
{
	return ( vector1->x * vector2->y ) - ( vector2->x * vector1->y );
}

struct Vector v_minus( const struct Vector* vector1, const struct Vector* vector2 )
{
	struct Vector result = {0};

	result.x = vector1->x - vector2->x;
	result.y = vector1->y - vector2->y;

	return result;
}

int is_dot_equal( const struct Vector* vector1, const struct Vector* vector2 )
{
	if( ( vector1->x == vector2->x ) && ( vector1->y == vector2->y ) )
	{
		return 1;
	}

	return 0;
}

int is_better( const struct Vector* vector1, const struct Vector* vector2 )
{
	if( ( vector1->x > vector2->x ) && ( vector1->y > vector2->y ) )
	{
		return 1;
	}

	return 0;
}


enum where
{
	NODATA = 0,
	INSIDE = 1,
	OUTSIDE = 2,
	BORDER = 3
};


int main()
{
	int N = 0;
	struct Vector bpla = {0};
	scanf( "%d %lld %lld", &N, &bpla.x, &bpla.y );


	struct Vector* points = ( struct Vector* )calloc( N, sizeof( struct Vector ) );
	for( int i = 0; i < N; i++ )
	{
		scanf("%lld %lld", &points[i].x, &points[i].y );
	}


	struct Vector* Xi_bpla = ( struct Vector* )calloc( N, sizeof( struct Vector ) );
	for( int i = 0; i < N; i++ )
	{
		Xi_bpla[i] = v_minus( &bpla, &points[i] );
	}


	struct Vector* Xi0_Xi1 = ( struct Vector* )calloc( N, sizeof( struct Vector ) );
	for( int i = 0; i < N - 1; i++ )
	{
		Xi0_Xi1[i] = v_minus( &points[i+1], &points[i] );
	}
	Xi0_Xi1[N-1] = v_minus( &points[0], &points[N-1] );


	long long* XX_x_Xbpla = ( long long* )calloc( N, sizeof( long ) );
	for( int i = 0; i < N; i++ )
	{
		XX_x_Xbpla[i] = pseudoscalar( &Xi0_Xi1[i], &Xi_bpla[i] );
	}


	int indicator = 0;
	for( int i = 0; i < N; i++ )
	{
		if( XX_x_Xbpla[i] > 0 )
		{
			indicator++;
		}
		else if( XX_x_Xbpla[i] < 0 )
		{
			indicator--;
		}
	}


	enum where answer = NODATA;
	if( ( indicator == N ) || ( indicator == (-1 * N) )  )
	{
		//проверка на вырожденность
		answer = INSIDE;
	}
	else
	{
		answer = OUTSIDE;
	}


	//проверка вырождения в отрезок
	if( answer == OUTSIDE )
	{
		int j = 0;
		for( j; j < N - 1; j++ )
		{
			if( pseudoscalar( &Xi0_Xi1[j], &Xi0_Xi1[j+1] ) )
			{
				break;
			}
		}
		if( j == N - 1 ) //многоугольник является отрезком
		{
			indicator = 0;
			for( int i = 0; i < N; i++ )
			{
				if( ( bpla.x > points[i].x ) && ( bpla.y > points[i].y )  )
				{
					indicator++;
				}
				else if( ( bpla.x < points[i].x ) && ( bpla.y < points[i].y ) )
				{
					indicator--;
				}
			}
			if( indicator == abs( N ) )
			{
				answer = OUTSIDE;
			}
			else
			{
				answer = INSIDE;
			}
		}
	}


	if( answer == INSIDE || answer == BORDER )
	{
		printf( "YES\n" );
	}
	else if( answer == OUTSIDE )
	{
		printf( "NO\n" );
	}

	free( points );
	free( Xi_bpla );
	free( Xi0_Xi1 );
	free( XX_x_Xbpla );
	return 0;
}
