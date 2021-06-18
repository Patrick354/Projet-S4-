#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constants.h"

//returns a random int in the [lower, upper] range
int randinrange(int lower, int upper)
{
        int res = (rand() % (upper - lower + 1)) + lower;
        return res;
}

int max(int x1, int x2)
{
	if(x1 > x2)
	{
		return x1;
	}
	return x2;
}

int min(int x1, int x2)
{
	if(x1 < x2)
        {
                return x1;
        }
        return x2;
}

// concatenates a list of same-sized matrices into a square matrix in a predefined array
void matconc (int size, int sqrtlen,  struct marker (*vector)[size][size], struct marker (*vectormap)[sqrtlen * size] )
{
	for (int j = 0; j < sqrtlen * sqrtlen; j++)
	{
		for (int k = 0; k < size; k++)
		{
			for (int i = 0; i < size; i++)
			{
				vectormap[(j/sqrtlen)*size + k][(j%sqrtlen) * size + i] = vector[j][k][i];
			}
		}
	}
}



