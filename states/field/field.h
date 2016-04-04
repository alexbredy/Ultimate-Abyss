#ifndef FIELD_H
#define FIELD_H

#include <SDL.h>
#include <pthread.h>
#include "gamestate.h"
#include "map.h"
#include "character.h"
#include "physicsengine.h"

class Field : public GameState
{

      public:


      void Init(GameEngine* game);
	  void Cleanup();

	  void Pause();
	  void Resume();

	  void HandleEvents(GameEngine* game);
	  void Update(GameEngine* game);
	  void Draw(GameEngine* game);

      //Thread methods


	  void openBlackTransition();
	  static void* callOpenBlackTransition(void* data);

      private:

      Map* map;
      Character* player;
      PhysicsEngine physics;
      bool sceneOnOff;
      SDL_Rect camera;
      SDL_Surface* black;

      //Thread data


      pthread_t transition;


}
;


#endif
