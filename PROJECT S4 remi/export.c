#include <stdlib.h>
#include <stdio.h>
#include "constants.h"


void saveimg( int size, int sqrtlen, struct color (*canvas)[sqrtlen * size], char filename[], int lastrow)
{
	int finalsize = size * (sqrtlen - 1);
	if (!lastrow)
	{
		finalsize += size;
	}
	FILE* img;
	img = fopen(filename, "wb");
	fprintf(img, "P3\n%d %d\n255\n", sqrtlen * size, finalsize);
	for(int k = 0; k < finalsize; k++)
	{
		for(int i = 0; i < size * sqrtlen; i++)
		{
			fprintf(img, "%d %d %d\n", canvas[k][i].R, canvas[k][i].G, canvas[k][i].B);
		}
	}
	fclose(img);
}

