
#ifndef START_H
#define START_H

#include "SDL/SDL.h"
#include "gamestate.h"
using namespace std;

class Start : public GameState
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
	SDL_Surface* fondu;
	int alpha;
};

#endif
