#include <stdio.h>
#include <stdlib.h>


typedef unsigned int addr_t;
const addr_t n_bits = 32;
const addr_t page_bits = 6;
const addr_t addr_bits = n_bits - page_bits;
const addr_t page_mask = 0x3F << ( n_bits - page_bits );


int main()
{
    addr_t N_pages = 0;
    scanf( "%u", &N_pages );

    addr_t* pages = ( addr_t* )calloc( N_pages, sizeof( addr_t ) );

    for( addr_t i = 0; i < N_pages; i++ )
    {
        scanf( "%x", &pages[i] );
    }
    addr_t logical_address = 0;
    scanf( "%x", &logical_address );

    addr_t index = ( logical_address & page_mask ) >> addr_bits;
    addr_t physical_address = pages[index] + logical_address - ( index << addr_bits );

    if( index < N_pages )
    {
        printf( "%x\n", physical_address );
    }
    else
    {
        printf( "error\n" );
    }


    free( pages );
    return 0;
}
