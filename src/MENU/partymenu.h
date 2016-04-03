#ifndef PARTYMENU_H
#define PARTYMENU_H

#include <SDL.h>
#include <String>
#include <vector>
#include "../menumodule.h"
#include "../character.h"

class PartyMenu : public MenuModule
{

      public:

      void openAnimation();
      void closeAnimation();
      void Init();
      void upCommand();
      void downCommand();
      void rightCommand();
      void leftCommand();
      void display();
      void updateCursor();

      void displayMenuList();
      void displayCharacterData();
      void setCharacters(Character* char1, Character* char2, Character* char3);

      void setCharPaneXVariation(int value);
      void setCharPaneYVariation(int value);
      void setMenuPaneXVariation(int value);
      void setMenuPaneYVariation(int value);


      private:

      SDL_Surface* background;
      SDL_Surface* menuPane;
      SDL_Surface* characterPane;

      Character* character1;
      Character* character2;
      Character* character3;

      //animation variables

      int charPaneXVariation;
      int charPaneYVariation;
      int menuPaneXVariation;
      int menuPaneYVariation;


}
;


#endif
