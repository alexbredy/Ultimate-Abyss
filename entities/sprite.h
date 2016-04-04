#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <String>
#include <vector>
using namespace std;

class Sprite
{
/*
 DIRECTIONS

                       7     1     5

                       3           4

                       6     2     8


 */

      public:

      void display(SDL_Surface* destination);

      int getXCoordinate();
      int getYCoordinate();
      SDL_Surface* getImage();
      int getDirection();
      string getTextDirection();
      int getFrame();
      SDL_Rect* getClipRect();
      int getClip8x8();

      bool isEnabled();

      void setImage(string filename);
      void setImage(SDL_Surface* image);
      void setClip8x8(int frameWidth, int frameHeight);

      void setCoordinates(int x, int y);
      void setXCoordinate(int x);
      void setYCoordinate(int y);

      void appendXCoordinate(int value);
      void appendYCoordinate(int value);

      void setDirection(int direction);
      void setDirection(string textDirection);

      void updateFrame();
      void setFrame(int frame);
      void setCurrentFramePeriod(int value);
      void setTotalFramePeriod(int value);

      void setEnabled(bool value);

      SDL_Rect& getPhysicalSprite();
      void updatePhysicalSprite();





      protected:


      private:

      int xCoordinate;
      int yCoordinate;

      SDL_Rect physicalSprite;

      SDL_Surface* image;
      SDL_Rect clipSprite[64];
      int direction;
      string textDirection;
      int frame;
      int currentFramePeriod;
      int totalFramePeriod;


      bool enabled;












};


#endif
