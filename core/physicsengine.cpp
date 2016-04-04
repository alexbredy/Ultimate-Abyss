#include "SDL/SDL.h"
#include "physicsengine.h"
#include <math.h>
#include <iostream>



void PhysicsEngine::Init()
{
    xCollision=0;
    yCollision=0;
    loopCount=0;
    area.x=0;
    area.y=0;
    area.w=0;
    area.h=0;
    red=0;
    green=0;
    blue=0;
    alpha=0;
}


///Vérifie si les coordonnées occupées par le nouveau SDL_Rect physique du joueur entrent en collision avec la physique de la carte.
///Renvoie true si il y a une collision et que le déplacement est nul, false sinon

bool PhysicsEngine::playerFieldDynamicCollision(Map* map, Character* player)
{
    SDL_LockSurface(map->getPhysicalDataImage());

    ///Initialisation des valeurs finales de déplacement
    player->setXFinalVariation(player->getXPreliminaryVariation());
    player->setYFinalVariation(player->getYPreliminaryVariation());


    ///Début de la vérification entre la collision du personnage avec l'écran (bordures de la map inclues)
    if((player->getFieldSprite().getPhysicalSprite().x==0 && player->getXPreliminaryVariation()<0)||(player->getFieldSprite().getPhysicalSprite().x+player->getFieldSprite().getPhysicalSprite().w == map->getWidth() && player->getXPreliminaryVariation()>0))
    {
        player->setXFinalVariation(0);


    }
    if((player->getFieldSprite().getPhysicalSprite().y==0 && player->getYPreliminaryVariation()<0)||(player->getFieldSprite().getPhysicalSprite().y+player->getFieldSprite().getPhysicalSprite().h == map->getHeight() && player->getYPreliminaryVariation()>0))
    {
        player->setYFinalVariation(0);

    }
    if(player->getXFinalVariation()==0&&player->getYFinalVariation()==0)
    {
        SDL_UnlockSurface(map->getPhysicalDataImage());
        return true;
    }
    ///Fin de la vérification de collision entre le personnage et l'écran

    xCollision=player->getXFinalVariation();
    yCollision=player->getYFinalVariation();

    ///Début de vérification du déplacement en diagonale
    if(xCollision!=0 && yCollision!=0)
    {
        int rapportYX=yCollision/xCollision;
        rapportYX = (int) fabs(rapportYX);

        if(xCollision<0)
        {
            area.x=player->getFieldSprite().getPhysicalSprite().x+xCollision;
        }
        else
        {
            area.x=player->getFieldSprite().getPhysicalSprite().x+player->getFieldSprite().getPhysicalSprite().w+xCollision;
        }
        if(yCollision<0)
        {
            area.y=player->getFieldSprite().getPhysicalSprite().y+yCollision;
        }
        else
        {
            area.y=player->getFieldSprite().getPhysicalSprite().y+player->getFieldSprite().getPhysicalSprite().h+yCollision;
        }

    }
    ///Fin du test de collision diagonal


    ///Début du test de collision horizontal
    else if(xCollision!=0)
    {
        area.y=player->getFieldSprite().getPhysicalSprite().y;
        area.w=(int) fabs(xCollision);
        area.h=player->getFieldSprite().getPhysicalSprite().h;

        if(xCollision<0)
        {
            area.x=player->getFieldSprite().getPhysicalSprite().x+xCollision; //xCollision est un chiffre négatif

            if(checkAreaFromLeft(map))
            {
                player->setXFinalVariation(0);
                SDL_UnlockSurface(map->getPhysicalDataImage());
                return true;
            }
            else
            {
                player->setXFinalVariation(xCollision);
                SDL_UnlockSurface(map->getPhysicalDataImage());
                return false;
            }
        }
        else
        {
            area.x=player->getFieldSprite().getPhysicalSprite().x+player->getFieldSprite().getPhysicalSprite().w+xCollision;
            if(checkAreaFromRight(map))
            {
                player->setXFinalVariation(0);
                SDL_UnlockSurface(map->getPhysicalDataImage());
                return true;
            }
            else
            {
                player->setXFinalVariation(xCollision);
                SDL_UnlockSurface(map->getPhysicalDataImage());
                return false;
            }
        }
    }
    ///Fin du test horizontal


    ///Début du test vertical
    else if(yCollision!=0)
    {
        area.x=player->getFieldSprite().getPhysicalSprite().x;
        area.w=player->getFieldSprite().getPhysicalSprite().w;
        area.h=(int) fabs(yCollision);

        if(yCollision<0)
        {
            area.y=player->getFieldSprite().getPhysicalSprite().y+yCollision;

            if(checkAreaFromTop(map))
            {
                player->setYFinalVariation(0);
                SDL_UnlockSurface(map->getPhysicalDataImage());
                return true;
            }
            else
            {
                player->setYFinalVariation(yCollision);
                SDL_UnlockSurface(map->getPhysicalDataImage());
                return false;
            }
        }
        else
        {
            area.y=player->getFieldSprite().getPhysicalSprite().y+player->getFieldSprite().getPhysicalSprite().h+yCollision;

            if(checkAreaFromBottom(map))
            {
                player->setYFinalVariation(0);
                SDL_UnlockSurface(map->getPhysicalDataImage());
                return true;
            }
            else
            {
                player->setYFinalVariation(yCollision);
                SDL_UnlockSurface(map->getPhysicalDataImage());
                return false;
            }
        }
    }


    SDL_UnlockSurface(map->getPhysicalDataImage());

    return false;





}

///Fin du test vertical


///Vérification de collision à l'endroit actuel d'un sprite, sans test de déplacement

bool PhysicsEngine::playerFieldStaticCollision(Map* map, Character* player)
{
    return true;
}











///Sous-fonctions


///Vérifie quelle partie de la nouvelle zone est accessible pour le sprite
///true si il y a collision et déplacement nul, false sinon

///Début du test de collision dans une nouvelle zone pour les quatres directions (diagonales non inclues)

bool PhysicsEngine::checkAreaFromLeft(Map* map)
{
    loopCount= 1;

    for(int x=0; x<=area.w; x++)
    {
        for(int y=0; y<=area.h; y++)
        {
            currentPixel=getPixel(map->getPhysicalDataImage(),area.x+x,area.y+y);
            SDL_GetRGBA(currentPixel, map->getPhysicalDataImage()->format, &red, &green, &blue, &alpha);
            if(red==255)
            {
                xCollision+=loopCount;
                if(xCollision<=0)
                {
                    return true;
                }
            }

        }
        loopCount++;
    }

    return false;
}

bool PhysicsEngine::checkAreaFromRight(Map* map)
{
    loopCount=1;

    for(int x=area.w; x>=0; x--)
    {
        for(int y=0; y<=area.h; y++)
        {
            currentPixel=getPixel(map->getPhysicalDataImage(),area.x+x,area.y+y);
            SDL_GetRGBA(currentPixel, map->getPhysicalDataImage()->format, &red, &green, &blue, &alpha);
            if(red==255)
            {
                xCollision-=loopCount;
                if(xCollision<=0)
                {
                    return true;
                }
            }

        }
        loopCount++;
    }

    return false;
}

bool PhysicsEngine::checkAreaFromTop(Map* map)
{
    loopCount=1;

    for(int y=0; y<=area.h; y++)
    {
        for(int x=0; x<=area.w; x++)
        {
            currentPixel=getPixel(map->getPhysicalDataImage(),area.x+x,area.y+y);
            SDL_GetRGBA(currentPixel, map->getPhysicalDataImage()->format, &red, &green, &blue, &alpha);
            if(red==255)
            {
                yCollision+=loopCount;
                if(xCollision<=0)
                {
                    return true;
                }
            }
        }

    }

    return false;
}

bool PhysicsEngine::checkAreaFromBottom(Map* map)
{
    loopCount=1;

    for(int y=area.h; y>=0; y--)
    {
        for(int x=0; x<=area.w; x++)
        {
            currentPixel=getPixel(map->getPhysicalDataImage(),area.x+x,area.y+y);
            SDL_GetRGBA(currentPixel, map->getPhysicalDataImage()->format, &red, &green, &blue, &alpha);
            if(red==255)
            {
                yCollision-=loopCount;
                if(xCollision<=0)
                {
                    return true;
                }
            }

        }
    }


    return false;
}


///Fin des fonctions de test de collision dans une zone pour les quatre directions


///Récupération d'un pixel d'une image (en général virtuelle)

Uint32 PhysicsEngine::getPixel(SDL_Surface* image, int x, int y)
{
    int bytesPerPixel = image->format->BytesPerPixel;
    Uint8 *pixel = (Uint8 *)image->pixels + y * image->pitch + x * bytesPerPixel;

    switch(bytesPerPixel)
    {
        case 1:
        {
            return *pixel;
            break;
        }
        case 2:
        {
            return *(Uint16 *)pixel;
            break;
        }
        case 3:
        {
            /*Suivant l'architecture de la machine*/
            if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
                return pixel[0] << 16 | pixel[1] << 8 | pixel[2];
            else
                return pixel[0] | pixel[1] << 8 | pixel[2] << 16;
            break;
        }
        case 4:
        {
            return *(Uint32 *)pixel;
            break;
        }
        /*Ne devrait pas arriver, mais évite les erreurs*/
        default:
        {
            return 0;
            break;
        }
    }


    return 0;
}
