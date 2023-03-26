#include <stdlib.h>
#include <stdio.h>

typedef int Data;

struct Node {
    Data val;
    struct Node *next;
};

struct List {
    struct Node *head;
};


//-----------------FUNCTION----------------------------------------------
struct List *list_create()
{
    struct List *created = (struct List *)calloc(1, sizeof(struct List));;
    created->head = NULL;

    return created;
}


//-----------------FUNCTION----------------------------------------------
void list_add_first(struct List *list, Data x)
{
    struct Node *new_node = (struct Node *) calloc(1, sizeof(struct Node));
    new_node->next = list->head;
    list->head = new_node;
    new_node->val = x;
}


//-----------------FUNCTION----------------------------------------------
void list_add_last(struct List *list, Data x)
{
    struct Node *new_node = (struct Node *) calloc(1, sizeof(struct Node));

    struct Node *last_node = list->head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }

    last_node->next = new_node;
    new_node->next = NULL;
    new_node->val = x;
}


//-----------------FUNCTION----------------------------------------------
Data list_remove_first(struct List *list)
{
    Data return_data = list->head->val;
    struct Node *new_head = list->head->next;

    free(list->head);
    list->head = new_head;

    return return_data;
}


//-----------------FUNCTION----------------------------------------------
Data list_remove_last(struct List *list)
{
    struct Node *last_node = list->head;
    while ( last_node->next ) //поиск последнего элемента
	{
        last_node = last_node->next;
    }


    Data return_data = last_node->val; //запись возвращаемого значения


    struct Node *pre_last_node = list->head;
    while ( pre_last_node )
	{
		if( pre_last_node->next == last_node )
		{
			break;
		}

        pre_last_node = pre_last_node->next;
    }


	last_node->val = -13114114;
    free(last_node);


    if( pre_last_node )
	{
        pre_last_node->next = NULL;
    }
	else
	{
		list->head = NULL;
	}

	//if( last_node == pre_last_node )

    return return_data;
}


//-----------------FUNCTION----------------------------------------------
Data list_get_first(struct List *list)
{
    return list->head->val;
}


//-----------------FUNCTION----------------------------------------------
Data list_get_last(struct List *list)
{
    struct Node *last_node = list->head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }

    return last_node->val;
}


//-----------------FUNCTION----------------------------------------------
int list_size(struct List *list)
{
    int length = 0;

    struct Node *last_node = list->head;
    while ( last_node )
	{
        length++;
        last_node = last_node->next;
    }

    return length;
}


//-----------------FUNCTION----------------------------------------------
void list_print(struct List *list) //! ОШИБКА ТУТ
{
	if( list_size( list ) == 0 )
	{
		printf( "Empty list\n" );
		return;
	}


    struct Node *last_node = list->head;

    while ( last_node ) //(last_node) && (last_node->next)
	{
        printf("%d ", last_node->val);
		last_node = last_node->next;
    }
	printf( "\n" );
}


//-----------------FUNCTION----------------------------------------------
void list_clear(struct List *list)
{
    struct Node *last_node = list->head;
    struct Node *next_node = list->head;

    while ( last_node )
	{
        next_node = last_node->next;
        free(last_node);
        last_node = next_node;
    }
}


//-----------------FUNCTION----------------------------------------------
void list_destroy(struct List *list) //тут есть ошибка
{
    list_clear(list);
    free(list);
}


int main()
{
	struct List * list = list_create();
	//list_add_first(list, 5);
	printf( "size = %d\n", list_size( list ) );
	list_print(list);
	list_destroy(list);

    return 0;
}
