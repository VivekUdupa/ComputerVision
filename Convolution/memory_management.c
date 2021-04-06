#include "memory_management.h"

void arry_create(unsigned char ***arry, int *rows, int *cols)
{
    if(DEBUG)
    {
        printf("debug mode on \t DEBUG = %d\n", DEBUG); 
        printf("Rows: %d, Cols: %d\n", *rows, *cols); 
    }

    // Allocate 2D array memory for ROWS x COLS
    *arry = (unsigned char **) calloc(*rows, sizeof(unsigned char*));
    for(int i = 0; i < *rows; i++)
        (* arry)[i] = (unsigned char *) calloc(*cols, sizeof(unsigned char));

}    

void arry_free(unsigned char ***arry, int rows)
{
    for(int i = 0; i < rows; i++)
        free( (*arry)[i]);
    free(*arry);
    printf("All memory freed \n");
}
