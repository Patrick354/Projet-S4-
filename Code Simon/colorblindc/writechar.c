#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "tools.h"

void linetest( int (*vector)[size][2] )
{
	for (int k = size/10; k < size/3 ; k++)
	{
		for(int i = size/10; i < size - size/10 ; i++)
		{
			vector[k][i][1] = 0;
		}
	}

	for (int k = size/10; k < size - size/10; k++)
	{
		for(int i = size/2 - size/10; i < size/2 + size/10 ; i++)
		{
			vector[k][i][1] = 0;
		}
	}
}
