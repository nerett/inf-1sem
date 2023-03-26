#include <stdlib.h>
#include <stdio.h>

struct Point {
    int x;
    int y;
};

struct Rect {
    struct Point lt; // left top
    struct Point rb; // right bottom
};

struct Rect transform (struct Rect r)
{
	struct Rect transformed;
	transformed.rb = r.lt;

	int x_length = r.rb.x - r.lt.x;
	int y_length = r.lt.y - r.rb.y;

	transformed.lt.x = r.rb.x - 2 * x_length;
	transformed.lt.y = r.rb.y + 2 * y_length;

	return transformed;
}

int main()
{
	Rect tested;
	tested.lt.x = -1;
	tested.lt.y = 1;
	tested.rb.x = 4;
	tested.rb.y = -2;

	Rect newrect = transform( tested );

	printf("%d %d %d %d\n", newrect.lt.x, newrect.lt.y, newrect.rb.x, newrect.rb.y );
	return 0;
}
