#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL.h>
#include <String>
#include "DATA/characterdata.h"
#include "DATA/mapdata.h"
#include "DATA/menudata.h"
#include "inventory.h"
#include "map.h"
using namespace std;

//classe KERNEL réglant toutes les données principales du jeu
//important pour la sauvegarde des données

class System
{

      public:

      void Init();
      MapData& getMapData();
      CharacterData& getCharacterData();
      MenuData& getMenuData();

      Map* getCurrentMap();
      Character* getCurrentControlledChar();
      MenuModule* getCurrentMenu();

      Character* getCharacter1();
      Character* getCharacter2();
      Character* getCharacter3();

      SDL_Surface* getCursorImage();
      SDL_Surface* getFontImage();
      SDL_Surface* getMenuFieldsImage();


      bool SceneActivated();

      private:

      //General information
      Character *character1;
      Character *character2;
      Character *character3;

      //Field information
      Character *currentControlledChar;
      Map *currentMap;

      //Menu information
      MenuModule *currentMenu;

      //Main inventory
      Inventory inventory;

      //Character DATA
      CharacterData characterData;
      //Map DATA
      MapData mapData;
      //Menu Data
      MenuData menuData;

      int mapID;
      bool scene;
      bool menuEnabled;

      //Images générales (pour ne les charger qu'une seule fois)

      SDL_Surface* cursor;
      SDL_Surface* font;
      SDL_Surface* menuFields;


};


#endif
