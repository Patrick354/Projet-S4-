#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constants.h"
#include "tools.h"

// finds an available center position for a new dot with a random offset
void getpos(int (*vector)[size][2], int pos[])
{
	int countx;
	int county = randinrange(0, size/50);
	int flag = 1;
	while (flag && county < size)
	{
		countx = randinrange(0, size/50);
		while(flag && countx < size)
		{
			if (!(vector[county][countx][0]))
			{
				countx += randinrange(1, size/50);
			}
			else
			{
				flag = 0;
			}
		}
		county += randinrange(1, size/50);
	}

	if (countx >= size && county >= size)
	{
		pos[0] = -1;
		pos[1] = -1;
	}
	else
	{
		pos[0] = countx;
		pos[1] = county;
	}
}


//draws a dot of random radius around pos, return value answers question : does this function have to be called again?
int make_dot(struct color canvas[size][size], int (*vector)[size][2], struct color color1, struct color color2, int minrad, int maxrad, int pos[])
{
	int rad = randinrange(minrad, maxrad);
	getpos(vector, pos);
	int countx = pos[0];
	int county = pos[1];
	
	// if not available position remains, send termination signal
	if (countx == -1 || county == -1)
	{
		return 1;
	}
	else
	{
		// define a portion of the matrix to iterate through around position. if the square reaches out of the 
		// matrix, it is cut to stay inside of bounds
		for( int y = max(0, (county - (rad + maxrad) )) ; y < min(size - 1, county + rad + maxrad); y++)
		{
			for( int x = max(0, (countx - (rad + maxrad) )) ; x < min(size-1, countx + rad + maxrad); x++)
			{
				//compute square distance from current pos to center
				int sqx = (countx - x) * (countx - x);
				int sqy = (county - y) * (county - y);
				int sqdist = sqx + sqy;
				
				//compare sqdist to markable radius and drawable radius
				if (sqdist <= (rad + maxrad) * (rad + maxrad) )
				{
					vector[y][x][0] = 0;
					if(sqdist <= rad * rad)
					{
						if (vector[y][x][1])
						{
							canvas[y][x] = color1;
						}
						else
						{
							canvas[y][x] = color2;
						}
					}
				}
			}
		}

		return 0;
	}
}


//finds ideal sizes for dots and fills the canvas with dots in the predefined pattern.
void dot_up(struct color canvas[size][size], int (*vector)[size][2], struct color color1, struct color color2, int pos[])
{
	int minrad = size/100;
	int maxrad = size/50;
	int done = 0;


	while( !done )
	{
		done = make_dot(canvas, vector, color1, color2, minrad, maxrad, pos);
	}
}













