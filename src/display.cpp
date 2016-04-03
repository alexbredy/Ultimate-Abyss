#include "display.h"

void displayImage(SDL_Surface* image, int x, int y)
{
    SDL_Rect coordinates;
    coordinates.x=x;
    coordinates.y=y;
    SDL_BlitSurface(image,NULL,SDL_GetVideoSurface(),&coordinates);


}
