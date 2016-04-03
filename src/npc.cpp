#include <stdio.h>

#include "SDL/SDL.h"
#include "npc.h"

NPC::NPC(int id, int X, int Y, SDL_Surface *imageLocation)
{
          this->id = id;
          this->coordinateX = X;
          this->coordinateY = Y;
          this->sprite = imageLocation;
}
