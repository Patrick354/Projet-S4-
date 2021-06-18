#ifndef TOOLS_H
#define TOOLS_H
#include "constants.h"
int randinrange(int lower, int upper);

int max(int x1, int x2);

int min(int x1, int x2);

void matconc(int size, int sqrtlen, struct marker (*vector)[size][size], struct marker (*vectormap)[size] );

#endif

