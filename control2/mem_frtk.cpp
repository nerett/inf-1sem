#include "stdlib.h"
#include "stdio.h"

#define N 100


struct _Decimal {
    char * a;          // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;    // наибольшая степень десяти
    unsigned int size; // размер выделенной динамической памяти в а (можно это поле не использовать).
};


typedef struct _Decimal Decimal;


Decimal zero = {{0}, 0};    // представление 0 в виде структуры


Decimal* div10 (const Decimal * a)
{
	Decimal* res = ( Decimal* )calloc( 1, sizeof( Decimal ) );

	if( ( a->n == 0 ) ) //любое однозначное число
	{
		res->n = 0;
		res->size = 0;

		res->a = ( char* )calloc( 1, sizeof( char ) );
		res->a[0] = 0;

		return res;
	}

	res->n = a->n - 1;
	res->a = ( char* )calloc( res->n + 1, sizeof( char ) );

	//res->a[0] = 0;

	for( int i = 0; i < res->n + 1; i++ ) //copy
	{
		res->a[i] = a->a[i+1];
	}

	return res;
}


int main()
{
	Decimal* a = ( Decimal* )calloc( 1, sizeof( Decimal ) );
	a->a = ( char* )calloc( 1000, sizeof( char ) );

	a->a[0] = 7;
	a->a[1] = 4;
	a->a[2] = 1;
	a->n = 2;

    Decimal* res;
    // 147 is {{7, 4, 1}, 2};

    res = div10(a);            // res = a/10 = 147/10 = 14

    printf( "result = " );                  // print 14
	for( int i = 0; i < res->n + 1; i++ )
	{
		printf( "%d ", res->a[i] );
	}
    printf("\n");

    // надо освободить память

    return 0;
}
