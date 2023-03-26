#include <stdlib.h>
#include <stdio.h>
#include <string.h>

union u
{
	char data[17];
	long double ldb;
	double db;
	float fl;
};

int main()
{
	char word[20] = {};
	union u value = {};
	int N = 0;

	scanf( "%s", word );

	if( !strcmp( word, "float" ) )
	{
		scanf( "%f", &value.fl );
		N = 4;
	}
	else if( !strcmp( word, "double" ) )
	{
		scanf( "%lf", &value.db );
		N = 8;
	}
	else if( !strcmp( word, "long" ) )
	{
		scanf( "%s", word );

		scanf( "%Lf", &value.ldb );
		N = 16;
	}

	for( int i = N - 1; i >= 0; i-- )
	{
		for (int j = sizeof( value.data[i] ) * 8 - 1; j >= 0; j--)
		{
    		putc('0' + ((value.data[i] >> j) & 1), stdout);
			if( j % 4 == 0 )
			{
				printf( " " );
			}
		}
	}

	return 0;
}
