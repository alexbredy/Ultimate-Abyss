#ifndef MENU_H
#define MENU_H

#include <SDL.h>
#include <pthread.h>
#include "gamestate.h"
#include "menumodule.h"
#include <String>
#include <vector>
#include "character.h"

class Menu : public GameState
{

      public:

      void Init(GameEngine* game);
	  void Cleanup();

	  void Pause();
	  void Resume();

	  void HandleEvents(GameEngine* game);
	  void Update(GameEngine* game);
	  void Draw(GameEngine* game);

	  static void* callOpenAnimation(void* data);
      static void* callCloseAnimation(void* data);

	  bool checkAllDisabled();


      private:

      MenuModule* menu;

      bool upKey;
      bool downKey;
      bool rightKey;
      bool leftKey;

      //Thread data


      pthread_t animation;




}
;


#endif
