#include "tree.h"
//#include <ctime>

int main()
{
	struct Node* the_tree = NULL;//( Node* )calloc( 1, sizeof( struct Node ) );
	srand( 0 );

	the_tree = tree_add( the_tree, 7 );
	the_tree = tree_add( the_tree, 3 );
	the_tree = tree_add( the_tree, 2 );
	the_tree = tree_add( the_tree, 1 );
	the_tree = tree_add( the_tree, 9 );
	the_tree = tree_add( the_tree, 5 );
	the_tree = tree_add( the_tree, 4 );
	the_tree = tree_add( the_tree, 6 );
	the_tree = tree_add( the_tree, 8 );

/*
	for( int i = 0; i < 100; i++ )
	{
		tree_add( the_tree, ( rand() )%1000 );
	}
*/

	tree_print( the_tree );
	tree_destroy( the_tree );
	//free( the_tree );

	return 0;
}
