#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "constants.h"
#include "tools.h"

// finds an available center position for a new dot with a random offset
int getpos(int size, struct marker (*vector)[size], int pos[], int rad)
{
	int res = 0;
	int countx;
	int county = randinrange(0, size/50);
	int flag = 1;
	while (flag && county < size)
	{
		countx = randinrange(0, size/50);
		while(flag && countx < size)
		{
			if ((vector[county][countx].space < rad))
			{
				countx += randinrange(1, size/50);
			}
			else
			{
				flag = 0;
				res = vector[county][countx].letter;
				
			}
		}
		// break the loop before adding another random number, makes for a better looking 
		//end  result
		if (!flag)
		{break;}
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
		pos[1] = county ;
		
	}
	return res;
	
}


//draws a dot of random radius around pos, return value answers question : does this function have to be called again?
int make_dot(int size, struct color (*canvas)[size], struct marker (*vector)[size], struct color color1, struct color color2, int minrad, int maxrad, int pos[])
{
	int rad = randinrange(minrad, maxrad);
	struct color pen;
	if (getpos(size, vector, pos, rad))
	{
		pen = color1;
		
	}
	else
	{
		pen = color2;
	}
	
	//randomized color variations
	pen.R = min(255, max(0, pen.R + randinrange(-55,55)));
	pen.G = min(255, max(0, pen.G + randinrange(-55,55)));
	pen.B = min(255, max(0, pen.B + randinrange(-55,55)));


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
		for( int y = max(0, (county - (rad + maxrad) )) ; y < min(size, county + rad + maxrad); y++)
		{
			for( int x = max(0, (countx - (rad + maxrad) )) ; x < min(size, countx + rad + maxrad); x++)
			{
				//compute square distance from current pos to center
				int sqx = (countx - x) * (countx - x);
				int sqy = (county - y) * (county - y);
				int sqdist = sqx + sqy;
				
				//compare sqdist to markable radius and drawable radius
				if (sqdist <= (rad + maxrad) * (rad + maxrad) )
				{
					if(vector[y][x].space > (int)(sqrt(sqdist) - rad))
					{
						vector[y][x].space = (int)(sqrt(sqdist) - rad);
					}
					if(sqdist < rad * rad)
					{
						canvas[y][x] = pen;
					}
				}
			}
		}

		return 0;
	}
}


//finds ideal sizes for dots and fills the canvas with dots in the predefined pattern.
void dot_up(int size, int sqrtlen, struct color (*canvas)[size], struct marker (*vector)[size], struct color color1, struct color color2, int pos[])
{
	int minrad = size/(50*sqrtlen);
	int maxrad = size/(20*sqrtlen);
	int done = 0;


	while( !done )
	{
		done = make_dot(size, canvas, vector, color1, color2, minrad, maxrad, pos);
	}
}













