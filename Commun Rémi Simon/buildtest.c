#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "tools.h"
#include "constants.h"
#include "dots.h"
#include "export.h"
#include "writechar.h"


void buildtest(char* word, int size)
{

	int len = strlen(word);
	int sqrtlen = (int)sqrt(len);
	//if len is a perfect square, we use it sqrt, else we use the integer part of its sqrt + 1
	if (sqrtlen * sqrtlen != len)
	{
		sqrtlen += 1;
	}

	//color initialization
	struct color green;
	green.R = 110;
	green.G = 187;
	green.B = 80;
	
	struct color red;
	red.R = 190;
	red.G = 80;
	red.B = 50;

	struct color grey;
	grey.R = 250;
	grey.G = 250;
	grey.B = 250;

	//marker initialization
	struct marker mark;
	mark.space = size*sqrtlen;
	mark.letter = 1;
	
	//arrays initialization
	int pos[2];
  	//large 3D array implementation to avoid segmentation fault.
  	struct color (*canvas)[sqrtlen * size] = malloc( sqrtlen * sqrtlen * size * size * sizeof(struct color) );
	struct marker (*vectormap)[sqrtlen * size] = malloc( sqrtlen * sqrtlen * size * size * sizeof(struct marker) );
	struct marker (*vector)[size][size] = malloc( sqrtlen * sqrtlen * size * size * sizeof(struct marker) );

	//vector list initialization	
	for (int j = 0; j < sqrtlen * sqrtlen; j++)
	{
  		for (int k = 0; k < size; k++)
  		{
    			for (int i = 0; i < size; i++)
    			{
	      			vector[j][k][i] = mark;
    			}
  		}
	}
	//write each letter plus whitespaces to make a square
	int whitespaces = 0;
	for (int k = 0; k < sqrtlen * sqrtlen; k++)
	{
		if (k < len)
		{
			writechar(size, word[k], vector[k]);
			
		}
		else
		{
			whitespaces += 1;
			writechar(size, ' ', vector[k]);
		}
	}
	
	//uncomment to change default canvas color
	for (int k = 0; k < sqrtlen * size; k++)
	{
		for (int i = 0; i < sqrtlen * size; i++)
		{	
			canvas[k][i] = grey;
		}
	}
	//over

	//fill vectormap with complete vectors
	matconc(size, sqrtlen, vector, vectormap);

	// laying of dots
	dot_up(size*sqrtlen, sqrtlen, canvas, vectormap, green, red, pos);
	
	
	//saving of image as .ppm
	saveimg(size, sqrtlen, canvas, "test.ppm", whitespaces >= sqrtlen);


  
}
