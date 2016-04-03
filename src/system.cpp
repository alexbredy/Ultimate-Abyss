#include <stdio.h>

#include <SDL.h>
#include "system.h"
#include "DATA/imagesetup.h"
#include <iostream>

using namespace std;

void System::Init()
{
    //Initialisation des personnages, des cartes, de l'inventaire, des menus.
    characterData.Init();
    mapData.Init();
    menuData.Init();

    inventory.Init();

    currentMap = &mapData.getAncientWay();
    currentControlledChar = &characterData.getKholkir();
    currentMenu = &menuData.getPartyMenu();

    cursor =ChargementImageAlpha("IMG/cursor.png");
    font = ChargementImageAlpha("IMG/font.png");
    menuFields = ChargementImageAlpha("IMG/menuFields.png");


    menuEnabled=true;

    character1=&characterData.getKholkir();
    character2=&characterData.getZika();
    character3=NULL;

}

MapData& System::getMapData()
{
    return mapData;
}

CharacterData& System::getCharacterData()
{
    return characterData;
}

MenuData& System::getMenuData()
{
    return menuData;
}

Map* System::getCurrentMap()
{
    return currentMap;
}

Character* System::getCurrentControlledChar()
{
    return currentControlledChar;
}

MenuModule* System::getCurrentMenu()
{
    return currentMenu;
}

bool System::SceneActivated()
{
     return scene;
}

Character* System::getCharacter1()
{

    return character1;
}

Character* System::getCharacter2()
{
    return character2;
}

Character* System::getCharacter3()
{
    return character3;
}

SDL_Surface* System::getCursorImage()
{
    return cursor;
}

SDL_Surface* System::getFontImage()
{
    return font;
}

SDL_Surface* System::getMenuFieldsImage()
{
    return menuFields;
}

