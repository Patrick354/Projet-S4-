#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "outilsdl.h"
#include "pixel_operations.h"
#include "verify.h"




double* buildmatrix(SDL_Surface *image,double *p)
{
  
    
  Uint8 r,g,b;
   //printf("pine ton oncle\n");;
  
  for(int x = 0; x < image->h;x++)
    {

      for (int y = 0; y < image->w;y++)
	{
          
	  Uint32 pixel = get_pixel(image,y,x);
       //printf("pine ton oncle\n");
	  
	  SDL_GetRGB(pixel,image->format,&r,&g,&b);
	  
	  if (r>254)
	    {
            
	      p[x*(image->w)+y] = 1;
	      
	    }
	  else
	    {
	      p[x*(image->w)+y] = 0;
	    }

	  
	}
  
    }
   
    
    return p;
    
}

char* verification (double *matrice,  SDL_Surface *image,double* p)
{
    char* res = "TEST";
   
    
    double *m = buildmatrix(image,p);
    

    if (m[190*458 + 180] == 0 && m[190*458+275] == 0)
    {
        res = "down";
    }
    if (m[270*458 + 198] == 0 && m[180*458+190] == 0)
    {
        res = "Right";
    }
    if (m[190*458 + 180] == 1 && m[190 * 458 +275] == 1)
    {
        res = "Up";
    }
    if (m[270*458 + 190] == 1 && m[180* 458 + 190] == 1)
    {
        res = "Left";
    }
    return res;
    
    
     

}

