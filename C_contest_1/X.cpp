#include <stdlib.h>
#include <stdio.h>

unsigned long long fact(unsigned long long n)
{
	if( n == 0 )
	{
		return 1;
	}

	return n * fact( n - 1 );
}

int main()
{
	printf("%llu\n\n", fact( 3 ) );

	return 0;
}
