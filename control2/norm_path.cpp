#include <stdlib.h>
#include <stdio.h>

#include <string.h>
extern void normalize_path(char * path)
{
	int d = 0;
	int length = strlen( path );
	char* buffer = ( char* )calloc( length, sizeof( char ) );

	bool last_slash = false;
	for( int i = 0; i < length; i++ ) //убирание лишних пробелов
	{
		if( path[i] == '/' )
		{
			if( last_slash == true )
			{
				d--;
				last_slash = true;
				continue;
			}

			last_slash = true;
			buffer[i+d] = '/';
		}
		else
		{
			last_slash = false;
			buffer[i+d] = path[i];
		}
	}

	//! DEBUG
	printf( "%s\n", buffer );


	length = strlen( buffer ); //возможно, убрать


	char** index_string = ( char** )calloc( length, sizeof( char* ) );

	for( int i = 0; i < length - 1; i++ )
	{
		if(  )
		{

		}
	}
}

int main()
{
	char test[] = "kjjh/////fsfsf/sfsf/fsfsfssfsfsf//////sf";
	normalize_path( test );

	return 0;
}
