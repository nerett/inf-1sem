#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED


#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


typedef int Data;

struct Node
{
	Data val;           // данные в узле
    struct Node* left;  // левый ребенок
    struct Node* right; // правый ребенок
};


struct Node* tree_add ( struct Node* tree, Data x );
void tree_print ( struct Node* tree );
void tree_destroy( struct Node* tree );


#endif
