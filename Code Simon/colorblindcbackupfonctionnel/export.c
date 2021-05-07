#include <stdlib.h>
#include <stdio.h>
#include "constants.h"


void saveimg( struct color canvas[size][size], char filename[])
{
	FILE* img;
	img = fopen(filename, "wb");
	fprintf(img, "P3\n%d %d\n255\n",size, size);
	for(int k = 0; k < size; k++)
	{
		for(int i = 0; i < size; i++)
		{
			fprintf(img, "%d %d %d\n", canvas[k][i].R, canvas[k][i].G, canvas[k][i].B);
		}
	}
	fclose(img);
}

