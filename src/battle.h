#ifndef BATTLE_H
#define BATTLE_H

#include <SDL.h>
#include "gamestate.h"

class Battle: public GameState
{

      public:

             //METTRE NOUVELLE IMAGE CLASS (GUI)
             //METTRE NOUVELLE INTELLIGENCE ARTIFICIELLE CLASS
             //RELATION AVEC LA CLASSE GAME->SYSTEM
             //METTRE NOUVELLE CLASS SCENES (REFERENCE THIS)

             void Init(GameEngine* game);
	         void Cleanup();

	         void Pause();
	         void Resume();

	         void HandleEvents(GameEngine* game);
	         void Update(GameEngine* game);
	         void Draw(GameEngine* game);

      private:
              bool sceneOnOff;

}
;


#endif
