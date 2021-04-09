#ifndef ROTATIONS_H
#define ROTATIONS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "outilsdl.h"
#include "pixel_operations.h"

void rightrotation(SDL_Surface *image1,int *p);
void leftrotation(SDL_Surface *image1,int *p);
#endif
