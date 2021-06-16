#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "calcul.h"

void partition(char* mat[12][3],char* str2, int col, int* True, int* False)
{

	int start_true = 0;
	int start_false = 0;

	for(int i = 0; i < 12; i++)
	{
		
		if(strcmp(mat[i][col], str2) == 0)
		{
			True[start_true] = i;
			start_true += 1;
		}
		else
		{
			False[start_false] = i;
			start_false += 1;
		}
		
		
	}

}

float find_best_split(char* mat[12][3], char** label, char* values[2][2],int col, char* question)
{
	float best_gain = 0;
	float current_uncertainty = calc_impur(mat,label);
	float gain = 0;

	for(int i = 0; i < 2; i ++)
	{
		for(int j = 0; j < 2; j++)
		{
			int True[50];
			int False[50];

			partition(mat,values[i][j],i,True,False);

			int size_true = size(True,50);
			int size_false = size(False,50);

			if (size_true == 0 || size_false == 0)
			{
				continue;
			}

			gain = info_gain(current_uncertainty,label,True,False,mat);

			if(gain >= best_gain)
			{
				best_gain = gain;
				col = i;
				strcpy(question,values[i][j]);


			}
		
		}

	}
	return best_gain;

	

}
