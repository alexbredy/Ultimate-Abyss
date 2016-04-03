#ifndef NPC_H
#define NPC_H

#include <SDL.h>
#include <String>
#include <vector>
using namespace std;

class NPC
{

      public:

      NPC(int id, int X, int Y, SDL_Surface *imageLocation);


      int getId();



      void addText(string message);



      protected:


      private:

      int id;
      int coordinateX;
      int coordinateY;

      SDL_Surface *sprite;

      vector<string*> messages;









};


#endif
