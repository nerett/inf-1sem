#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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


double calc_square( struct Vector** const p_array, int N )
{
	struct Vector* points = *p_array;

	double square = 0;
    for( int i = 0; i < N - 1; i++ )
	{
        square += points[i].x * points[i+1].y;
    }
    for( int i = 0; i < N - 1; i++ )
	{
        square -= points[i+1].x * points[i].y;
    }
    square += points[N-1].x * points[0].y - points[0].x * points[N-1].y;

    square = fabs( square ) / 2;

	return square;
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
    scanf( "%d", &N );


	struct Vector* points = ( struct Vector* )calloc( N, sizeof( struct Vector ) );
    for( int i = 0; i < N; i++ )
	{
        scanf( "%lld %lld", &points[i].x, &points[i].y );
    }


    printf( "%g\n", calc_square( &points, N ) );

	free( points );
    return 0;
}
