#ifndef SOUNDDATA_H
#define SOUNDDATA_H
#include <String>

#include <FMOD/fmod.h>

using namespace std;

class GameEngine; //On d�clare la classe car on ne peut pas mettre un include de gameengine.h sinon d�claration cyclique

class SoundData
{
      public:

      void Init();

      FSOUND_SAMPLE* getCursorMove();
      FSOUND_SAMPLE* getCursorValidate();


      private:

      FSOUND_SAMPLE* cursorMove;
      FSOUND_SAMPLE* cursorValidate;







};

#endif
