#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "tools.h"


void writeA(int size, struct marker (*vector)[size] )
{
	//diagonal bar from top middle to bottom left
	for (int k = size/10; k < 9*size/10; k++)
	{
		for (int i = 3*size/5 - k/2; i> 3*size/5 - k/2 - size/6; i--)
		{
			vector[k][i].letter = 0;
		}
	}
	//diagonal bar from top middle to bottom right
	for (int k = size/10; k < 9*size/10; k++)
	{
		for (int i = 2*size/5 + k/2; i <  2*size/5 + k/2 + size/6; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar in the middle
	for (int k = 11*size/20; k < 13*size/20; k++)
	{
		for (int i = size/4; i < 3*size/4; i++)
		{
			vector[k][i].letter = 0;
		}
	}

}

void writeB(int size, struct marker (*vector)[size])
{
	//vertical bar on the left
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = size/6; i < size/3; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//horizontal bar on the bottom
	for (int k = size - size/4; k < size - size/10; k++)
	{
		for (int i = size/4; i < 3*size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar on top
	for (int k = size/10; k < size/4 ; k++)
	{
		for(int i = size/4; i < 3*size/5 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar in the middle
	for (int k = 17*size/40; k < 23*size/40 ; k++)
	{
		for(int i = size/4; i < 3*size/5 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//vertical bar on the right
	for (int k = size/5; k < 17*size/40; k++)
	{
		for (int i = 3*size/5; i < 3*size/4; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//vertical bar on the right
	for (int k = 23*size/40; k < 4*size/5; k++)
	{
		for (int i = 3*size/5; i < 3*size/4; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	
}

void writeC(int size, struct marker (*vector)[size])
{
	//vertical bar on the left
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = size/5; i < 2 * size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//horizontal bar on the bottom
	for (int k = size - size/4; k < size - size/10; k++)
	{
		for (int i = size/4; i < size - size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar on top
	for (int k = size/10; k < size/4 ; k++)
	{
		for(int i = size/4; i < size - size/5 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	
}

void writeD(int size, struct marker (*vector)[size])
{
	//vertical bar on the left
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = size/6; i < size/3; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//horizontal bar on the bottom
	for (int k = size - size/4; k < size - size/10; k++)
	{
		for (int i = size/4; i < 3*size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar on top
	for (int k = size/10; k < size/4 ; k++)
	{
		for(int i = size/4; i < 3*size/5 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//vertical bar on the right
	for (int k = size/5; k < 4*size/5; k++)
	{
		for (int i = 3*size/5; i < 3*size/4; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	
}

void writeE(int size, struct marker (*vector)[size] )
{
	//horizontal bar in the middle
 	for (int k = 17*size/40; k < 23*size/40; k++)
        {
                for(int i = size/2 - size/10; i < size/2 + size/10 ; i++)
                {
                        vector[k][i].letter = 0;
                }
        }
	//horizontal bar on top
	for (int k = size/10; k < size/4; k++)
	{
		for (int i = size/4; i < size - size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar on the bottom
	for (int k = size - size/4; k < size - size/10; k++)
	{
		for (int i = size/4; i < size - size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	// vertical bar on the left
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = size/4; i < 2 * size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
}

void writeF(int size, struct marker (*vector)[size] )
{
	//horizontal bar in the middle
 	for (int k = 17*size/40; k < 23*size/40; k++)
        {
                for(int i = size/2 - size/10; i < size/2 + size/10 ; i++)
                {
                        vector[k][i].letter = 0;
                }
        }
	//horizontal bar on top
	for (int k = size/10; k < size/4; k++)
	{
		for (int i = size/4; i < size - size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	// vertical bar on the left
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = size/4; i < 2 * size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
}

void writeG(int size, struct marker (*vector)[size])
{
	//vertical bar on the left
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = size/5; i < 2 * size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//horizontal bar in the middle
	for (int k = 20*size/40; k < 26*size/40 ; k++)
	{
		for(int i = 6*size/10; i < 4*size/5 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//horizontal bar on the bottom
	for (int k = size - size/4; k < size - size/10; k++)
	{
		for (int i = size/4; i < size - size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar on top
	for (int k = size/10; k < size/4 ; k++)
	{
		for(int i = size/4; i < size - size/5 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//vertical bar on the right
	for (int k = 23*size/40; k < 4*size/5; k++)
	{
		for (int i = 2*size/3; i < 4*size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	
}

void writeH(int size, struct marker (*vector)[size])
{

	//vertical bar on the left
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = size/4; i < 2 * size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//vertical bar on the right
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = 3*size/5; i < 3*size/4; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//horizontal bar in the middle
	for (int k = 4*size/10; k < 6*size/10; k++)
	{
		for (int i = size/4; i < 3*size/4; i++)
		{
			vector[k][i].letter = 0;
		}
	}
}






void writeI(int size, struct marker (*vector)[size] )
{
	//vertical bar in the middle
 	for (int k = size/10; k < size - size/10; k++)
        {
                for(int i = size/2 - size/10; i < size/2 + size/10 ; i++)
                {
                        vector[k][i].letter = 0;
                }
        }
	//horizontal bar on top
	for (int k = size/10; k < size/4; k++)
	{
		for (int i = size/4; i < size - size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar on the bottom
	for (int k = size - size/4; k < size - size/10; k++)
	{
		for (int i = size/4; i < size - size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
}

void writeJ(int size, struct marker (*vector)[size] )
{
	//vertical bar in the middle
 	for (int k = size/10; k < size - size/10; k++)
        {
                for(int i = size/2 - size/10; i < size/2 + size/10 ; i++)
                {
                        vector[k][i].letter = 0;
                }
        }
	//horizontal bar on top
	for (int k = size/10; k < size/4; k++)
	{
		for (int i = size/5; i < size - size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar on the bottom
	for (int k = size - size/4; k < size - size/10; k++)
	{
		for (int i = size/5; i < 6*size/10; i++)
		{
			vector[k][i].letter = 0;
		}
	}
}

void writeK(int size, struct marker (*vector)[size])
{

	// vertical bar on the left
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = size/4; i < 2 * size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//diagonal bar from center to top right
	for (int k = size/10; k < size/2; k++)
	{
		for (int i = size - k - size/6; i < size - k; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//diagonal bar from center to bottom right
	for (int k = size/2; k < 9*size/10; k++)
	{
		for (int i =  k - size/6; i <  k; i++)
		{
			vector[k][i].letter = 0;
		}
	}
}

void writeL(int size, struct marker (*vector)[size])
{
	// vertical bar on the left
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = size/4; i < 2 * size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar on the bottom
	for (int k = size - size/4; k < size - size/10; k++)
	{
		for (int i = size/4; i < size - size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
}

void writeM(int size, struct marker (*vector)[size] )
{
	//diagonal bar from center to top right, thicc
	for (int k = size/10; k < size/2; k++)
	{
		for (int i = size - k - size/10; i < size - k + size/10 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//diagonal bar from center to top left
	for (int k = size/10; k < size/2; k++)
	{
		for (int i = size/10 + k - 7*size/40; i < 3*size/10 + k - 7*size/40; i ++)
		{
			vector[k][i].letter = 0;
		}
	}

	//vertical bar on the left
	for (int k = size/10; k < 9*size/10; k++)
	{
		for (int i = size/10; i < 3*size/10; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//vertical bar on the right
	for (int k = size/10; k < 9*size/10; k++)
	{
		for (int i = 7*size/10; i < 9*size/10; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//little square in the middle
 	for (int k = 4*size/10; k < 6*size/10; k++)
        {
                for(int i = size/2 - size/10; i < size/2 + size/10 ; i++)
                {
                        vector[k][i].letter = 0;
                }
        }
	
}
	
void writeN(int size, struct marker (*vector)[size] )
{

	//diagonal bar from top left to bottom right
	for (int k = size/10; k < 8*size/10; k++)
	{
		for (int i = size/10 + k - 7*size/40; i < 4*size/10 + k - 7*size/40; i ++)
		{
			vector[k][i].letter = 0;
		}
	}

	//vertical bar on the left
	for (int k = size/10; k < 9*size/10; k++)
	{
		for (int i = size/10; i < 3*size/10; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//vertical bar on the right
	for (int k = size/10; k < 9*size/10; k++)
	{
		for (int i = 7*size/10; i < 9*size/10; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	
}

void writeO(int size, struct marker (*vector)[size])
{
	//vertical bar on the left
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = size/5; i < 2 * size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//vertical bar on the right
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = 3*size/5; i < 4*size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//horizontal bar on the bottom
	for (int k = size - size/4; k < size - size/10; k++)
	{
		for (int i = size/4; i < size - size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar on top
	for (int k = size/10; k < size/3 ; k++)
	{
		for(int i = size/4; i < size - size/5 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}
}

void writeP(int size, struct marker (*vector)[size])
{
	//vertical bar on the left
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = size/6; i < size/3; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//horizontal bar on top
	for (int k = size/10; k < size/4 ; k++)
	{
		for(int i = size/4; i < 3*size/5 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar in the middle
	for (int k = 17*size/40; k < 23*size/40 ; k++)
	{
		for(int i = size/4; i < 3*size/5 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//vertical bar on the right
	for (int k = size/5; k < 17*size/40; k++)
	{
		for (int i = 3*size/5; i < 3*size/4; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	
}

void writeQ(int size, struct marker (*vector)[size])
{
	//vertical bar on the left
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = size/5; i < 2 * size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//vertical bar on the right
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = 3*size/5; i < 4*size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//horizontal bar on the bottom
	for (int k = size - size/4; k < size - size/10; k++)
	{
		for (int i = size/4; i < size - size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar on top
	for (int k = size/10; k < size/3 ; k++)
	{
		for(int i = size/4; i < size - size/5 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//diagonal bar from center to bottom right
	for (int k = 3*size/4; k < size; k++)
	{
		for (int i =  k - size/6; i <  k + size/10; i++)
		{
			vector[k][i].letter = 0;
		}
	}
}

void writeR(int size, struct marker (*vector)[size])
{
	//vertical bar on the left
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = size/6; i < size/3; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//horizontal bar on top
	for (int k = size/10; k < size/4 ; k++)
	{
		for(int i = size/4; i < 3*size/5 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar in the middle
	for (int k = 17*size/40; k < 23*size/40 ; k++)
	{
		for(int i = size/4; i < 3*size/5 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//vertical bar on the right
	for (int k = size/5; k < 17*size/40; k++)
	{
		for (int i = 3*size/5; i < 3*size/4; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//diagonal bar from center to bottom right
	for (int k = size/2; k < 17*size/20; k++)
	{
		for (int i =  k - size/6; i <  k + size/10; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	
}

void writeS(int size, struct marker (*vector)[size])
{
	//vertical bar on the left
	for (int k = 2*size/10; k < 23*size/40; k++)
	{
		for (int i = size/6; i < size/3; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//horizontal bar on the bottom
	for (int k = size - size/4; k < size - size/10; k++)
	{
		for (int i = size/6; i < 5*size/6; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar on top
	for (int k = size/10; k < size/4 ; k++)
	{
		for(int i = size/6; i < 5*size/6 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar in the middle
	for (int k = 17*size/40; k < 23*size/40 ; k++)
	{
		for(int i = size/3; i < 2*size/3; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//vertical bar on the right
	for (int k = 17*size/40; k < 4*size/5; k++)
	{
		for (int i = 2*size/3; i < 5*size/6; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	
}



void writeT(int size,  struct marker (*vector)[size] )
{
	//horizontal bar on top
	for (int k = size/10; k < size/3 ; k++)
	{
		for(int i = size/10; i < size - size/10 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	for (int k = size/10; k < size - size/10; k++)
	{
		for(int i = size/2 - size/10; i < size/2 + size/10 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}
}


void writeU(int size, struct marker (*vector)[size])
{
	//vertical bar on the left
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = size/5; i < 2 * size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//vertical bar on the right
	for (int k = size/10; k < size - size/10; k++)
	{
		for (int i = 3*size/5; i < 4*size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//horizontal bar on the bottom
	for (int k = size - size/4; k < size - size/10; k++)
	{
		for (int i = size/4; i < size - size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
}

void writeV(int size, struct marker (*vector)[size] )
{
	//diagonal bar from bottom to top right, thicc
	for (int k = size/10; k < 9*size/10; k++)
	{
		for (int i = size - k/2 - size/10; i < size - k/2 + size/10 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//diagonal bar from bottom to top left
	for (int k = size/10; k < 9*size/10; k++)
	{
		for (int i = size/10 + k/2 - 7*size/40; i < 3*size/10 + k/2 - 7*size/40; i ++)
		{
			vector[k][i].letter = 0;
		}
	}
	
}

void writeX(int size, struct marker (*vector)[size] )
{
	//diagonal bar from bottom left to top right, thicc
	for (int k = size/10; k < 9*size/10; k++)
	{
		for (int i = size - k - size/10; i < size - k + size/10 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//diagonal bar from bottom right to top left
	for (int k = size/10; k < 9*size/10; k++)
	{
		for (int i = size/10 + k - 7*size/40; i < 3*size/10 + k - 7*size/40; i ++)
		{
			vector[k][i].letter = 0;
		}
	}
	
}

void writeY(int size, struct marker (*vector)[size] )
{
	//diagonal bar from center to top right, thicc
	for (int k = size/10; k < size/2; k++)
	{
		for (int i = size - k - size/10; i < size - k + size/10 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}

	//diagonal bar from center to top left
	for (int k = size/10; k < size/2; k++)
	{
		for (int i = size/10 + k - 7*size/40; i < 3*size/10 + k - 7*size/40; i ++)
		{
			vector[k][i].letter = 0;
		}
	}

	//vertical bar from middle to bottom, offset to the left
	for (int k = size/2; k < 9*size/10; k++)
	{
		for (int i = 4*size/10; i < 6*size/10; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	
}

void writeZ(int size, struct marker (*vector)[size] )
{
	//diagonal bar from bottom left to top right, thicc
	for (int k = size/10; k < 9*size/10; k++)
	{
		for (int i = size - k - size/10; i < size - k + size/10 ; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar on top
	for (int k = size/10; k < size/4; k++)
	{
		for (int i = size/10; i < size - size/5; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	//horizontal bar on the bottom
	for (int k = size - size/4; k < size - size/10; k++)
	{
		for (int i = size/4; i < 9*size/10; i++)
		{
			vector[k][i].letter = 0;
		}
	}
	
}

//calls adequate function to write char c in matrix vector. all unintended characters will be replaced with a whitespace.
void writechar(int size, char c, struct marker (*vector)[size])
{
	if(c == 'a' || c == 'A')
	{
		writeA(size, vector);
	}

	if(c == 'b' || c == 'B')
	{
		writeB(size, vector);
	}


	if(c == 'c' || c == 'C')
	{
		writeC(size, vector);
	}
	
	if(c == 'd' || c == 'D')
	{
		writeD(size, vector);
	}

	if(c == 'e' || c == 'E')
	{
		writeE(size, vector);
	}


	if(c == 'f' || c == 'F')
	{
		writeF(size, vector);
	}
	
	if(c == 'g' || c == 'G')
	{
		writeG(size, vector);
	}

	if(c == 'h' || c == 'H')
	{
		writeH(size, vector);
	}

	if(c == 'i' || c == 'I')
	{
		writeI(size, vector);
	}

	if(c == 'j' || c == 'J')
	{
		writeJ(size, vector);
	}

	if(c == 'k' || c == 'K')
	{
		writeK(size, vector);
	}

	if(c == 'l' || c == 'L')
	{
		writeL(size, vector);
	}
	
	if(c == 'm' || c == 'M')
	{
		writeM(size, vector);
	}
	
	if(c == 'n' || c == 'N')
	{
		writeN(size, vector);
	}

	if(c == 'o' || c == 'O' || c == '0')
	{
		writeO(size, vector);
	}
	
	if(c == 'p' || c == 'P')
	{
		writeP(size, vector);
	}
	
	if(c == 'q' || c == 'Q')
	{
		writeQ(size, vector);
	}
	
	if(c == 'r' || c == 'R')
	{
		writeR(size, vector);
	}

	if(c == 's' || c == 'S')
	{
		writeS(size, vector);
	}

	if(c == 't' || c == 'T')
	{
		writeT(size, vector);
	}

	if(c == 'u' || c == 'U')
	{
		writeU(size, vector);
	}

	if(c == 'v' || c == 'V')
	{
		writeV(size, vector);
	}
	
	if(c == 'x' || c == 'X')
	{
		writeX(size, vector);
	}

	if(c == 'y' || c == 'Y')
	{
		writeY(size, vector);
	}
	
	if(c == 'z' || c == 'Z')
	{
		writeZ(size, vector);
	}
}
