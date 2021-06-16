#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAX 12
#define FALSE 1
#define TRUE 0
#define NEW_QUESTION { "" , FALSE }


//P
int size(int* row, int size)
{
	int i = 1;
	while(i < size+1 && (row[i] != 0) && row[i] <= 12 && row[i]>0)  // || row[i] == 1))
	{
		i += 1; 
	}
	return i;
}



int nb_line(int pos)
{
    int res;
    res = pos/3;
    if(pos%3 != 0)
    {
        res++;
    }
    return res;
}





//J'ai crée une structure spliting car on ne peut pas retourner deux valeurs en C
//La structure contient un array true et un array false qui vont chacun contenir le numéro de la ligne ( comme ça on n'a pas à copier chaque élement )
//P

//P
void array_copy(char *original, char *copy, int w)
{
	for(int i = 0; i < w; i++)
	{
		copy[i] = original[i];
	}
}

//L
int* class_count(char** h, char* mat[12][3], int len)
{
    static int count_tab[6]; 
    int index = 0;
    int count = 0;
    for(int i = 0; i<len ;i++ )
    {
        for(int x =0;x<12;x++)
        {
            for(int y = 0;y < 3 ;y++)
            {
                if(mat[x][y] == h[i])
                {
                    count++;
                }
            }
        }
        count_tab[index] = count;
        index++;
        count = 0;
    }
    return count_tab;
}



int line_count(char* mat[12][3])
{
	int count = 0;
	for(int i = 0; i < 12 && strcmp(mat[i][0],"None") != 0 ; i ++)
	{
		count += 1;
	}
	return count;
}




void initialize_mat(char* test[12][3])
{
	for(int i = 0; i < 12; i++)
	{
		for(int y = 0; y < 3; y++)
		{
			test[i][y] = "None";
		}
	}
}



//L&P
void send_array_from_number(char* mat[12][3], int* array,char* res[12][3])
{
    int index = 0;
    int size1 = size(array,50);
    for(int i = 0; i < size1; i++)
    {
	    index = array[i];
        for(int y = 0; y<3;y++)
        {
            res[i][y] = mat[index][y];
        }
       
    }
}


