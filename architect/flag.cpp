#ifndef REGISTERS
	#define REGISTERS 4
#endif

#include <stdlib.h>
#include <stdio.h>


enum OPCODES
{
	HLT = 0,
	ADD = 1,
	SUB = 2,
	MOV = 3,
	IR = 4
};

const unsigned char REGSTART = 5;
const unsigned char REGEND = REGSTART + REGISTERS - 1;
typedef unsigned char ZF;
const ZF TRUE = 1;
const ZF FALSE = 0;

#define test( reg )							\
do{											\
	if( reg < REGSTART || reg > REGEND || !REGISTERS )	\
	{										\
		printf( "-1" );						\
		free( data );						\
		return 0; 							\
	}										\
}while(0)


int main()
{
	unsigned char current_op = HLT;
	unsigned char val = 0;
	unsigned char reg = 0;
	unsigned char reg1 = 0;
	unsigned char reg2 = 0;
	unsigned char* data = ( unsigned char* )calloc( REGEND, sizeof( unsigned char ) );
	int read_symbols = 0;
	ZF zero_flag = FALSE;
	ZF read_zero_flag = FALSE;

	while( 1 )
	{
		current_op = HLT;
		val = 0;
		reg = 0;
		reg1 = 0;
		reg2 = 0;
		read_symbols = 0;
		read_zero_flag = FALSE;


		read_symbols = scanf( "%hhu", &current_op );
		if( read_symbols <= 0 )
		{
			break;
		}

		read_zero_flag = current_op & 0x80;
		current_op &= 0x7F;

		switch( current_op )
		{
			case HLT:
				if( read_zero_flag && !zero_flag )
				{
					break;
				}
				free( data );
				return 0;
				break;
			case ADD: 
				scanf( "%hhu %hhu", &reg1, &reg2 );
				test( reg1 );
				test( reg2 );
				if( read_zero_flag && !zero_flag )
				{
					break;
				}
				data[reg1] += data[reg2];
				zero_flag = FALSE;
				if( data[reg1] == 0 )
				{
					zero_flag = TRUE;
				}
				break;
			case SUB:
				scanf( "%hhu %hhu", &reg1, &reg2 );
				test( reg1 );
				test( reg2 );
				if( read_zero_flag && !zero_flag )
				{
					break;
				}
				data[reg1] -= data[reg2];
				zero_flag = FALSE;
				if( data[reg1] == 0 )
				{
					zero_flag = TRUE;
				}
				break;
			case MOV:
				scanf( "%hhu %hhu", &reg, &val );
				test( reg );
				if( read_zero_flag && !zero_flag )
				{
					break;
				}
				data[reg] = val;
				zero_flag = FALSE;
				if( val == 0 )
				{
					zero_flag = TRUE;
				}
				break;
			case IR:
				if( read_zero_flag && !zero_flag )
				{
					break;
				}
				for( unsigned char i = REGSTART; i <= REGEND; i++ )
				{
					printf( "%hhu ", data[i] );
				}
				printf( "\n" );
				break;
			default:
				printf( "-1" );
				free( data );
				return 0;
				break;
		}
	}

	free( data );
	return 0;
}