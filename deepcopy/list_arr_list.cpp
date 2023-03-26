#include <stdlib.h>
#include <stdio.h>

struct node
{
	struct node *next;
	int n;
};

struct node* mergelists(struct node **arr, int arrlen)
{
	struct node* head = NULL; //test
	struct node* tail = NULL;
	struct node* to_add = NULL;

	int min_number = arr[0]->n;
	int min_number_index = 0;

	for( int i = 1; i < arrlen; i++ ) //найдём минимальное число для самого старта
	{
		if( arr[i]->n < min_number )
		{
			min_number = arr[i]->n;
			head = arr[i]; //тоже неоптимально
		}
	}
	//голова списка у нас есть
	head = tail;

	//int j = 0;
	while( 1 ) //число "сцеплений" элементов ПЕРЕДЕЛАТЬ!!! (когда не было ни одного сцепления или когда все пусты)
	{
		int k = 0;
		for( k = 0; k < arrlen; k++ ) //поиск опорного элемента
		{
			if( arr[k] != NULL )
			{
				min_number_index = k;
				break;
			}
		}
		if( k == arrlen ) //условие полной отсортированности
		{
			 break;
		}

		//min_number = arr[min].n;
		for( k; k < arrlen; k++ ) //поиск минимального
		{
			if( arr[k] == NULL )
			{
				continue;
			}

			if( arr[k]->n < arr[min_number_index]->n )
			{
				min_number_index = k;
			}
		}

		to_add = arr[min_number_index];
		arr[min_number_index] = to_add->next; //перепривязвание в массиве


		tail->next = to_add; //сделать проверку на NULL
		tail = to_add;
		tail->next = NULL;
		//нужно организовать смещение указателей в массиве указателей
	}

	//дополнительно можно зануулить ячейки
	for( int i = 0; i < arrlen; i++ )
	{
		arr[i] = NULL;
	}

	return head;
}

int main()
{
	//короче, пробегать по массиву и цеплять в конец наименьший элемент (списки-то отсортированные)
	node** array = ( node** )calloc( 100, sizeof( node* ) );
	array[0][0].n = 1
	array[0][1] =
	array[0][2] =
	array[0][3] =
	array[1][0] =
	array[2][0] =
	array[3][0] =
	array[3][1] =
	array[3][2] =
	array[3][3] =
	array[3][4] =
	array[4][0] =
	array[5][0] =
	array[6][0] =
	array[7][0] =
	array[8][0] =
	array[9][0] =
	array[9][1] =

	return 0;
}
