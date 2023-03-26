#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <malloc.h>

#define NDEBUG

const int false = 0;
const int true = 1;
typedef int bool;
typedef enum err_code err_code;
typedef int stk_element_t; //!!!
typedef char* ( user_dump )( stk_element_t* data, int N_elements );

enum err_code
{
	OK = 0,
	NO_ELEMENTS_TO_POP = 1,
	CALLOC_ERROR = 2,
	INVALID_DATA_PTR = 3,
	REALLOCATION_ERROR = 4,
	FOPEN_ERROR = 5,
	N_ELEMENT_MORE_CAPACITY = 6,
	INVALID_UP_RESIZE_COEFF = 7,
	INVALID_DOWN_RESIZE_COEFF = 8,
	STACK_IS_NOT_CONSTRUCTED = 9,
	INVALID__USER_TYPE_DUMP_STRING_PTR = 10,
	#ifndef NDEBUG
		LEFT_STRUCT_CANARY_DIED = 11,
		RIGHT_STRUCT_CANARY_DIED = 12,
		LEFT_DATA_CANARY_DIED = 13,
		RIGHT_DATA_CANARY_DIED = 14,
		DATA_HASH_SETTING_ERROR = 15,
		INVALID_DATA_HASH = 16
	#endif
};

/*
char err_code_interpretation[10] = {
	"OK",
	"NO_ELEMENTS_TO_POP",
	"CALLOC_ERROR",
	"INVALID_DATA_PTR",
	"REALLOCATION_ERROR",
	"FOPEN_ERROR",
	"N_ELEMENT_MORE_CAPACITY",
	"INVALID_UP_RESIZE_COEFF",
	"INVALID_DOWN_RESIZE_COEFF",
	"STACK_IS_NOT_CONSTRUCTED",
	"INVALID__USER_TYPE_DUMP_STRING_PTR"
};
*/    // not working:(                                                        \

#define error_output( error_variable, possible_error_type ) do { \
    if( error_variable != NULL )                                 \
	{                                                            \
		*error_variable = possible_error_type;                   \
	}                                                            \
} while(0)

#define void_check_errors( error_variable ) do {                       \
    if( error_variable != NULL )                                       \
  	{                                                                  \
  		if( *error_variable != OK )                                    \
		{                                                              \
			return;                                                    \
		}                                                              \
  	}                                                                  \
} while(0)

#define int_check_errors( error_variable ) do {                      \
   if( error_variable != NULL )                                      \
   {                                                                 \
	   if( *error_variable != OK )                                   \
	   {                                                             \
		   return 0;                                                \
	   }                                                             \
   }                                                                 \
} while(0)

#define validate_dump( some_stack, error_variable ) do {                                                  \
		err_code stack_error = OK;                                                                        \
		validate_stack( some_stack, &stack_error );                                                       \
		stack_dump( some_stack, stack_error, __FILE__, __PRETTY_FUNCTION__, __LINE__, error_variable );   \
	} while(0)


const size_t START_CAPACITY = 8; //8
const unsigned long long CANARY = 0xAB0BAB0BAB0BAB0B;
const int INT_POISON = 0; //TODO поменять на нормальный яд (или заставить пользователя создать его)

const int START_HASH_KEY = 0;
#ifdef NDEBUG
	const int N_CANARIES = 0;
	const int DATA_PTR_OFFSET = 0;
	const int N_ELEMENT_OFFSET = 0;
#endif
#ifndef NDEBUG
	const int N_CANARIES = 2;
	const int DATA_PTR_OFFSET = 1;
	const int N_ELEMENT_OFFSET = 1;
#endif


struct Stack //чтобы использовать стек надо после его создания вызвать конструктор; после вызова деструктора стек можно пересоздать и использовать заново;
{
	#ifndef NDEBUG
		unsigned long long left_struct_canary = CANARY;
	#endif


    int max_capacity; //size_t
    int N_element;

	stk_element_t* data;

    double up_resize_coeff;
    double down_resize_coeff;
    //double smoothing_downsize_coeff = 0;

	//!TODO указатель на функцию дампа данных
	user_dump* user_type_dump_function;

	bool is_initialized; //! static

	#ifndef NDEBUG
		int data_hash;

		unsigned long long right_struct_canary;
	#endif
};

void StackCtor( struct Stack* some_stack, user_dump* user_type_dump_function, err_code* error_variable );
void StackDtor( struct Stack* some_stack, err_code* error_variable);

void stack_push( struct Stack* some_stack, stk_element_t value, err_code* error_variable );
stk_element_t stack_pop( struct Stack* some_stack, err_code* error_variable );
static void stack_resize( struct Stack* some_stack, err_code* error_variable );

//static void init_stack( Stack* some_stack, err_code* error_variable = NULL );

static void calc_upsize_coeff( struct Stack* some_stack );
static void calc_downsize_coeff( struct Stack* some_stack );
static double calc_smoothing_downsize_coeff( const struct Stack* some_stack );

static void upsize_stack( struct Stack* some_stack, err_code* error_variable );
static void downsize_stack( struct Stack* some_stack, err_code* error_variable );
static void reallocate_stack( struct Stack* some_stack, err_code* error_variable );

static bool validate_stack( struct Stack* some_stack, err_code* error_variable ); //< Returns true, if stack is OK
void stack_dump( struct Stack* some_stack, err_code stack_error, const char* error_filename, const char* error_function, int error_line, err_code* error_variable );
void remake_log( err_code* error_variable );

static void set_data_canaries( struct Stack* some_stack );
static unsigned long long struct_canary_x_ptr( unsigned long long* canary_ptr );
static stk_element_t data_canary_x_ptr( stk_element_t* stack_data, int offset );
static bool check_struct_canary( unsigned long long* canary_ptr );
static bool check_data_canary( stk_element_t* stack_data, int offset );
static void set_stack_data_hash( struct Stack* some_stack, err_code* error_variable );
int xor_hash( stk_element_t* data, int N_elements );

//void set_canary(  );
//static void upsize_stack( Stack* some_stack, err_code* error_variable = NULL );
//static void downsize_stack( Stack* some_stack, err_code* error_variable = NULL );


void stack_push( struct Stack* some_stack, stk_element_t value, err_code* error_variable ) //есть какая-то ошибка памяти
{
	assert( some_stack );

	validate_dump( some_stack, error_variable );
	void_check_errors( error_variable );

	if( some_stack->is_initialized == false )
	{
		return;
	}

    stack_resize( some_stack, error_variable );
	void_check_errors( error_variable );

	some_stack->N_element++;

	//не знаю, нужна ли проверка N_element < max_capacity
	some_stack->data[some_stack->N_element] = value;

	#ifndef NDEBUG
		set_stack_data_hash( some_stack, error_variable );
	#endif
}



stk_element_t stack_pop( struct Stack* some_stack, err_code* error_variable ) //!TODO ошибка запроса нулевого элемента стека
{
	assert( some_stack );

	validate_dump( some_stack, error_variable );
	int_check_errors( error_variable );


	if( !some_stack->is_initialized )
	{
		return 0;
	}
	if( some_stack->N_element < 0 )
	{
		return 0;
	}

	if( some_stack->max_capacity < some_stack->N_element )
	{
		error_output( error_variable, NO_ELEMENTS_TO_POP );
		return 0;
	}

	stk_element_t return_value = some_stack->data[some_stack->N_element];
	some_stack->data[some_stack->N_element] = INT_POISON;
	some_stack->N_element--;

	#ifndef NDEBUG
		set_stack_data_hash( some_stack, error_variable );
	#endif

	stack_resize( some_stack, error_variable );
	int_check_errors( error_variable );

	return return_value;
}



static void stack_resize( struct Stack* some_stack, err_code* error_variable )
{
	assert( some_stack );

	validate_dump( some_stack, error_variable );
	void_check_errors( error_variable );


	calc_upsize_coeff( some_stack );
	calc_downsize_coeff( some_stack );

    if( some_stack->N_element == some_stack->max_capacity )
    {
        upsize_stack( some_stack, error_variable );
    }
    else if( some_stack->N_element < some_stack->max_capacity * calc_smoothing_downsize_coeff( some_stack ) && some_stack->max_capacity > START_CAPACITY ) //! КОСТЫЛЬ!
    {
		downsize_stack( some_stack, error_variable );
    }

	void_check_errors( error_variable );
}



static void calc_upsize_coeff( struct Stack* some_stack )
{
	assert( some_stack );

	validate_dump( some_stack, NULL );


	some_stack->up_resize_coeff = 2; //! HARDCODE
}



static void calc_downsize_coeff( struct Stack* some_stack )
{
	assert( some_stack );

	validate_dump( some_stack, NULL );


	some_stack->down_resize_coeff = 0.5; //! HARDCODE
}



static double calc_smoothing_downsize_coeff( const struct Stack* some_stack )
{
	assert( some_stack );

	//validate_dump( some_stack, NULL ); //BUG

	return 0.2; //! HARDCODE
}



void StackCtor( struct Stack* some_stack, user_dump* user_type_dump_function, err_code* error_variable )
{
	assert( some_stack );
	/*
	if( some_stack->is_initialized )
	{
		return; //! переделать
	}
	*/

	some_stack->max_capacity = START_CAPACITY; // проверить после каллока
	some_stack->data = ( stk_element_t* )calloc( some_stack->max_capacity + 1 + N_CANARIES, sizeof( stk_element_t ) ); //я не знаю, почему, но все ошибки valgrind исчезли после +1
	some_stack->data += DATA_PTR_OFFSET;
	if( some_stack->data == NULL )
	{
		error_output( error_variable, CALLOC_ERROR );
		return;
	}

    some_stack->N_element = -1; //FIXED
    some_stack->up_resize_coeff = 1;
    some_stack->down_resize_coeff = 1;
    //double smoothing_downsize_coeff = 0

	some_stack->user_type_dump_function = user_type_dump_function;

	some_stack->is_initialized != false;


	#ifndef NDEBUG
		some_stack->left_struct_canary = struct_canary_x_ptr( &some_stack->left_struct_canary );
		some_stack->right_struct_canary = struct_canary_x_ptr( &some_stack->right_struct_canary );

		set_data_canaries( some_stack );
	#endif
}



void StackDtor( struct Stack* some_stack, err_code* error_variable )
{
	assert( some_stack );

	validate_dump( some_stack, error_variable );
	void_check_errors( error_variable );


	if( !some_stack->is_initialized )
	{
		return;
	}


	if( some_stack->data == NULL )
	{
		error_output( error_variable, INVALID_DATA_PTR );
		return;
	}
	free( some_stack->data - DATA_PTR_OFFSET );

	some_stack->is_initialized = false;
	some_stack->N_element = 0;
	some_stack->max_capacity = 0;
	some_stack->up_resize_coeff = 0;
	some_stack->down_resize_coeff = 0;
}



void upsize_stack( struct Stack* some_stack, err_code* error_variable )
{
	assert( some_stack );

	validate_dump( some_stack, error_variable );
	void_check_errors( error_variable );


	some_stack->max_capacity *= some_stack->up_resize_coeff;

	reallocate_stack( some_stack, error_variable );
	void_check_errors( error_variable );

	#ifndef NDEBUG
		set_data_canaries( some_stack );
	#endif
}



void downsize_stack( struct Stack* some_stack, err_code* error_variable )
{
	assert( some_stack );

	validate_dump( some_stack, error_variable );
	void_check_errors( error_variable );


	some_stack->max_capacity *= some_stack->down_resize_coeff;

	reallocate_stack( some_stack, error_variable );
	void_check_errors( error_variable );

	#ifndef NDEBUG
		set_data_canaries( some_stack );
	#endif
}



static bool validate_stack( struct Stack* some_stack, err_code* error_variable )
{
	if( some_stack->is_initialized == false )
	{
		error_output( error_variable, STACK_IS_NOT_CONSTRUCTED );
		return false;
	}
	if( some_stack->N_element > some_stack->max_capacity )
	{
		error_output( error_variable, N_ELEMENT_MORE_CAPACITY );
		return false;
	}
	if( some_stack->data == NULL )
	{
		error_output( error_variable, INVALID_DATA_PTR );
		return false;
	}
	if( some_stack->up_resize_coeff <= 0 )
	{
		error_output( error_variable, INVALID_UP_RESIZE_COEFF );
		return false;
	}
	if( some_stack->down_resize_coeff <= 0 )
	{
		error_output( error_variable, INVALID_DOWN_RESIZE_COEFF );
		return false;
	}


	#ifndef NDEBUG
		if( !check_struct_canary( &some_stack->left_struct_canary ) )
		{
			error_output( error_variable, LEFT_STRUCT_CANARY_DIED );
			return false;
		}
		if( !check_struct_canary( &some_stack->right_struct_canary ) )
		{
			error_output( error_variable, RIGHT_STRUCT_CANARY_DIED );
			return false;
		}
		if( !check_data_canary( some_stack->data, - DATA_PTR_OFFSET ) )
		{
			error_output( error_variable, LEFT_DATA_CANARY_DIED );
			return false;
		}
		if( !check_data_canary( some_stack->data, some_stack->max_capacity + DATA_PTR_OFFSET ) )
		{
			error_output( error_variable, RIGHT_DATA_CANARY_DIED );
			return false;
		}
		if( xor_hash( some_stack->data, some_stack->N_element ) != some_stack->data_hash )
		{
			error_output( error_variable, INVALID_DATA_HASH );
			return false;
		}
	#endif


	return true;
}



void stack_dump( struct Stack* some_stack, err_code stack_error, const char* error_filename, const char* error_function, int error_line, err_code* error_variable )
{
	#ifndef NDEBUG


	assert( some_stack );


	FILE* logfile = fopen( "stack_log.html", "a" );
	if( logfile == NULL )
	{
		error_output( error_variable, FOPEN_ERROR );
		return;
	}

	fprintf( logfile , "<font color=\"purple\">[STACK_DUMP]</font> " );
	if( stack_error == OK )
	{
		fprintf( logfile , "<font color=\"green\">[OK] at function %s at %s:%d</font>\n", error_function, error_filename, error_line );
	}
	else
	{
		fprintf( logfile, "<font color=\"red  \">[ERROR] stack_error_code = %d at function %s at %s:%d</font>\n", stack_error, error_function, error_filename, error_line );
		fprintf( logfile, "    struct Stack\n" );
		fprintf( logfile, "    {\n" );
		fprintf( logfile, "        max_capacity = %d\n", some_stack->max_capacity );
		fprintf( logfile, "        N_element = %d\n", some_stack->N_element );
		fprintf( logfile, "        *data = 0x%p\n", some_stack->data );
		fprintf( logfile, "        up_resize_coeff = %f\n", some_stack->up_resize_coeff );
		fprintf( logfile, "        down_resize_coeff = %f\n", some_stack->down_resize_coeff );
		fprintf( logfile, "        is_initialized = %d\n", some_stack->is_initialized );
		fprintf( logfile, "    };\n" );

		if( ( some_stack->user_type_dump_function != NULL ) && some_stack->N_element > -1 )
		{
			char* user_type_dump_string = some_stack->user_type_dump_function( some_stack->data, some_stack->N_element );
			if( user_type_dump_string == NULL )
			{
				error_output( error_variable, INVALID__USER_TYPE_DUMP_STRING_PTR );
				return;
			}

			fprintf( logfile, "    data = { " );
			fprintf( logfile, "%s", user_type_dump_string );
			fprintf( logfile, "};\n" );

			free( user_type_dump_string );
		}
	}
	fclose( logfile );


	#endif
}



void remake_log( err_code* error_variable )
{
	#ifndef NDEBUG


	FILE* logfile = fopen( "stack_log.html", "w" );
	if( logfile == NULL )
	{
		error_output( error_variable, FOPEN_ERROR );
		return;
	}

	fputs( "<pre>", logfile );
	fclose( logfile );


	#endif
}



static void set_data_canaries( struct Stack* some_stack )
{
	*( some_stack->data - DATA_PTR_OFFSET ) =
		data_canary_x_ptr( some_stack->data, - DATA_PTR_OFFSET );

	*( some_stack->data + some_stack->max_capacity + DATA_PTR_OFFSET ) =
		data_canary_x_ptr( some_stack->data, some_stack->max_capacity + DATA_PTR_OFFSET );
}



static unsigned long long struct_canary_x_ptr( unsigned long long* canary_ptr )
{
	return CANARY ^ ( unsigned long long )( canary_ptr );
}



static stk_element_t data_canary_x_ptr( stk_element_t* stack_data, int offset )
{
	return ( stk_element_t )( CANARY ^ ( unsigned long long )( stack_data + offset ) );
}



static bool check_struct_canary( unsigned long long* canary_ptr )
{
	return *canary_ptr == struct_canary_x_ptr( canary_ptr );
}



static bool check_data_canary( stk_element_t* stack_data, int offset )
{
	return *( stack_data + offset ) == data_canary_x_ptr( stack_data, offset );
}



static void reallocate_stack( struct Stack* some_stack, err_code* error_variable )
{
	void* realloc_buffer = ( stk_element_t* )realloc( some_stack->data - DATA_PTR_OFFSET,
		sizeof( stk_element_t ) * ( some_stack->max_capacity + 1 + N_CANARIES ) );

	if( realloc_buffer != NULL )
	{
		some_stack->data = ( stk_element_t* )realloc_buffer + DATA_PTR_OFFSET;
	}
	else
	{
		error_output( error_variable, REALLOCATION_ERROR );
		return;
	}
}



int xor_hash( stk_element_t* data, int N_elements )
{
	assert( data );


	int hash_key = START_HASH_KEY;

	for( int i = 0; i < N_elements; i++ )
	{
    	hash_key = hash_key ^ ( int )data[i];
	}

	return hash_key;
}



void set_stack_data_hash( struct Stack* some_stack, err_code* error_variable ) //не проверяет валидность стека в силу логики использования
{
	#ifndef NDEBUG

	assert( some_stack );


	int hash_key_buffer = xor_hash( some_stack->data, some_stack->N_element );
	some_stack->data_hash = hash_key_buffer;

	if( some_stack->data_hash != hash_key_buffer )
	{
		error_output( error_variable, DATA_HASH_SETTING_ERROR );
		return;
	}

	#endif
}


int main()
{
	struct Stack stack;
	err_code error_variable = OK;
	StackCtor( &stack, NULL, &error_variable );

	char symbol = 0;
	char pop_bracket = 0;
	int i = 0;
	while( i++ > -1 )
	{
		char symbol = 0;
		char pop_bracket = 0;

		scanf( "%c", &symbol );

		if( ( symbol == EOF ) || ( symbol == '\n' ) || ( symbol == '\0' ) ) //проверка на конец строки
		{
			break;
		}


		if( ( symbol == '<' ) || ( symbol == '(' ) || ( symbol == '{' ) || ( symbol == '[' ) ) //если открывающая скобка
		{
			stack_push( &stack, symbol, &error_variable );
		}
		else //если закрывающая скобка
		{
			if( stack.N_element == -1 )
			{
				printf( "NO\n" );
				StackDtor( &stack, &error_variable );
				return 0;
			}
			pop_bracket = stack_pop( &stack, &error_variable );

			if( ( pop_bracket - symbol ) > 3 ) //если скобочки разные
			{
				printf( "NO\n" );
				StackDtor( &stack, &error_variable );
				return 0;
			}
		}
	}


	if( stack.N_element == -1 ) //проверка что стек не пуст
	{
		printf( "YES\n" );
	}
	else
	{
		printf( "NO\n" );
	}

	StackDtor( &stack, NULL );
	return 0;
}
