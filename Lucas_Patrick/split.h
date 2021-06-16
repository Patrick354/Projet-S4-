#ifndef SPLIT_H
#define SPLIT_H

void partition(char* mat[12][3],char* str2, int col, int* True, int* False);

float find_best_split(char* mat[12][3], char** label, char* values[2][2],int col, char* question);

#endif
