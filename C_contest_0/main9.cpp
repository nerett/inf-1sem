#include <stdlib.h>
#include <stdio.h>

struct Athlet
{
	int mass;
	int power;
};


int cmp_Athlets(const void * p1, const void * p2)
{
	struct Athlet athlet1 = *(  const struct Athlet* )( p1 );
	struct Athlet athlet2 = *( const struct Athlet* )( p2 );

	return athlet1.power - athlet2.power;
}

int main()
{
	int N = 0;

	scanf( "%d", &N );

	if( N == 1 )
	{
		printf( "1\n" );
		return 0;
	}

	struct Athlet* the_array = ( struct Athlet* )calloc( N, sizeof( struct Athlet ) );

	for( int i = 0; i < N; i++ )
	{
		scanf( "%d %d", &the_array[i].mass, &the_array[i].power );
	}

	qsort( the_array, N, sizeof( struct Athlet ), cmp_Athlets );

	int height = 1;
	int current_mass = the_array[0].mass;

	for( int i = 1; i < N; i++ )
	{
		if( the_array[i].power >=  current_mass )
		{
			height++;
			current_mass += the_array[i].mass;
			//printf("currentmass=%d currentpower=%d\n", current_mass, the_array[i].power );
		}
	}

	printf( "%d\n", height );

	free( the_array );
	return 0;
}
