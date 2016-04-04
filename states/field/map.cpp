#include <stdio.h>

#include "SDL/SDL.h"
#include "map.h"
#include "DATA/imagesetup.h"

void Map::setId(int id)
{
    this->id=id;
}

void Map::setName(string name)
{
    this->name=name;
}

void Map::setSize(int width, int height)
{
    this->width=width;
    this->height=height;
}

void Map::setMainImage(string filename)
{
    this->mainImage=ChargementImageAlpha(filename);
}

void Map::setPhysicalDataImage(string filename)
{
    this->physicalDataImage=ChargementImageAlpha(filename);
}

int Map::getId()
{
    return id;
}

string Map::getName()
{
    return name;
}

int Map::getWidth()
{
    return width;
}

int Map::getHeight()
{
    return height;
}

SDL_Surface* Map::getMainImage()
{
    return mainImage;
}

SDL_Surface* Map::getPhysicalDataImage()
{
    return physicalDataImage;
}


