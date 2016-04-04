
#include <stdio.h>
#include <String>
#include "SDL/SDL.h"
//#include "gameengine.h"
/*OBLIGATOIRE!! la déclaration de la classe dans character.h ne nous permet pas de travailler
sur ladite classe d'où l'obligation d'include le fichier ici (et la déclaration cyclique n'existe plus étant donné que nous
sommes dans le .cpp*/
#include "character.h"
#include "DATA/imagesetup.h"
using namespace std;

void Character::Init()
{
    this->name=name;
    this->faceImage=faceImage;
    this->walkSpeed=1;
    this->runSpeed=2;
    this->xPreliminaryVariation=0;
    this->yPreliminaryVariation=0;
    this->north=false;
    this->south=false;
    this->west=false;
    this->east=false;
    this->xFinalVariation=0;
	this->yFinalVariation=0;
	this->xPreliminaryVariation=0;
	this->yPreliminaryVariation=0;

}

int Character::getId()
{
    return this->id;
}

string Character::getName()
{
    return name;
}

void Character::setFaceImage(string filename)
{
    this->faceImage=ChargementImageAlpha(filename);
}

SDL_Surface* Character::getFaceImage()
{
    return faceImage;
}


Stats& Character::getStats()
{
    return stats;
}

///FIELD METHODS

Sprite& Character::getFieldSprite()
{
    return this->fieldSprite;
}

bool Character::northDirection()
{
    return north;
}

bool Character::southDirection()
{
    return south;
}

bool Character::eastDirection()
{
    return east;
}

bool Character::westDirection()
{
    return west;
}

void Character::enableNorth()
{north=1;}

void Character::enableSouth()
{south=1;}

void Character::enableEast()
{east=1;}

void Character::enableWest()
{west=1;}

void Character::disableNorth()
{north=0;}

void Character::disableSouth()
{south=0;}

void Character::disableEast()
{east=0;}

void Character::disableWest()
{west=0;}

void Character::disableAll()
{
    north=false;
    south=false;
    east=false;
    west=false;
}

bool Character::checkAllDisabled()
{
    return !north&&!south&&!east&&!west;
}

int Character::getWalkSpeed()
{
    return walkSpeed;
}

int Character::getRunSpeed()
{
    return runSpeed;
}

int Character::getXFinalVariation()
{
    return xFinalVariation;
}

int Character::getYFinalVariation()
{
    return yFinalVariation;
}

void Character::setXFinalVariation(int value)
{
    xFinalVariation=value;
}

void Character::setYFinalVariation(int value)
{
    yFinalVariation=value;
}

void Character::appendXFinalVariation(int value)
{
    xFinalVariation+=value;
}

void Character::appendYFinalVariation(int value)
{
    yFinalVariation+=value;
}

int Character::getXPreliminaryVariation()
{
    return xPreliminaryVariation;
}

int Character::getYPreliminaryVariation()
{
    return yPreliminaryVariation;
}

void Character::setXPreliminaryVariation(int value)
{
    xPreliminaryVariation=value;
}

void Character::setYPreliminaryVariation(int value)
{
    yPreliminaryVariation=value;
}

void Character::appendXPreliminaryVariation(int value)
{
    xPreliminaryVariation+=value;
}

void Character::appendYPreliminaryVariation(int value)
{
    yPreliminaryVariation+=value;
}

SDL_Surface* Character::getCurrentFieldImage()
{
    return currentFieldImage;
}

SDL_Surface* Character::getWalkFieldImage()
{
    return walkFieldImage;
}

SDL_Surface* Character::getRunFieldImage()
{
    return runFieldImage;
}

SDL_Surface* Character::getSpecialFieldImage()
{
    return specialFieldImage;
}

void Character::setId(int id)
{
    this->id = id;
}

void Character::setName(string name)
{
    this->name = name;
}

void Character::setCurrentFieldImage(SDL_Surface *image)
{
    this->currentFieldImage= image;
}

void Character::setWalkFieldImage(string filename)
{
    this->walkFieldImage=ChargementImageAlpha(filename);
}
