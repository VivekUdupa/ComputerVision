/* This program is a C implementation of a 7x7 mean filter 
Author: Vivek Koodli Udupa
Class: Clemson Intro to Computer Vision by Adam Hoover 
Purpose: Rewriting all codes from CV class
Date: Jan 1 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE 		*fpt;
	unsigned char 	**image;
	char 		header[80];
	int		ROWS,COLS,BYTES;
	int		i,j,b;
	unsigned char 	filter[7][7];
	int 		fr=7, fc=7;

	// Validating command line arguments 
	if(argc != 2)
	{
		printf("Invalid inputs \n Usage: ./[executable] [filename] ");
		exit(0);
	}

	// Opening the input image 
	fpt = fopen(argv[1]. "r"); //open in read mode
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
	image = (unsigned char **)calloc(ROWS, sizeof(unsinged char *));
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
	for( i = 1; i < ROWS - 1; i++)
	{
		for(j = 1; j < COLS - 1; j++)
		{
			for(k = 0; k < fr; k++)
			{
				for(l = 0; l < fc; l++)
				{
					
				}
			}
		}
	}

	
	printf("You forgot to complete your code idiot!!!\n");
	return 0;
}
