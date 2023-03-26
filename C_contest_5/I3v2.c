#include <stdio.h>
#include <stdlib.h>

// stdbool.h was created in 1980, people in 2021:
typedef int bool;
const int true = 1;
const int false = 0;


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
	struct Vector X = {0};

    scanf( "%d", &N );
    int j = N - 1;

	struct Vector* points = ( struct Vector* )calloc( N, sizeof( struct Vector ) );
    //int *x = ( int* )calloc( N, sizeof( int ) );
    //int *y = ( int* )calloc( N, sizeof( int ) );

    scanf( "%lld %lld", &X.x, &X.y );

	int i = 0, k = 0;
    for( i = 0; i < N; i++ )
	{
        scanf("%lld %lld", &points[i].x, &points[i].y);
    }

    for( i = 0; i < N; i++ )
	{
        if( is_dot_equal( &points[i], &X ) )
		{
            printf("YES\n");

            free( points );
            return 0;
        }
    }

    for( i = 0; i < ( N - 1 ); i++ )
	{
        if( is_dot_equal( &points[i], &points[i+1] ) )
		{
            k += 1;
        }
        else
		{
            k = 0;
        }
    }

	bool result = false;
    if ( k == ( N - 1)  )
	{
        if( is_dot_equal( &points[i], &X ) )
		{
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    else
	{
        for( i = 0; i < N; i++ )
		{
			// DO NOT TOUCH IT i dont know what iD does
            if( ( points[i].y < X.y && points[j].y >= X.y || points[j].y < X.y && points[i].y >= X.y ) &&
			( points[i].x + ( points[j].x - points[i].x )*( X.y - points[i].y )/( points[j].y - points[i].y ) < X.x ) )
			{
                result = !result;
            }

            j = i;
        }

        if ( result == 1 )
		{
            printf("YES\n");
        }
        else
		{
            printf("NO\n");
        }
    }


    free( points );
    return 0;
}
