#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "outilsdl.h"
#include "pixel_operations.h"


void rightrotation(SDL_Surface *image1,int *p)
{
    //Matrice de lettre tournée
    Uint8 r,g,b;
    int w = image1->w;
    int h = image1->h;
  
    for (int x = 0; x < h; x++)
    {
        for (int y = 0; y < w; y++)
        
        {
            Uint32 pixel = get_pixel(image1,h-y-1,x);
            SDL_GetRGB(pixel,image1->format,&r,&g,&b);
            if (r >127)
            {
                p[x*h+y] = 1;
            }
            else
            {
                p[x*h+y] = 0;
                
            }
            
            
        }

    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (p[i*h+j] == 1)
            {
                Uint32 newpixel = SDL_MapRGB(image1->format,255,255,255);
                put_pixel(image1,i,j,newpixel);
            }
            else
            {
                Uint32 newpixel = SDL_MapRGB(image1->format,0,0,0);
                put_pixel(image1,i,j,newpixel);

            }
            


            
        }
        
    }
    

}

void leftrotation(SDL_Surface *image1,int *p)
{
    //Matrice de lettre tournée
    Uint8 r,g,b;
    int w = image1->w;
    int h = image1->h;
    printf("bonjour\n");
    for (int x = 0; x < h; x++)
    {
        for (int y = 0; y < w; y++)
        
        {
            Uint32 pixel = get_pixel(image1,y,w-x-1);
            SDL_GetRGB(pixel,image1->format,&r,&g,&b);
            if (r >127)
            {
                p[x*h+y] = 1;
            }
            else
            {
                p[x*h+y] = 0;
                
            }
            
            
        }

    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (p[i*h+j] == 1)
            {
                Uint32 newpixel = SDL_MapRGB(image1->format,255,255,255);
                put_pixel(image1,i,j,newpixel);
            }
            else
            {
                Uint32 newpixel = SDL_MapRGB(image1->format,0,0,0);
                put_pixel(image1,i,j,newpixel);

            }
            


            
        }
        
    }
    

    
    
}
