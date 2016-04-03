
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "SDL/SDL.h"
#include "system.h"
#include "inventory.h"
#include <vector>
using namespace std;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int SCREEN_BPP = 32;

const int FRAMES_PER_SECOND = 60;

class GameState;

class GameEngine
{
public:



	void Init(const char* title, int width=SCREEN_WIDTH, int height=SCREEN_HEIGHT, int bpp=SCREEN_BPP, bool fullscreen=false);
	void Cleanup();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return m_running; }
	void Quit() { m_running = false; }

	int getFramesPerSecond();

    System& getSystem();

	SDL_Surface* screen;
	SDL_Event event;




private:

    int FRAMES_PER_SECOND;

    System system;

	vector<GameState*> states;

	bool m_running;
	bool m_fullscreen;
};

#endif
