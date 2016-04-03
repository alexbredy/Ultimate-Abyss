#include <stdio.h>
#include <String>
#include <iostream>
#
#include <sstream>

#include "SDL/SDL.h"
#include "../gameengine.h"
/*OBLIGATOIRE!! la déclaration de la classe dans character.h ne nous permet pas de travailler
sur ladite classe d'où l'obligation d'include le fichier ici (et la déclaration cyclique n'existe plus étant donné que nous
sommes dans le .cpp*/
#include "menudata.h"
#include "tinyxml.h"
using namespace std;

void MenuData::Init()
{
    partyMenu.Init();
}

PartyMenu& MenuData::getPartyMenu()
{
    return partyMenu;
}
