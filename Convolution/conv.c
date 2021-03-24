/*======================================================================* 
*                                                                       *
*        This program is a C implementation of a 7x7 mean filter using  *
*        3 differnent methods and showing they yield the same result    *
*        Methods:                                                       *
*        (1) Seperable filters                                          *
*        (2) Seperable Filter with Sliding Window                       *
*        (3) 2D Convolution                                             *
*                                                                       *
*        Author: Vivek Koodli Udupa                                     *        
*        Class: Clemson Intro to Computer Vision by Adam Hoover         *    
*        Start Date: Jan 1 2021                                         *
*        End Date: TBD                                                  *
*                                                                       *        
========================================================================*/
#include "conv.h"
#include "allocate.h"

int main(int argc, char *argv[])
{
    
    // Declaration and Initialiation
    FILE 		    *fpt;
	unsigned char 	**image;
	char 		    header[80];
	int		        ROWS,COLS,BYTES;
	int		        i,j,b,k,l,img_px,temp;
	unsigned char 	filter[7][7];
	int 		    fr=7, fc=7;

	// Validating command line arguments 
/*	if(argc != 2)
	{
		printf("Invalid inputs \n Usage: ./[executable] [filename] ");
		exit(0);
	}
*/   
   // Open file in "read mode"
   // OpenFile(&fpt, argv[1], 'r');
    
    if(DEBUG){
        ROWS = 10;
        COLS = 10;
    }

    // Allocate Dynamic Memory for storing image values 
    arry_create(&image, &ROWS, &COLS);


    // DEBUG Mode to allocate values to 2d array and print it
    if(DEBUG)
    {
        for(i = 0; i < ROWS; i++)
            for(j = 0; j < COLS; j++)
                image[i][j] = ((i*COLS) + (j + 1));
        
        for(i = 0; i < ROWS; i++)
        {
            printf("\n");
            for(j = 0; j < COLS; j++)
                printf("%d \t",image[i][j]);
        }
        printf("\n");
    }

    return 0;
}


