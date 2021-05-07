#ifndef DOTS_H
#define DOTS_H
#include "constants.h"

int getpos(int (*vector)[size][2], int pos[]);

int make_dot(struct color canvas[size][size], int (*vector)[size][2] , struct color color1, struct color color2, int minrad, int maxrad, int pos[]);

void dot_up(struct color canvas[size][size], int (*vector)[size][2], struct color color1, struct color color2, int pos[]);

#endif
