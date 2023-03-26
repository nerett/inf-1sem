#include <stdlib.h>
#include <stdio.h>

int main()
{
	int N = 0;
	scanf("%d", &N );
	int* the_string = ( int* )calloc( ( N ), sizeof( int ) );

	for( int i = 0; i < N; i++ )
	{
		scanf("%d", &the_string[i] );
	}
	//scanf("%s", the_string );

	for( int i = 0; i < N; i++ )
	{
		printf("%d ", the_string[i] );
	}
	for( int i = 0; i < N; i++ )
	{
		printf("%d ", the_string[i] );
	}
	//printf("%s %s", the_string, the_string );
	//printf("%s\n", the_string );

	free( the_string );
	return 0;
}
