#include "stdlib.h"
#include "stdio.h"


struct Point
{
	int x;
    int y;
};


struct Rect
{
    struct Point lt; // left top
    struct Point rb; // right bottom
};


struct Rect * transform (const struct Rect * src) {
	struct Rect* new_rect = ( struct Rect* )calloc( 1, sizeof( struct Rect ) );

	new_rect->lt.x = ( -1 ) * src->lt.x;
	new_rect->rb.x = ( -1 ) * src->rb.x;

	new_rect->rb.y = src->rb.y;
	new_rect->lt.y = src->lt.y;

	return new_rect;
}


int main()
{
	struct Rect a = {{2, 4}, {7, 1}};
    struct Rect * rect;

    rect = transform(&a);

    printf("%d %d %d %d\n", a.lt.x, a.lt.y, a.rb.x, a.rb.y);
    printf("%d %d %d %d\n", rect->lt.x, rect->lt.y, rect->rb.x, rect->rb.y);

    free(rect);

	return 0;
}
