#include <stdio.h>
#include <String>
#include "SDL/SDL.h"

#include <iostream>

#include "sprite.h"
#include "DATA/imagesetup.h"



void Sprite::display(SDL_Surface* destination)
{
    SDL_Rect offset;

    offset.x=xCoordinate;
    offset.x-=128/2;
    offset.y=yCoordinate;
    offset.y-=128;
    //SDL_BlitSurface(image, &clipSprite[getClip8x8()], destination, &offset);
    SDL_BlitSurface(image, &clipSprite[getClip8x8()], destination, &offset);


}

bool Sprite::isEnabled()
{
    return enabled;
}

void Sprite::setEnabled(bool value)
{
    enabled=value;
}

int Sprite::getXCoordinate()
{
    return this->xCoordinate;
}

int Sprite::getYCoordinate()
{
    return this->yCoordinate;
}

SDL_Surface* Sprite::getImage()
{
    return this->image;
}

int Sprite::getDirection()
{
    return direction;
}

string Sprite::getTextDirection()
{
    return textDirection;
}

int Sprite::getFrame()
{
    return frame;
}

SDL_Rect* Sprite::getClipRect()
{
    return clipSprite;
}

SDL_Rect& Sprite::getPhysicalSprite()
{
    return physicalSprite;
}

void Sprite::updatePhysicalSprite()
{
    physicalSprite.x=xCoordinate-physicalSprite.w/2;
    physicalSprite.y=yCoordinate-physicalSprite.h;
}

int Sprite::getClip8x8()
{
    unsigned int clipValue = 0;

    switch (this->direction) ///8 directions, valeurs de 1 à 8. Si 0 valeur transformée à 2 (BAS)
    {
            case 1:
            {
                 switch (this->frame)
                 {
                        case 0:
                        {
                             clipValue = 0;
                             break;
                        }
                        case 1:
                        {
                             clipValue = 1;
                             break;
                        }
                        case 2:
                        {
                             clipValue = 2;
                             break;
                        }
                        case 3:
                        {
                             clipValue = 3;
                             break;
                        }
                        case 4:
                        {
                             clipValue = 4;
                             break;
                        }
                        case 5:
                        {
                             clipValue = 5;
                             break;
                        }
                        case 6:
                        {
                             clipValue = 6;
                             break;
                        }
                        case 7:
                        {
                             clipValue = 7;
                             break;
                        }
                 }
                 break;
            }

                 case 2:
                 {
                 switch (this->frame)
                 {
                        case 0:
                        {
                             clipValue = 8;
                             break;
                        }
                        case 1:
                        {
                             clipValue = 9;
                             break;
                        }
                        case 2:
                        {
                             clipValue = 10;
                             break;
                        }
                        case 3:
                        {
                             clipValue = 11;
                             break;
                        }
                        case 4:
                        {
                             clipValue = 12;
                             break;
                        }
                        case 5:
                        {
                             clipValue = 13;
                             break;
                        }
                        case 6:
                        {
                             clipValue = 14;
                             break;
                        }
                        case 7:
                        {
                             clipValue = 15;
                             break;
                        }
                 }
                 break;
                 }

                 case 3:
                 {
                 switch (this->frame)
                 {
                        case 0:
                        {
                             clipValue = 16;
                             break;
                        }
                        case 1:
                        {
                             clipValue = 17;
                             break;
                        }
                        case 2:
                        {
                             clipValue = 18;
                             break;
                        }
                        case 3:
                        {
                             clipValue = 19;
                             break;
                        }
                        case 4:
                        {
                             clipValue = 20;
                             break;
                        }
                        case 5:
                        {
                             clipValue = 21;
                             break;
                        }
                        case 6:
                        {
                             clipValue = 22;
                             break;
                        }
                        case 7:
                        {
                             clipValue = 23;
                             break;
                        }
                 }
                 break;
                 }

                 case 4:
                 {
                 switch (this->frame)
                 {
                        case 0:
                        {
                             clipValue = 24;
                             break;
                        }
                        case 1:
                        {
                             clipValue = 25;
                             break;
                        }
                        case 2:
                        {
                             clipValue = 26;
                             break;
                        }
                        case 3:
                        {
                             clipValue = 27;
                             break;
                        }
                        case 4:
                        {
                             clipValue = 28;
                             break;
                        }
                        case 5:
                        {
                             clipValue = 29;
                             break;
                        }
                        case 6:
                        {
                             clipValue = 30;
                             break;
                        }
                        case 7:
                        {
                             clipValue = 31;
                             break;
                        }
                 }
                 break;
                 }

                 case 5:
                 {
                 switch (this->frame)
                 {
                        case 0:
                        {
                             clipValue = 32;
                             break;
                        }
                        case 1:
                        {
                             clipValue = 33;
                             break;
                        }
                        case 2:
                        {
                             clipValue = 34;
                             break;
                        }
                        case 3:
                        {
                             clipValue = 35;
                             break;
                        }
                        case 4:
                        {
                             clipValue = 36;
                             break;
                        }
                        case 5:
                        {
                             clipValue = 37;
                             break;
                        }
                        case 6:
                        {
                             clipValue = 38;
                             break;
                        }
                        case 7:
                        {
                             clipValue = 39;
                             break;
                        }
                 }
                 break;
                 }

                 case 6:
                 {
                 switch (this->frame)
                 {
                        case 0:
                        {
                             clipValue = 40;
                             break;
                        }
                        case 1:
                        {
                             clipValue = 41;
                             break;
                        }
                        case 2:
                        {
                             clipValue = 42;
                             break;
                        }
                        case 3:
                        {
                             clipValue = 43;
                             break;
                        }
                        case 4:
                        {
                             clipValue = 44;
                             break;
                        }
                        case 5:
                        {
                             clipValue = 45;
                             break;
                        }
                        case 6:
                        {
                             clipValue = 46;
                             break;
                        }
                        case 7:
                        {
                             clipValue = 47;
                             break;
                        }
                 }
                 break;
                 }

                 case 7:
                 {
                 switch (this->frame)
                 {
                        case 0:
                        {
                             clipValue = 48;
                             break;
                        }
                        case 1:
                        {
                             clipValue = 49;
                             break;
                        }
                        case 2:
                        {
                             clipValue = 50;
                             break;
                        }
                        case 3:
                        {
                             clipValue = 51;
                             break;
                        }
                        case 4:
                        {
                             clipValue = 52;
                             break;
                        }
                        case 5:
                        {
                             clipValue = 53;
                             break;
                        }
                        case 6:
                        {
                             clipValue = 54;
                             break;
                        }
                        case 7:
                        {
                             clipValue = 55;
                             break;
                        }
                 }
                 break;
                 }

                 case 8:
                 {
                 switch (this->frame)
                 {
                        case 0:
                        {
                             clipValue = 56;
                             break;
                        }
                        case 1:
                        {
                             clipValue = 57;
                             break;
                        }
                        case 2:
                        {
                             clipValue = 58;
                             break;
                        }
                        case 3:
                        {
                             clipValue = 59;
                             break;
                        }
                        case 4:
                        {
                             clipValue = 60;
                             break;
                        }
                        case 5:
                        {
                             clipValue = 61;
                             break;
                        }
                        case 6:
                        {
                             clipValue = 62;
                             break;
                        }
                        case 7:
                        {
                             clipValue = 63;
                             break;
                        }
                 }
                 break;
                 }
    }


    return clipValue;
}


void Sprite::setImage(string filename)
{
    this->image=ChargementImageAlpha(filename);
}

void Sprite::setImage(SDL_Surface* image)
{
    this->image=image;
}

void Sprite::setCoordinates(int x, int y)
{
    this->xCoordinate=x;
    this->yCoordinate=y;
}

void Sprite::setXCoordinate(int x)
{
    this->xCoordinate=x;
}

void Sprite::setYCoordinate(int y)
{
    this->yCoordinate=y;
}

void Sprite::appendXCoordinate(int value)
{
    xCoordinate+=value;
}

void Sprite::appendYCoordinate(int value)
{
    yCoordinate+=value;
}

void Sprite::setDirection(int direction)
{
    this->direction=direction;

    switch(this->direction)
    {
        case 0:
        {
            this->direction=2;
            textDirection="south";
            break;
        }
        case 1:
        {
            textDirection="north";
            break;
        }
        case 2:
        {
            textDirection="south";
            break;
        }
        case 3:
        {
            textDirection="west";
            break;
        }
        case 4:
        {
            textDirection="east";
            break;
        }
        case 5:
        {
            textDirection="northEast";
            break;
        }
        case 6:
        {
            textDirection="southWest";
            break;
        }
        case 7:
        {
            textDirection="northWest";
            break;
        }
        case 8:
        {
            textDirection="southWest";
            break;
        }

    }
}

void Sprite::setDirection(string textDirection)
{
    this->textDirection=textDirection;

    if(this->textDirection=="north")
    {
        this->direction=1;
    }
    else if(this->textDirection=="south")
    {
        this->direction=2;
    }
    else if(this->textDirection=="west")
    {
        this->direction=3;
    }
    else if(this->textDirection=="east")
    {
        this->direction=4;
    }
    else if(this->textDirection=="northEast")
    {
        this->direction=5;
    }
    else if(this->textDirection=="southWest")
    {
        this->direction=6;
    }
    else if(this->textDirection=="northWest")
    {
        this->direction=7;
    }
    else if(this->textDirection=="southEast")
    {
        this->direction=8;
    }
    else
    {
        setDirection(0);
    }
}

void Sprite::updateFrame()
{
    if(frame==0)
    {
        frame++;
    }
    else
    {
        if(currentFramePeriod<totalFramePeriod)
        {
            currentFramePeriod++;
        }
        else if(currentFramePeriod>=totalFramePeriod)
        {
            currentFramePeriod=0;
            frame++;
            if(frame>6)//si la frame courante est supérieur au nombre total de frames en mouvement (6 en général) à modifier si exceptions
            {
                frame=1;
            }
        }
    }
}

void Sprite::setFrame(int frame)
{
    this->frame=frame;
}

void Sprite::setCurrentFramePeriod(int value)
{
    this->currentFramePeriod=value;
}

void Sprite::setTotalFramePeriod(int value)
{
    this->totalFramePeriod=value;
}



void Sprite::setClip8x8(int frameWidth, int frameHeight)
{
    //128 en règle générale width et height

    unsigned int i;
    for (i = 0 ; i < 64 ; i++) // transition noir
    {
        this->clipSprite[i].w = frameWidth;
        this->clipSprite[i].h = frameHeight;

    }

    for (i = 0 ; i < 8 ; i++)
    {
        this->clipSprite[i].x = 0 + i*frameWidth;
        this->clipSprite[i].y = 0;


    }

    for (i = 8 ; i < 16 ; i++)
    {
        ////On fait (i-8) pour rendre le calcul des coordonnées entre 0 et 7
        this->clipSprite[i].x = 0 + (i-8)*frameWidth;
        this->clipSprite[i].y = frameHeight;


    }

    for (i = 16 ; i < 24 ; i++)
    {
        ////On fait (i-8) pour rendre le calcul des coordonnées entre 0 et 7
        this->clipSprite[i].x = 0 + (i-16)*frameWidth;
        this->clipSprite[i].y = frameHeight*2;


    }

    for (i = 24 ; i < 32 ; i++)
    {
        ////On fait (i-8) pour rendre le calcul des coordonnées entre 0 et 7
        this->clipSprite[i].x = 0 + (i-24)*frameWidth;
        this->clipSprite[i].y = frameHeight*3;


    }

    for (i = 32 ; i < 40 ; i++)
    {
        ////On fait (i-8) pour rendre le calcul des coordonnées entre 0 et 7
        this->clipSprite[i].x = 0 + (i-32)*frameWidth;
        this->clipSprite[i].y = frameHeight*4;


    }

    for (i = 40 ; i < 48 ; i++)
    {
        ////On fait (i-8) pour rendre le calcul des coordonnées entre 0 et 7
        this->clipSprite[i].x = 0 + (i-40)*frameWidth;
        this->clipSprite[i].y = frameHeight*5;


    }

    for (i = 48 ; i < 56 ; i++)
    {
        ////On fait (i-8) pour rendre le calcul des coordonnées entre 0 et 7
        this->clipSprite[i].x = 0 + (i-48)*frameWidth;
        this->clipSprite[i].y = frameHeight*6;


    }

    for (i = 56 ; i < 64 ; i++)
    {
        ////On fait (i-8) pour rendre le calcul des coordonnées entre 0 et 7
        this->clipSprite[i].x = 0 + (i-56)*frameWidth;
        this->clipSprite[i].y = frameHeight*7;


    }

}



