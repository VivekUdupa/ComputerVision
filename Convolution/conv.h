// Main Header file 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1
// File Operations
void OpenFile(FILE **fpt, char *fname, char *mode);
void ReadHeader(FILE **fpt, char *fname, char *header, int *row, int *col, int *byte);
void ReadImage(FILE **fpt, unsigned char **arr, const int row, const int col);
void WriteImage(FILE *fpt, char *path, char *mode, int **arr, char *header, int *row, int *col, int *byte);

// Convolution operations
int SF_Conv(unsigned char ***image_in, unsigned char ***image_out, unsigned char *header, int *Rows, int *Cols, int *Bytes, int *window);
unsigned char** Convolve(unsigned char** image, int ROWS, int COLS, unsigned char filter);


