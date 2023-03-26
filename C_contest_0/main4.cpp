#include <stdlib.h>
#include <stdio.h>

int main()
{
	int a[3], b[3], c[3];
	for( int i = 0; i < 3; i++ )
	{
		scanf("%d", &a[i] );
	}
	for( int i = 0; i < 3; i++ )
	{
		scanf("%d", &b[i] );
	}
	for( int i = 0; i < 3; i++ )
	{
		scanf("%d", &c[i] );
	}

	printf("%d", a[0] + b[1] + c[2] );
	return 0;
}
