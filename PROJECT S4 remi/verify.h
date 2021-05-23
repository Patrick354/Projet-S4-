#ifndef VERIFY_H_
#define VERIFY_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "outilsdl.h"
#include "pixel_operations.h"

double* buildmatrix(SDL_Surface *image,double  *p);
char* verification (double *matrice,  SDL_Surface *image, double *p);


#endif