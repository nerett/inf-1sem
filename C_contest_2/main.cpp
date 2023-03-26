#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const char NOT_A_LETTER[] = { "01234567890 QWERTYUIOPASDFGHJKLZXCVBNM :;'\"/!@#$%^&*()-_+=№" };

int is_letter(char symbol)
{
    int size = sizeof(NOT_A_LETTER);
    //printf("\n%d\n", size );
    for (int i = 0; i < size; i++) {
        if (symbol == NOT_A_LETTER[i]) {
            return 0;
        }
    }
    return 1;
}

int count_strings(char *text_line, int N_symbols)
{
    int N_strings = 0;

    for (int i = 0; i <= N_symbols; i++) {      //BUG
        if (text_line[i] == '\0' || text_line[i] == EOF
            || !is_letter(text_line[i])) {
            N_strings++;
            text_line[i] = '\0';
        }
    }

    return N_strings;
}



void find_string_beginning(char *text_line, char **index_string, int N_symbols) // init_strings
{
    char last_read = '\n';
    int j = 0;

    for (int i = 0; i < N_symbols; i++) {
        if (last_read == '\n' || last_read == '\0') {
            index_string[j] = text_line + i;
            j++;
        }
        last_read = text_line[i];
    }
}



int main()
{
	for( true )
	{
		char* string;
		int redcode = scanf( "%m[^a-z]", &string );
		if( redcode == 1 && &string != NULL ) free( string );

		if (scanf("%m[a-z]", &string) <= 0) {
	        printf("NO\n");
	        free(string);
	        return 0;
	    }

		int length = strlen(string);

	    int N_strings = count_strings(string, length);

	    char **index_string = (char **) calloc(N_strings + 1, sizeof(char *));
	    find_string_beginning(string, index_string, length);

	    for (int i = 0; i < N_strings; i++) {
	        if (index_string[i] != NULL)
	            if (strcmp(index_string[i], "bomb") == 0) {
	                printf("YES\n");
	                free(string);
	                free(index_string);
	                return 0;
	            }
	    }

	    printf("NO\n");
	    free(index_string);
	    free(string);
	    return 0;
	}
    char *string;
    if (scanf("%m[a-z A-Z 0-9 :;'\"/!@#$%^&*()-_+=№]", &string) <= 0) {
        printf("NO\n");
        free(string);
        return 0;
    }

    int length = strlen(string);

    int N_strings = count_strings(string, length);

    char **index_string = (char **) calloc(N_strings + 1, sizeof(char *));
    find_string_beginning(string, index_string, length);

    for (int i = 0; i < N_strings; i++) {
        if (index_string[i] != NULL)
            if (strcmp(index_string[i], "bomb") == 0) {
                printf("YES\n");
                free(string);
                free(index_string);
                return 0;
            }
    }

    printf("NO\n");
    free(index_string);
    free(string);
    return 0;
}
