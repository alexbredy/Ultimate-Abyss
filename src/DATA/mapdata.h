#ifndef MAPDATA_H
#define MAPDATA_H
#include <String>

#include "SDL/SDL.h"
#include "../map.h"

using namespace std;

class GameEngine; //On d�clare la classe car on ne peut pas mettre un include de gameengine.h sinon d�claration cyclique

class MapData
{
      public:

      Map& getAncientWay();

      void Init();

      private:

      Map ancientWay;
      Map abandonnedStaircase;









};

#endif
