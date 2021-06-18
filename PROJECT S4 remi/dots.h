#ifndef DOTS_H
#define DOTS_H
#include "constants.h"

int getpos(int size, struct marker(*vector)[size], int pos[]);

int make_dot(int size, struct color (*canvas)[size], struct marker (*vector)[size] , struct color color1, struct color color2, int minrad, int maxrad, int pos[]);

void dot_up(int size, int sqrtlen, struct color (*canvas)[size], struct marker (*vector)[size], struct color color1, struct color color2, int pos[]);

#endif
