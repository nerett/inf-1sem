#include <stdlib.h>
#include <stdio.h>

int main()
{
	int N = 0;
	scanf( "%d", &N );

	int answer = 0;

	for( int i = 0; i < N * N; i++ )
	{
		int value = 0;
		scanf( "%d", &value );
		if( value != 0 )
		{
			answer++;
		}
	}

	//printf( "pre = %d\n", answer );
	if( answer != 1 )
	{
		answer = answer / 2;
	}
	printf( "%d\n", answer );
	return 0;
}
