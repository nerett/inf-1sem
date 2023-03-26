#include <stdlib.h>
#include <stdio.h>


struct Vector
{
	//x1*y2-x2*y1
	int x;
	int y;
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


int main()
{
	struct Vector A = {0}, B = {0}, C = {0};
	struct Vector boom = {0};

	scanf( "%d %d", &A.x, &A.y );
	scanf( "%d %d", &B.x, &B.y );
	scanf( "%d %d", &C.x, &C.y );
	scanf( "%d %d", &boom.x, &boom.y );

/*
	if( is_dot_equal( &A, &B ) && is_dot_equal( &B, &C ) ) //вырождение в точку
	{
		if( is_dot_equal( &A, &boom ) )
		{
			printf( "In\n" );
			return 0;
		}
		else
		{
			printf( "Out\n" );
			return 0;
		}
	}
*/


	struct Vector Aboom = v_minus( &boom, &A ), Bboom = v_minus( &boom, &B ), Cboom = v_minus( &boom, &C );
	struct Vector AB = v_minus( &B, &A ), BC = v_minus( &C, &B ), CA = v_minus( &A, &C );

	int ABxAboom = pseudoscalar( &AB, &Aboom ), BCxBboom = pseudoscalar( &BC, &Bboom ), CAxCboom = pseudoscalar( &CA, &Cboom );

	if( ( ABxAboom >= 0 && BCxBboom >= 0 && CAxCboom >= 0 ) || ( ABxAboom <= 0 && BCxBboom <= 0 && CAxCboom <= 0 ) )
	{
		if( !pseudoscalar( &A, &B ) ) //вырождение в отрезок
		{
			//printf( "AAAAAAAAAAAAAA\n" );
			if( ( is_better( &boom, &A ) && is_better( &boom, &B ) && is_better( &boom, &C ) ) || //если дальше
			( is_better( &A, &boom ) && is_better( &B, &boom ) && is_better( &C, &boom ) ) ) //если ближе
			{
				printf( "Out\n" );
				return 0;
			}
		}

		printf( "In\n" );
	}
	else
	{
		printf( "Out\n" );
	}

	return 0;
}
