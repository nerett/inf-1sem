#include <stdlib.h>
#include <stdio.h>


struct Vector
{
	//x1*y2-x2*y1
	 long long x;
	 long long y;
};


 long long pseudoscalar( const struct Vector* vector1, const struct Vector* vector2 )
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

 long long is_dot_equal( const struct Vector* vector1, const struct Vector* vector2 )
{
	if( ( vector1->x == vector2->x ) && ( vector1->y == vector2->y ) )
	{
		return 1;
	}

	return 0;
}

 long long is_better( const struct Vector* vector1, const struct Vector* vector2 )
{
	if( ( vector1->x > vector2->x ) && ( vector1->y > vector2->y ) )
	{
		return 1;
	}

	return 0;
}


int main()
{
	struct Vector A = {0}, B = {0}, C = {0}, D = {0};

	scanf( "%lld %lld %lld %lld", &A.x, &A.y, &B.x, &B.y );
	scanf( "%lld %lld %lld %lld", &C.x, &C.y, &D.x, &D.y );

	struct Vector AB = v_minus( &B, &A );
	struct Vector AC = v_minus( &C, &A ), AD = v_minus( &D, &A );

	int indicator = 0;
	if( ( ( pseudoscalar( &AB, &AC ) <= 0 ) && ( pseudoscalar( &AB, &AD ) >= 0 ) ) ||
	( ( pseudoscalar( &AB, &AC ) >= 0 ) && ( pseudoscalar( &AB, &AD ) <= 0 ) ) )
	{
		indicator++;
	}

	struct Vector CD = v_minus( &D, &C );
	struct Vector CA = v_minus( &A, &C ), CB = v_minus( &B, &C );

	if( ( ( pseudoscalar( &CD, &CA ) <= 0 ) && ( pseudoscalar( &CD, &CB ) >= 0 ) ) ||
	( ( pseudoscalar( &CD, &CA ) >= 0 ) && ( pseudoscalar( &CD, &CB ) <= 0 ) ) )
	{
		indicator++;
	}

	//проверка коллинеарности


	if( indicator == 2 )
	{
		if( ( !pseudoscalar( &AB, &AC ) ) && ( !pseudoscalar( &AB, &AD ) ) && ( !pseudoscalar( &CD, &CA ) ) && ( !pseudoscalar( &CD, &CB ) ) ) //они на одной прямой
		{
			if( ( is_better( &A, &C ) && is_better( &A, &D ) && is_better( &B, &C ) && is_better( &B, &D ) ) || //если дальше
			( is_better( &C, &A ) && is_better( &C, &B ) && is_better( &D, &A ) && is_better( &D, &B ) ) ) //если ближе
			{
				printf( "NO\n" );
				return 0;
			}
		}
		printf( "YES\n" );
	}
	else
	{
		printf( "NO\n" );
	}

	return 0;
}
