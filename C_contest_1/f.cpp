#include <stdlib.h>
#include <stdio.h>

int main()
{
	char * b[6];
	char ** p;

	p = ( char** )calloc( 6, sizeof( char* ) );
	for( int i = 0; i < 6; i++ )
	{
		p[i] = b[i];
	}

	return 0;
}
