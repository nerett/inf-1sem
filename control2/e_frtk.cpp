#include <stdlib.h>
#include <stdio.h>

#include <string.h>
char * convert (char * dst, const char * src)
{
	int length = strlen( src ); //количество элементов считается корректно
	//printf("length = %d\n", length );

	char* buffer = ( char* )calloc( length * 4 + 1, sizeof( char ) );

	for( int i = 0; i < length; i++ )
	{
		//printf("src c = %c\n", src[i] );
		switch( src[i] )
		{
			case '0': sprintf( buffer + i*4, "%s", "0000" ); break;
			case '1': sprintf( buffer + i*4, "%s", "0001" ); break;
			case '2': sprintf( buffer + i*4, "%s", "0010" ); break;
			case '3': sprintf( buffer + i*4, "%s", "0011" ); break;
			case '4': sprintf( buffer + i*4, "%s", "0100" ); break;
			case '5': sprintf( buffer + i*4, "%s", "0101" ); break;
			case '6': sprintf( buffer + i*4, "%s", "0110" ); break;
			case '7': sprintf( buffer + i*4, "%s", "0111" ); break;
			case '8': sprintf( buffer + i*4, "%s", "1000" ); break;
			case '9': sprintf( buffer + i*4, "%s", "1001" ); break;
			case 'a': sprintf( buffer + i*4, "%s", "1010" ); break;
			case 'A': sprintf( buffer + i*4, "%s", "1010" ); break;
			case 'b': sprintf( buffer + i*4, "%s", "1011" ); break;
			case 'B': sprintf( buffer + i*4, "%s", "1011" ); break;
			case 'c': sprintf( buffer + i*4, "%s", "1100" ); break;
			case 'C': sprintf( buffer + i*4, "%s", "1100" ); break;
			case 'd': sprintf( buffer + i*4, "%s", "1101" ); break;
			case 'D': sprintf( buffer + i*4, "%s", "1101" ); break;
			case 'e': sprintf( buffer + i*4, "%s", "1110" ); break;
			case 'E': sprintf( buffer + i*4, "%s", "1110" ); break;
			case 'f': sprintf( buffer + i*4, "%s", "1111" ); break;
			case 'F': sprintf( buffer + i*4, "%s", "1111" ); break;
		}
		//printf( "buffer = %s\n", buffer );
	}

	char* start = strchr( buffer, '1' );
	sprintf( dst, "%s", start );

	free( buffer );

	return dst;
}


int main()
{
	char d[100];
	printf("%s\n", convert(d, "01a3"));	// 110100011
	return 0;
}
