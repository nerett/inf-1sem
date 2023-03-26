#include "tree.h"


//--------------------FUNCTION----------------------------
struct Node* tree_add ( struct Node* tree, Data x )
{
	if( tree == NULL ) //единственное место, где создаются элементы (!)
	{
        struct Node* t = ( struct Node* )calloc( 1, sizeof( struct Node ) );
        t->right = NULL;
        t->left = NULL;
        t->val = x;
        return t;
    }


	if( tree != NULL )
	{
		if( x > tree->val )
		{
			tree->right = tree_add( tree->right, x );
		}
		else if( x < tree->val )
		{
			tree->left = tree_add( tree->left, x );
		}
	}

	return tree;
}


//--------------------FUNCTION----------------------------
void tree_print ( struct Node* tree )
{
//printf( "DEBUG 1\n" );
	if ( tree == NULL )
	{
		return;
	}
//printf( "DEBUG 2\n" );
    if ( tree->left )
	{
//printf( "if print DEBUG 1\n" );
        tree_print( tree->left );
        printf(" ");
//printf( "if print DEBUG 2\n" );
    }
//printf( "DEBUG 3\n" );
    printf( "%d", tree->val );
    if ( tree->right )
	{
        printf(" ");
        tree_print( tree->right );
    }
//printf( "DEBUG 4\n" );
}


//--------------------FUNCTION----------------------------
void tree_destroy( struct Node* tree )
{
    if( tree == NULL )
    {
        free( tree );
    }
    else
    {
        tree_destroy( tree->right );
        tree_destroy( tree->left );
        free( tree );
    }
}
