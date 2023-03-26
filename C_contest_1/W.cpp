#include <stdlib.h>
#include <stdio.h>

unsigned int nod(unsigned int a, unsigned int b)
{
	unsigned int max = 0;
	if( a > b )
	{
		max = a;
	}
	else
	{
		max = b;
	}

	for( max; max > 0; max-- )
	{
		if( ( a % max == 0 ) && ( b % max == 0 ) )
		{
			break;
		}
	}

	return max;
}

int main()
{
	printf("%u\n\n", nod( 79169, 99221 ) );

	return 0;
}
