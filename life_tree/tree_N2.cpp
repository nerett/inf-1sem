#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


typedef int Data;

#define TRUE 1

struct Node
{
	Data val;           // данные в узле
    struct Node* left;  // левый ребенок
    struct Node* right; // правый ребенок
};


struct Node* tree_add ( struct Node* tree, Data x );
void tree_print ( struct Node* tree );
void tree_destroy( struct Node* tree );


int main()
{
	struct Node* the_tree = NULL;//( Node* )calloc( 1, sizeof( struct Node ) );
	
    int input_value = 0;
	while( TRUE )
	{
        scanf( "%d", &input_value );
        if( input_value == 0 )
        {
            break;
        }
		the_tree = tree_add( the_tree, input_value );
	}

	tree_print( the_tree );
    
	tree_destroy( the_tree );
	//free( the_tree );

	return 0;
}


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
	if ( tree == NULL )
	{
		return;
	}
    if ( tree->left )
	{
        tree_print( tree->left );
        printf(" ");
    }
    printf( "%d", tree->val );
    if ( tree->right )
	{
        printf(" ");
        tree_print( tree->right );
    }
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
