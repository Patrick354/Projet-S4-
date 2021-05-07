#include <stdlib.h>
#include <stdio.h>
#include "constants.h"
#include "dots.h"
#include "export.h"


int main(int argc, char*argv[])
{
	printf("balise 1 \n");

	//color initialization
	struct color green;
	green.R = 0;
	green.G = 255;
	green.B = 0;
	
	struct color red;
	red.R = 255;
	red.G = 0;
	red.B = 0;

	struct color grey;
	grey.R = 200;
	grey.G = 200;
	grey.B = 200;

	printf("balise 2 \n");
	
	//arrays initialization
	
	int pos[2];
	
	printf("balise 3 \n");

  	struct color canvas[size][size];
	
	printf("balise 4 \n");	
	
  	//large 3D array implementation to avoid segmentation fault.
	int (*vector)[size][2] = malloc( size * size * 2 * sizeof(int) );
	
  	
	printf("balise 5 \n");
	
  	for (int k = 0; k < size; k++)
  	{
    		for (int i = 0; i < size; i++)
    		{
      			canvas[k][i] = grey;
      			vector[k][i][0] = 1;
      			vector[k][i][1] = 1;
    		}
  	}

	printf("balise 6 \n");

	// laying of dots
	dot_up(canvas, vector, red, green, pos);
	
	saveimg(canvas, "test.ppm");
	return 0;


  
}
