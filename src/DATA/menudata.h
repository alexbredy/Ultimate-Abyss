#ifndef MENUDATA_H
#define MENUDATA_H
#include <String>

#include "SDL/SDL.h"
#include "../MENU/partymenu.h"

using namespace std;

class GameEngine; //On déclare la classe car on ne peut pas mettre un include de gameengine.h sinon déclaration cyclique

class MenuData
{
      public:

      void Init();

      PartyMenu& getPartyMenu();





      private:

      PartyMenu partyMenu;


/*
      MenuModule party;
      MenuModule item;
      MenuModule magic;
      MenuModule materia;
      MenuModule equip;
      MenuModule status;
      MenuModule change;
      MenuModule limit;
      MenuModule config;
      MenuModule book;
      MenuModule summon;
      MenuModule quit;

      MenuModule begin;
      MenuModule name;
      MenuModule save;
      MenuModule shop;


*/





};

#endif
