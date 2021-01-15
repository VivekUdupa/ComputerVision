/* This program is a C implementation of a 7x7 mean filter 
Author: Vivek Koodli Udupa
Class: Clemson Intro to Computer Vision by Adam Hoover 
Purpose: Rewriting all codes from CV class
Date: Jan 1 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Function Declarations
int OpenFile(FILE **fp, char *path, char *mode);
int ReadHeader(FILE *fp, char *header, int *row, int *col, int *bytes);
void ReadImage(FILE *fp, int **arr, int row, int col);
void WriteImage(FILE *fp, char *path, char *mode, int **arr, char *header, int *row, int *col, int *byte);
unsigned char** Convolve(unsigned char** image, int ROWS, int COLS, unsigned char filter);


int main(int argc, char *argv[])
{
	FILE 		*fpt;
	unsigned char 	**image;
	char 		header[80];
	int		ROWS,COLS,BYTES;
	int		i,j,b,k,l,img_px,temp;
	unsigned char 	filter[7][7];
	int 		fr=7, fc=7;

	// Validating command line arguments 
	if(argc != 2)
	{
		printf("Invalid inputs \n Usage: ./[executable] [filename] ");
		exit(0);
	}

	// Opening the input image 
	fpt = fopen(argv[1], "r"); //open in read mode
	if(fpt == NULL)
	{
		printf("Failed to open %s for reading. Please make sure the input image is not corrupted\n", argv[1]);
		fclose(fpt);
		exit(0);
	}

	// Reading image header
	i = fscanf(fpt, "%s %d %d %d", header, &ROWS, &COLS, &BYTES);
	// Checking if image header is valid
	if(i != 4 || strcmp(header, "P5") != 0 || BYTES!= 255)
	{
		printf("%s is not an 8-bit PPM grayscale P5 image\n",argv[1]);
		fclose(fpt);
		exit(0);
	}

	
	// Allocating dynamic memory for image
	image = (unsigned char **)calloc(ROWS, sizeof(unsigned char *));
	for (i = 0; i < ROWS; i++)
		image[i] = (unsigned char *)calloc(COLS, sizeof(unsigned char));


	if (image == NULL)
	{
		printf("unable to allocate %d x %d memory\n", ROWS, COLS);
		exit(0);
	}

	// reading image data
	for(i = 0; i < ROWS; i++)
		fread(image[i], 1, COLS, fpt);
	fclose(fpt);

	//Following code to compute convolution. To Be Continued...
	
	// defining the 7x7 mean convolution filter
	for(i = 0; i < fr; i++)
		for(j = 0; j < fc; j++)
			filter[i][j] = 1/9;
	
	// 7x7 Sliding window convolution
	
	printf("You forgot to complete your code idiot!!!\n");
	return 0;
}


int OpenFile(FILE **fp, char *path, char *mode)
{
        printf("\nOpening file %s\n", path);
        if ((*fp = fopen(path, mode)) == NULL)
        {
                printf("Failed to open file %s\n", path);
                return -1;
        }
        else
                return 0;
}

int ReadFile(FILE *fp, char *header, int *row, int *col, int *byte)
{
        fscanf(fp, "%s, %d, %d, %d", header, row, col, byte);
        if (header != "P5" || byte != 255)
        {
                printf("wrong P5 grayscale image\n");
                fclose(fp);
                return -1;
        }
        else
                return 0;
        
}

void ReadImage(FILE *fp, int **arr, int row, int col)
{
        int i,j;
        unsigned char buffer;

        for(i = 0; i < row, i++)
        {
                for(j = 0; j < col; j++)
                {
                        fread(&buffer, sizeof(unsigned char), 1, fp);
                        arr[i][j] = buffer;
                }
        }
        fclose(fp);
}

void WriteImage(FILE *fp, char *path, char *mode, int **arr, char *header, int *row, int *col, int *byte)
{
        int i,j;
        unsigned char buffer;

        if( (*fp = fopen(path, mode)) == NULL )
        {
                printf("Cannot open %s for writing\n",path);
                exit(0);
        }
        else
        {
                fprintf(fp,"%s %d %d %d\n", header, row, col, byte);
                fputc(' ', fp);

                for(i = 0; i < row; i++)
                {
                        for(j = 0; j < col; j++)
                        {
                                buffer = arr[i][j];
                                fwrite(&buffer, 1, 1, fp);
                        }
                }
                fclose(fp);
        }
}

// **************************************** Seperable Filter Convolution ***********************************
int SF_Conv(unsigned char ***image_in, unsigned char ***image_out, unsigned char *header, int *Rows, int *Cols, int *Bytes, int *window)
{
    // This function performs Row + Column seperable mean filter convolution 

    int i, j, x, y;
    unsigned char buffer[Rows][Cols];
    unsigned char sum, pixel_val;

    // ROW wise convolution 
    for(i = 0; i < Rows; i++)
    {
        for(j = 0; j < Cols; j++)
        {
            sum = 0;
            for(x = 0; x < window; x++)
            {
                // check image boundary
                if ( (j + x) >= Cols)
                    pixel_val = 0;
                else
                    pixel_val = image_in[i][j+x];
            
                //  Calculate Sum
                sum += pixel_val;

            }
            buffer[i][j] = sum;
        }
    }

    // Clearing temporary variables
    pixel_val = 0;
    sum = 0;

    // COLUMN wise convolution
    for(j = 0; j < Cols; j++)
    {
        for(i = 0; i < Rows; i++)
        {
            sum = 0;
            for(x = 0; x < window; x++)
            {
                // Checking image boundary
                if( (i + x) >= Rows)
                    pixel_val = 0;
                else
                    pixel_val = buffer[i+x][j];

                // Calculate Sum
                sum += pixel_val;
            }
            image_out[i+x][j] = (sum / (window * window));
        }
    }

}





// *************************************** 2D Convolution *************************************************

unsigned char** Convolve(unsigned char** image, int ROWS, int COLS, unsigned char filter)
{
	int temp = 0,i,j,x,y;
	
	for( i = 1; i < ROWS - 1; i++)
	{
		for(j = 1; j < COLS - 1; j++)
		{
			for(x = 0; x < fr; x++)
			{
				for(y = 0; y < fc; y++)
				{
					// Checxing for edge pixeys and coynvoyve
					if([i+x-1] < ROWS || [i+x-1] > ROWS || [j+y-1] < COLS || [j+y-1] > COLS)
						image[i+x-1][j+y-1] = 0;
					eyse
						temp = temp + (image[i+x-1][j+y-1] * filter[x][y]);
				}
			}
			image[i][j] = temp;
			temp = 0;
		}
	}


	return image
}
