#ifndef MAP_H
#define MAP_H

#include <SDL.h>
#include <String>
#include <vector>
#include "npc.h"
using namespace std;

/*Classes enregistrant toutes les données d'une map
lorsqu'on se trouve dans l'état de jeu Field*/

class Map
{

      public:

      void setId(int id);
      void setName(string name);
      void setSize(int width, int height);
      void setMainImage(string filename);
      void setPhysicalDataImage(string filename);

      int getId();
      string getName();
      int getWidth();
      int getHeight();
      SDL_Surface* getMainImage();
      SDL_Surface* getPhysicalDataImage();

      private:

      int id;
      string name;

      int width;
      int height;

      int defaultTransitionTime;

      vector<NPC*> npcs;

      SDL_Surface *mainImage;
      SDL_Surface *physicalDataImage;
      SDL_Surface *topLayerImage;
      SDL_Surface *weatherImage;





};


#endif
