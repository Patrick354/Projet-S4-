#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

float calc_impur(char* mat[12][3],char** h) 
{
    int* counts = class_count(h,mat,2);
    float lbl;
    int lines = line_count(mat);
    float impurty = 1;
    for(int i = 0; i < 2; i++)
    {
        lbl = (float)counts[i]/lines; 
        impurty -= lbl*lbl;
    }
    return impurty;

}

float info_gain(float cu,char** h, int* True, int* False, char* mat[12][3])
{
    char* r_true[12][3];
    initialize_mat(r_true);
    send_array_from_number(mat,True,r_true);
    char* r_false[12][3];
    initialize_mat(r_false);
    send_array_from_number(mat,False,r_false);
    
    int size_true = size(True,50);
    int size_false = size(False,50);

    float div = (float)size_true/(size_true+size_false);


    return (float) cu-(div*(calc_impur(r_true,h)))-((1-div)*(calc_impur(r_false,h)));

}
