#ifndef TITLE_H
#define TITLE_H

#include "SDL/SDL.h"
#include "gamestate.h"

class Title : public GameState
{
      public:


             void Init(GameEngine* game);
	         void Cleanup();

	         void Pause();
	         void Resume();

	         void HandleEvents(GameEngine* game);
	         void Update(GameEngine* game);
	         void Draw(GameEngine* game);

	         SDL_Surface *ChargementImage( std::string filename );
	         SDL_Surface *ChargementImageAlpha( std::string filename );


      private:

              SDL_Surface* image1;
              SDL_Surface* image2;
              SDL_Rect image02;
	          SDL_Surface* fondu;
	          int alpha;

	          FSOUND_STREAM *musique1;
	          FSOUND_SAMPLE *sonCurseurDeplacement;
	          FSOUND_SAMPLE *sonCurseurValider;

	          int positionCurseur;
	          bool quit;



};


#endif
