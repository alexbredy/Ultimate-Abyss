#include <stdio.h>
#include <iostream>

#include "SDL/SDL.h"
#include "SDL_image.h"
#include <FMOD/fmod.h>
#include "gameengine.h"
#include "gamestate.h"

#include "field.h"
#include "physicsengine.h"
#include "character.h"
#include "inventory.h"
#include "weapon.h"

#include <vector>
#include "DATA/imagesetup.h"

using namespace std;
void* blackTransition(void* pvide);

void Field::Init(GameEngine* game)
{
    map=game->getSystem().getCurrentMap();
    player=game->getSystem().getCurrentControlledChar();
    physics.Init();

    black = SDL_CreateRGBSurface(SDL_HWSURFACE, 1280, 720, 32, 0, 0, 0, 0);
    SDL_FillRect(black, NULL, SDL_MapRGB(SDL_GetVideoSurface()->format, 0, 0, 0));
    SDL_SetAlpha(black, SDL_SRCALPHA, 255);

    pthread_create(&transition,NULL,callOpenBlackTransition,this);



    //check for start events


}

void Field::Cleanup()
{
}

void Field::Pause()
{

}

void Field::Resume()
{

}

void Field::HandleEvents(GameEngine* game)
{

    while( SDL_PollEvent( &game->event ) )
    {
        if( game->event.type == SDL_KEYDOWN )
        {

            switch( game->event.key.keysym.sym )
            {

                case SDLK_UP:
                {
                    player->enableNorth();
                    player->appendYPreliminaryVariation(-player->getWalkSpeed());
                    break;
                }
                case SDLK_DOWN:
                {
                    player->enableSouth();
                    player->appendYPreliminaryVariation(player->getWalkSpeed());
                    break;
                }
                case SDLK_LEFT:
                {
                    player->enableWest();
                    player->appendXPreliminaryVariation(-player->getWalkSpeed());
                    break;
                }
                case SDLK_RIGHT:
                {
                    player->enableEast();
                    player->appendXPreliminaryVariation(player->getWalkSpeed());
                    break;
                }
                case SDLK_RETURN:
                {
                    //si il y a un évènement
                    //on annule le déplacement
                }
                case SDLK_ESCAPE:
                {
                    //open menu
                }

                default:{};


            }
        }

        if(game->event.type == SDL_KEYUP)
        {
            switch( game->event.key.keysym.sym )
            {

                case SDLK_UP:
                {
                    player->disableNorth();
                    player->appendYPreliminaryVariation(player->getWalkSpeed());
                    break;
                }
                case SDLK_DOWN:
                {
                    player->disableSouth();
                    player->appendYPreliminaryVariation(-player->getWalkSpeed());
                    break;
                }
                case SDLK_LEFT:
                {
                    player->disableWest();
                    player->appendXPreliminaryVariation(player->getWalkSpeed());
                    break;
                }
                case SDLK_RIGHT:
                {
                    player->disableEast();
                    player->appendXPreliminaryVariation(-player->getWalkSpeed());
                    break;
                }
                case SDLK_RETURN:
                {

                }
                default:{};


            }
        }



        if( game->event.type == SDL_QUIT )
        {
            //On quitte le programme
            game->Quit();
        }
    }


     /*if(!game->system.SceneActivated()) //Si une scène n'est PAS déclenchée on exécute les évènements suivants
     {

     }*/

}

void Field::Update(GameEngine* game)
{

    ///Code de la mise à jour du joueur sur la map

    //Si touche activation évènement (ENTREE) a été activée et un évènement a lieu, on annule le déplacement
    //variation = 0 et disableAll (pour les directions)

    //On vérifie si le joueur a été déplacé
    if((player->northDirection()==player->southDirection())&&(player->westDirection()==player->eastDirection()))
    {
            player->getFieldSprite().setFrame(0);
            player->setXFinalVariation(0);
            player->setYFinalVariation(0);

    }

    if(!player->checkAllDisabled())
    {
        //on déplace le joueur dans la direction choisie
        if(player->northDirection() && (player->westDirection()==player->eastDirection()) && !player->southDirection())
        {
            player->getFieldSprite().setDirection("north");
        }
        else if(player->southDirection() && (player->westDirection()==player->eastDirection()) && !player->northDirection())
        {
            player->getFieldSprite().setDirection("south");
        }
        else if(player->eastDirection() && !player->westDirection() && (player->northDirection()==player->southDirection()))
        {
            player->getFieldSprite().setDirection("east");
        }
        else if(player->westDirection() && !player->eastDirection() && (player->northDirection()==player->southDirection()))
        {
            player->getFieldSprite().setDirection("west");
        }
        else if(player->northDirection() && player->eastDirection() && !player->southDirection() && !player->westDirection())
        {
            player->getFieldSprite().setDirection("northEast");
        }
        else if(player->northDirection() && player->westDirection() && !player->southDirection() && !player->eastDirection())
        {
            player->getFieldSprite().setDirection("northWest");
        }
        else if(player->southDirection() && player->eastDirection() && !player->northDirection() && !player->westDirection())
        {
            player->getFieldSprite().setDirection("southEast");
        }
        else if(player->southDirection() && player->westDirection() && !player->northDirection() && !player->eastDirection())
        {
            player->getFieldSprite().setDirection("southWest");
        }

        if(!physics.playerFieldDynamicCollision(map, player))
        {
            player->getFieldSprite().updateFrame();
        }
        else
        {
            player->getFieldSprite().setFrame(0);
        }
        player->getFieldSprite().appendXCoordinate(player->getXFinalVariation());
        player->getFieldSprite().appendYCoordinate(player->getYFinalVariation());
        player->getFieldSprite().updatePhysicalSprite();

    }




}

void Field::Draw(GameEngine* game)
{
    vector<Sprite> spriteDisplayOrder;
    if(player->getFieldSprite().isEnabled())
    {
        spriteDisplayOrder.push_back(player->getFieldSprite());
    }
    Sprite test =spriteDisplayOrder.at(0);


    ///Alternative: Create vector/arraylist to send in a graphics object to manage image display

    //Display background

    SDL_BlitSurface(map->getMainImage(),NULL,SDL_GetVideoSurface(),NULL);
    SDL_BlitSurface(map->getPhysicalDataImage(),NULL,game->screen,NULL);

    test.display(game->screen);
    ///add field elements
    ///add player image
    ///for each NPC in vector add

    //Display top layers and sprites
    //Display weather images
    //Display Text
    //Display black/white transition

    SDL_BlitSurface(black,NULL,game->screen,NULL);

    SDL_UpdateRect(game->screen, 0, 0, 0, 0);



}

void Field::openBlackTransition()
{
    for(int i =255; i>=0;i-=2)
    {
        SDL_Delay(5);
        SDL_SetAlpha(black, SDL_SRCALPHA, i);
    }


}

void* Field::callOpenBlackTransition(void* data)
{
    Field* mirror;
    mirror = (Field*)data;
    mirror->openBlackTransition();
    return NULL;
}

