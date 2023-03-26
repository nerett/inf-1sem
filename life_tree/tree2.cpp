#include <stdlib.h>
#include <stdio.h>

typedef int Data;

struct Node
{
    Data val;           // данные в узле
    struct Node *left;  // левый ребенок
    struct Node *right; // правый ребенок
};

struct Node *tree_add(struct Node *tree, Data x)
{
    if (tree == NULL)
    {
        tree = (struct Node *)malloc(sizeof(struct Node));
        tree->right = NULL;
        tree->left = NULL;
        tree->val = x;
    }
    else
    {
        if (x > tree -> val)
        {
            tree_add(tree -> right, x);
        }
        if (x < tree->val)
        {
            tree_add(tree->left, x);
        }
    }
    return tree;
}

void tree_print(struct Node *tree)
{
    if (tree != NULL)
    {
        tree_print(tree->left);
        printf("%d ", tree->val);
        tree_print(tree->right);
    }
}

void tree_destroy(struct Node *tree)
{
    if (tree == NULL)
    {
        free(tree);
    }
    else
    {
        tree_destroy(tree->right);
        tree_destroy(tree->left);
        free(tree);
    }
}

int main()
{
    struct Node* tree = ( Node* )calloc( 1, sizeof( struct Node ) );;

    int input_value = 1;
    while (input_value != 0)
    {
        scanf( "%d", &input_value );
        if ( input_value != 0 )
        {
            tree_add( tree, input_value );
        }
    }

	printf("print:\n");
    tree_print( tree );
    tree_destroy( tree );
}
