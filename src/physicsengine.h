#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include "SDL/SDL.h"
#include "character.h"
#include "map.h"

using namespace std;

class PhysicsEngine
{
    public:

    void Init();
    bool playerFieldDynamicCollision(Map* map, Character* player);
    bool playerFieldStaticCollision(Map* map, Character* player);
    bool checkAreaFromLeft(Map* map);
    bool checkAreaFromRight(Map* map);
    bool checkAreaFromTop(Map* map);
    bool checkAreaFromBottom(Map* map);

    Uint32 getPixel(SDL_Surface* image, int x, int y);

    private:

    int xCollision;
    int yCollision;
    int loopCount;
    Uint32 currentPixel;
    SDL_Rect area;
    Uint8 red;
    Uint8 green;
    Uint8 blue;
    Uint8 alpha;

};

#endif

