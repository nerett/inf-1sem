#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const long long STRLENGTH = 99999;

struct namednum
{
	char *name;
	int number;
};

void fixupstrings(struct namednum* arr, size_t arrlen)
{
	for( size_t i = 0; i < arrlen; i++ )
	{
		if( arr[i].name == NULL )
		{
			continue;
		}

		for( size_t j = 0; j < i; j++ ) //i + 1; j < arrlen
		{
				if( arr[j].name == NULL )
				{
					continue;
				}

				if( arr[i].name == arr[j].name )
				{
					arr[i].name = strdup( arr[j].name );
					break;
				}
		}
	}
}


int main()
{
	namednum test[STRLENGTH];
	for( int i = 0; i < STRLENGTH; i++ )
	{
		test[i].name = ( char* )calloc( 20, sizeof( char ) );
		test[i].number = i;
	}

	printf( "BEFORE\n" );
	for( int i = 0; i < STRLENGTH; i++ )
	{
		printf("[BEFORE] %p\n", test[i].name );
	}

	test[2].name = NULL;
	test[5].name = test[6].name;

	//test[8].name = NULL;
	test[9].name = test[8].name;

	printf( "BEFORE2\n" );
	for( int i = 0; i < STRLENGTH; i++ )
	{
		printf("[BEFORE2] %p\n", test[i].name );
	}

	fixupstrings( test, STRLENGTH );

	printf( "AFTER\n" );
	for( int i = 0; i < STRLENGTH; i++ )
	{
		printf("[AFTER] %p\n", test[i].name );
	}
	return 0;
}
