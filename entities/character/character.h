#ifndef CHARACTER_H
#define CHARACTER_H
#include <String>

#include "SDL/SDL.h"
#include "stats.h"
#include "sprite.h"
#include "weapon.h"
using namespace std;

class GameEngine; //On déclare la classe car on ne peut pas mettre un include de gameengine.h sinon déclaration cyclique

class Character
{
      public:



      void Init();
      int getId();
      string getName();
      void setFaceImage(string filename);
      SDL_Surface* getFaceImage();
      Stats& getStats();

      void setId(int id);
      void setName(string name);


      //Field methods

      Sprite& getFieldSprite();

      bool northDirection();
      bool southDirection();
      bool eastDirection();
      bool westDirection();

      void enableNorth();
      void enableSouth();
      void enableEast();
      void enableWest();

      void disableNorth();
      void disableSouth();
      void disableEast();
      void disableWest();

      void disableAll();
      bool checkAllDisabled();

      int getWalkSpeed();
      int getRunSpeed();

      int getXFinalVariation();
      int getYFinalVariation();

      void setXFinalVariation(int value);
      void setYFinalVariation(int value);
      void appendXFinalVariation(int value);
      void appendYFinalVariation(int value);

      int getXPreliminaryVariation();
      int getYPreliminaryVariation();


      void setXPreliminaryVariation(int value);
      void setYPreliminaryVariation(int value);
      void appendXPreliminaryVariation(int value);
      void appendYPreliminaryVariation(int value);


      SDL_Surface* getCurrentFieldImage();
      SDL_Surface* getWalkFieldImage();
      SDL_Surface* getRunFieldImage();
      SDL_Surface* getSpecialFieldImage();

      void setCurrentFieldImage(SDL_Surface *image);
      void setWalkFieldImage(string filename);
      void setRunFieldImage(string filename);
      void setSpecialFieldImage(string filename);
      //End of field methods




      private:

      int id;
      string name;
      SDL_Surface *faceImage;
      Stats stats;

      int attack;

      Weapon weapon;

      //Field information
      Sprite fieldSprite;

      bool north;
      bool south;
      bool east;
      bool west;

      int walkSpeed;
      int runSpeed;


      //Variables affectées par l'appui des touches. Celles-ci seront copiées dans les 2 suivantes (Final) pour le déplacement final
      int xPreliminaryVariation;
      int yPreliminaryVariation;

      int xFinalVariation;
      int yFinalVariation;

      SDL_Surface *currentFieldImage;
      SDL_Surface *walkFieldImage;
      SDL_Surface *runFieldImage;
      SDL_Surface *specialFieldImage;







};


#endif
