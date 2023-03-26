#ifndef _TREE_H
#define _TREE_H

#include <stddef.h>


typedef int Data; //Шаблоны

struct Node {
    Data val;            // данные в узле
    struct Node * left;  // левый ребенок
    struct Node * right; // правый ребенок
};

typedef struct Node Derevo; //C++ no struct....

void tree_print (Derevo * tree); //operator <<
void tree_destroy (Derevo * tree); //деструктор
struct Node * tree_add (Derevo * tree, Data x); //конструктор
int tree_height(Derevo * tree);

void tree_print_leaves (Derevo * tree); 
#endif

//ssh -p 50506  frkt@remote.vdi.mipt.ru
