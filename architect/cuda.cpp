#include <stdio.h>
#include <stdlib.h>
#include <math.h>


const int MAXTHREADS = 1536;
const double D_MAXTHREADS = 1536.0;
const int MAXREGS = 32768;
const int MAXMEM = 49152;


int calc_threads( int thread_per_block )
{
	return ( ( thread_per_block - 1 ) / 32 + 1 ) * 32;
}

int calc_regs( int reg_per_thread )
{
	return ( ( reg_per_thread - 1 ) / 2 + 1 ) * 2;
}

int calc_blocks( int current_threads )
{
	return MAXTHREADS / current_threads;
}

int calc_mem( int memlimit )
{
	return MAXMEM / memlimit;
}


int main()
{
    int thread_per_block = 0;
    int reg_per_thread = 0;
    int mem_per_block = 0;

    FILE *inputfile = fopen( "cuda.in", "r" );
    fscanf( inputfile, "%d %d %d", &thread_per_block, &reg_per_thread, &mem_per_block );
    fclose(inputfile);


    int current_threads = calc_threads( thread_per_block );
    int current_regs = calc_regs( reg_per_thread );
    int current_blocks = calc_blocks( current_threads );
    int reglimit = MAXREGS / ( current_threads * current_regs );
	int memlimit = ( ( mem_per_block - 1 ) / 128 + 1 ) * 128;
	int current_mem = calc_mem( memlimit );
    if( reglimit < current_blocks )
	{
		current_blocks = reglimit;
	}
    if( current_mem < current_blocks )
	{
		current_blocks = current_mem;
	}

    int percentage = ( int )round( ( ( current_blocks * thread_per_block ) / D_MAXTHREADS ) * 100 );


    FILE *outfile = fopen( "cuda.out", "w" );
    fprintf( outfile, "%d", percentage );
    fclose( outfile );

    return 0;
}
