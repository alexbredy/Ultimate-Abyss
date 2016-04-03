
#include <stdio.h>

#include "SDL/SDL.h"
#include "FMOD/fmod.h"
#include "gameengine.h"
#include "gamestate.h"



void GameEngine::Init(const char* title, int width, int height, int bpp, bool fullscreen)
{
	int flags = 0;

	// initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	//initialize FMOD
	FSOUND_Init(44100, 32, 0);

	// set the title bar text
	SDL_WM_SetCaption(title, title);

	if ( fullscreen ) {
		flags = SDL_FULLSCREEN;
	}

	// create the screen surface
	screen = SDL_SetVideoMode(width, height, bpp, SDL_HWSURFACE|SDL_DOUBLEBUF);

	m_fullscreen = fullscreen;
	m_running = true;

	FRAMES_PER_SECOND=60;

    //Initialisation du KERNEL du jeu
	system.Init();



}

void GameEngine::Cleanup()
{
	// cleanup the all states
	while ( !states.empty() )
	{
		states.back()->Cleanup();
		states.pop_back();
	}

	// switch back to windowed mode so other
	// programs won't get accidentally resized
	if ( m_fullscreen ) {
		screen = SDL_SetVideoMode(1280, 720, 0, 0);
	}


    //shutdown FMOD
	FSOUND_Close();
    // shutdown SDL
	SDL_Quit();
}

void GameEngine::ChangeState(GameState* state)
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// store and init the new state
	states.push_back(state); //on ajoute sur la pile du vecteur le state renvoyé par la fonction CXXXState::Instance() (par exemple m_Start)
	states.back()->Init(this);   //on initialise le state en question (Start par exemple)
}


//les 2 fonctions suivantes sont à utiliser dans le cas de l'appel du menu et du retour sur la carte

void GameEngine::PushState(GameState* state)
{
	// pause current state
	if ( !states.empty() ) {
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init(this);
}

void GameEngine::PopState()
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// resume previous state
	if ( !states.empty() ) {
		states.back()->Resume();
	}
}


void GameEngine::HandleEvents()
{
	// let the state handle events
	states.back()->HandleEvents(this); //appelle la gestion des évènements du dernier objet state du vecteur states
}

void GameEngine::Update()
{
	// let the state update the game
	states.back()->Update(this);
}

void GameEngine::Draw()
{
	// let the state draw the screen
	states.back()->Draw(this);
}

int GameEngine::getFramesPerSecond()
{
    return FRAMES_PER_SECOND;
}

System& GameEngine::getSystem(){
    return system;}

