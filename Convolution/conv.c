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
	unsigned char 	*image;
	char 		header[80];
	int		ROWS,COLS,BYTES;
	int		i,j,b;

	// Validating command line arguments 
	if(argc != 3)
	{
		printf("Missing inputs \n Usage: conv [filename] [amount] ");
		exit(0);
	}

	

}
