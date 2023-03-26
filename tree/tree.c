#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

void tree_print(Derevo * tree)
{
    if (!tree)
        return;
    if (tree->left) {
        tree_print(tree->left);
        printf(" ");
    }
    printf("%d", tree->val);    //Перегруженный operator <<
    if (tree->right) {
        printf(" ");
        tree_print(tree->right);
    }
}

struct Node * tree_add (struct Node * tree, Data x){ //конструктор
    if(!tree){
        struct Node* t = malloc(sizeof(struct Node));
        t->right = NULL;
        t->left = NULL;
        t->val = x;
        return t;
    }
 if(x > tree->val){
 
	tree->right = tree_add(tree->right, x);
/*
        if(!tree->right){
            tree->right = malloc(sizeof(struct Node));
            tree->right->right = NULL;
            tree->right->left = NULL;
            tree->right->val = x;
            return tree;
        }else{
            tree_add(tree->right, x);
            return tree;
        }
*/
    }else if(x < tree->val){
	tree->left = tree_add(tree->left, x);
/*
        if(!tree->left){
            tree->left = malloc(sizeof(struct Node));
            tree->left->right = NULL;
            tree->left->left = NULL;
            tree->left->val = x;
            return tree;
        }else{
            tree_add(tree->left, x);
      
    }*/
   }
   return tree;
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




