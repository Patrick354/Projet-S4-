#ifndef TOOLS_H
#define TOOLS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FALSE 1 
#define TRUE 0 


int size(int* row, int size);


int nb_line(int pos);

void array_copy(char *original, char *copy, int w);

int* class_count(char** h, char* mat[12][3], int len);

int line_count(char* mat[12][3]);

void initialize_mat(char* test[12][3]);

void send_array_from_number(char* mat[12][3], int* array,char* res[12][3]);


#endif

