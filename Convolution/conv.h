// Main Header file 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1
// File Operations
int OpenFile(FILE **fp, char path, char mode);
int ReadHeader(FILE *fp, char *header, int *row, int *col, int *bytes);
void ReadImage(FILE *fp, int **arr, int row, int col);
void WriteImage(FILE *fp, char *path, char *mode, int **arr, char *header, int *row, int *col, int *byte);

// Convolution operations
int SF_Conv(unsigned char ***image_in, unsigned char ***image_out, unsigned char *header, int *Rows, int *Cols, int *Bytes, int *window);
unsigned char** Convolve(unsigned char** image, int ROWS, int COLS, unsigned char filter);


