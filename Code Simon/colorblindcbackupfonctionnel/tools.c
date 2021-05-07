#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

