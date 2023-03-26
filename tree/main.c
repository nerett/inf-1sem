#include "tree.h"
int main()
{
struct Node * tree=NULL;
tree = tree_add(tree, 7);

//tree_print(tree); 
tree = tree_add(tree, 3);
tree = tree_add(tree, 2);
//tree_print(tree); 
tree = tree_add(tree, 1);
tree = tree_add(tree, 9);
tree = tree_add(tree, 5);
tree = tree_add(tree, 4);
tree = tree_add(tree, 6);
tree = tree_add(tree, 8);
tree_print(tree); 
tree_destroy(tree);
return 0;
}	
