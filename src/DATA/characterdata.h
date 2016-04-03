#ifndef CHARACTERDATA_H
#define CHARACTERDATA_H
#include <String>

#include "SDL/SDL.h"
#include "../character.h"

using namespace std;

class GameEngine; //On déclare la classe car on ne peut pas mettre un include de gameengine.h sinon déclaration cyclique

class CharacterData
{
      public:

      void Init();

      Character& getKholkir();
      Character& getZika();





      private:

      Character kholkir;
      Character *test;
      Character zika;







};

#endif
