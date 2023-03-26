#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct namednum
{
	char *name;
	int number;
};

void namednumcpy(struct namednum *dst, const struct namednum *src, int srclen)
{
	for( size_t i = 0; i < srclen; i++ )
	{
		dst[i].number = src[i].number;

		if( src[i].name == NULL )
		{
			dst[i].name = NULL;
			continue;
		}

		dst[i].name = strdup( src[i].name );
	}
}

int main()
{

}
