#ifndef OUTILSDL_H
#define OUTILSDL_H

#include <err.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "pixel_operations.h"

// SDL tools : 
void init_sdl();
SDL_Surface* load_image(char *path);
SDL_Surface* display_image(SDL_Surface *img);
void wait_for_keypressed();
void SDL_FreeSurface(SDL_Surface *surface);

// Matrix tools :
void sdl_to_matrice(SDL_Surface *image, int*p);
void copy_matrix(int *src, int *dst, size_t len);


#endif