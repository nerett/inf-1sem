#include "stdlib.h"
#include "stdio.h"

#define N 100


struct _Decimal
{
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
};


typedef struct _Decimal Decimal;


Decimal zero = {{0}, 0};    // представление 0 в виде структуры


void mult10 (Decimal* res, const Decimal* a)
{
	if( a->n >= N )
	{
		return;
	}

	if( ( a->n == 0 ) && ( a->a[0] == 0 ) ) //сравнение с нулём
	{
		res->n = 0;
		res->a[0] = 0;

		return;
	}

	res->a[0] = 0;
	res->n = a->n + 1;

	for( int i = 0; i < res->n; i++ ) //copy
	{
		res->a[i+1] = a->a[i];
	}
}


int main()
{
    Decimal a = {{7, 4, 1}, 2};  // set number 147
    Decimal res;

    mult10(&res, &a);          // res = a*10 = 147*10 = 1470

    printf( "number = \n" );         // print 1470
	for( int i = 0; i <= res.n; i++ )
	{
		printf( "%d ", res.a[i] );
	}
    printf("\n");

    return 0;
}
