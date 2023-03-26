#include <stdlib.h>
#include <stdio.h>

struct object
{
	unsigned long long m = 0;
	unsigned long long v = 0;
	unsigned long long p = 0;
};

int cmp_obj(const void* p1, const void* p2);

int main()
{
	int N = 0;
	scanf( "%d", &N );
	struct object* obj_array = ( struct object* )calloc( N, sizeof( struct object ) );
	for( int i = 0; i < N; i++ )
	{
		scanf( "%llu %llu", &( obj_array[i].m ), &( obj_array[i].v ) );
		obj_array[i].p = obj_array[i].m * obj_array[i].v;
	}

	qsort( obj_array, N, sizeof( struct object ), cmp_obj );

	for( int i = 0; i < N; i++ )
	{
		printf( "%llu %llu\n", ( obj_array[i].m ), ( obj_array[i].v ) );
		obj_array[i].p = obj_array[i].m * obj_array[i].v;
	}

	free( obj_array );
}

int cmp_obj(const void* p1, const void* p2)
{
	struct object* obj1 = ( struct object* )( p1 );
	struct object* obj2 = ( struct object* )( p2 );

	long long result = obj1->p - obj2->p;

	if( result == 0 )
	{
		result = obj2->m - obj1->m;
	}


	if( result < 0 ) result = -1;
	else if( result > 0 ) result = 1;
	else if( result == 0 ) result = 0;


	return result;
}
