#include <stdio.h>
#include <stdlib.h>

//const int MAXIMUM_MATRIX_SIZE = 21;

int main()
{
    long int matrix[21][21] = {};
    int n = 0, m = 0;
    
    scanf( "%d %d", &n, &m );
    
    n++;
    m++;


    int i = 0;
    int j = 0;
    for( j = 0; j < m; j++ ) //инициализация краёв матрицы
    {
        matrix[i][j] = 1;
    }

    j = 0;
    i = 0;
    for( i = 0; i < n; i++ ) //инициализация краёв матрицы
    {
        matrix[i][j] = 1;
    }

    /*
        1 1 1 1 1 1 1 ...
        1 y x x x x x
        1 x y x x x x
        1 x x y x x x
        1 x x x y x x
        1 x x x x y x
        1 x x x x x y
        .
        .
        .
    */
        
    for( i = 1; i < n; i++ )
    {
        for( j = 1; j < m; j++ )
        {
            matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
        }
    }


    printf( "%ld", matrix[n-1][m-1] );

    return 0;
}
